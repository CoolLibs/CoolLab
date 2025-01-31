#include "post_image_online.h"
#if COOLLAB_HAS_OPENSSL
#include <string>
#include "Cool/File/File.h"
#include "Cool/Log/Message.h"
#include "Cool/Log/ToUser.h"
#include "Cool/Path/Path.h"
#include "Cool/String/String.h"

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "cpp-httplib/httplib.h"

static auto escape(std::string str) -> std::string
{
    // First, escape the backslashes so that we don't later escape backslashes that are actually meant to escape something.
    Cool::String::replace_all_inplace(str, "\\", "\\\\");
    Cool::String::replace_all_inplace(str, "=", "\\=");
    Cool::String::replace_all_inplace(str, "|", "\\|");

    return str;
}

static auto process_link(std::string const& str) -> std::string
{
    if (str.empty() || str[0] != '@')
        return str;
    return fmt::format("https://www.instagram.com/{}", str.c_str() + 1); // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
}

#if LAB_ENABLE_TESTS
#include <doctest/doctest.h>
TEST_CASE("escape()")
{
    CHECK(escape("Hello") == "Hello");
    CHECK(escape("=") == "\\=");
    CHECK(escape("|") == "\\|");
    CHECK(escape("\\") == "\\\\");
    CHECK(escape("\\=") == "\\\\\\=");
    CHECK(escape("Hello\\=Hello") == "Hello\\\\\\=Hello");
}
TEST_CASE("process_link()")
{
    CHECK(process_link("Hello") == "Hello");
    CHECK(process_link("@julesfouchy") == "https://www.instagram.com/julesfouchy");
    CHECK(process_link("Hel@lo") == "Hel@lo");
    CHECK(process_link("@") == "https://www.instagram.com/");
    CHECK(process_link("@@") == "https://www.instagram.com/@");
}
#endif

namespace Lab {

void post_image_online(ArtworkInfo const& artwork_info, AuthorInfo const& author_info, LegalInfo const& legal_info, std::string const& image_png_data)
{
    if (image_png_data.empty())
    {
        Cool::Log::ToUser::warning("Export", "Failed to export image");
        return;
    }
    auto cli = httplib::SSLClient{"api.cloudinary.com"};

    // Create the multipart/form-data request
    auto const items = httplib::MultipartFormDataItems{
        // Add the image file as a binary data item
        httplib::MultipartFormData{
            .name         = "file",
            .content      = image_png_data,
            .filename     = "image.png",
            .content_type = "image/png",
        },
        httplib::MultipartFormData{
            .name         = "upload_preset",
            .content      = "gallery",
            .filename     = {},
            .content_type = {},
        },
        httplib::MultipartFormData{
            .name         = "tags",
            .content      = "gallery",
            .filename     = {},
            .content_type = {},
        },
        httplib::MultipartFormData{
            .name    = "context",
            .content = fmt::format(
                "title={}|description={}|author_name={}|author_link={}|email={}|agreed_to_have_it_shared_on_our_instagram={}",
                escape(artwork_info.title),
                escape(artwork_info.description),
                escape(author_info.name),
                escape(process_link(author_info.link)),
                escape(legal_info.email),
                escape(legal_info.has_agreed_to_share_on_instagram ? "true" : "false")
            ),
            .filename     = {},
            .content_type = {},
        },
    };

    // Send the POST request with the multipart/form-data
    auto const res = cli.Post("/v1_1/coollab/image/upload", items);
    if (res && res->status == 200)
    {
        Cool::Log::ToUser::info(
            "Gallery",
            "Posted successfully.\nYou can now see your image online at https://coollab-art.com/Gallery.",
            std::vector{
                Cool::ClipboardContent{
                    .title   = "link",
                    .content = "https://coollab-art.com/Gallery",
                },
            }
        );
    }
    else
    {
        if (!res)
            Cool::Log::ToUser::warning("Gallery", fmt::format("Failed to post.\n{}", httplib::to_string(res.error())));
        else
            Cool::Log::ToUser::warning("Gallery", fmt::format("Failed to post.\nStatus {}.\n{}: {}", res->status, res->reason, res->body));
    }
}

} // namespace Lab

#else
namespace Lab {
void post_image_online(ArtworkInfo const&, AuthorInfo const&, LegalInfo const&, std::string const&)
{
    assert(false && "Coollab was not built with the OpenSSL library because it was not found while compiling. You cannot use this function.");
}
} // namespace Lab
#endif