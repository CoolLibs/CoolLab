#include "NodeColor.h"
#include <variant>
#include "Cool/StrongTypes/Angle.h"
#include "Cool/StrongTypes/ColorAndAlpha.h"
#include "Cool/StrongTypes/Direction2D.h"
#include "PrimitiveType.h"

namespace Lab {

namespace NodeColor {
#include "generated_node_kind/node_colors_definition.inl"
} // namespace NodeColor

auto compute_function_color(FunctionSignature signature) -> Cool::Color
{
    {
#include "generated_node_kind/compute_function_color.inl"
    }
    // Default color if everything else failed:
    return NodeColor::miscellaneous();
}

auto compute_value_input_color(Cool::AnyInputDefinition const& input_def) -> Cool::Color
{
    if (std::holds_alternative<Cool::InputDefinition<Cool::Color>>(input_def)
        || std::holds_alternative<Cool::InputDefinition<Cool::ColorAndAlpha>>(input_def))
        return NodeColor::image();

    if (std::holds_alternative<Cool::InputDefinition<float>>(input_def)
        || std::holds_alternative<Cool::InputDefinition<int>>(input_def)
        || std::holds_alternative<Cool::InputDefinition<bool>>(input_def)
        || std::holds_alternative<Cool::InputDefinition<Cool::Hue>>(input_def)
        || std::holds_alternative<Cool::InputDefinition<Cool::Angle>>(input_def)
        || std::holds_alternative<Cool::InputDefinition<Cool::Direction2D>>(input_def))
        return NodeColor::greyscale();

    return NodeColor::miscellaneous();
}

auto compute_primitive_type_color(PrimitiveType type) -> Cool::Color
{
    if (is_color_type(type))
        return NodeColor::image();
    if (is_greyscale_type(type))
        return NodeColor::greyscale();

    switch (type)
    {
    case PrimitiveType::SignedDistance:
        return NodeColor::shape_2D();
    case PrimitiveType::Int:
    case PrimitiveType::Bool:
    case PrimitiveType::Hue:
    case PrimitiveType::Angle:
    case PrimitiveType::Direction2D:
        return NodeColor::greyscale();
    case PrimitiveType::UV:
        return NodeColor::modifier_2D();
    case PrimitiveType::Particle2D:
        return NodeColor::particle();
    default:
        return NodeColor::miscellaneous();
    }
}

auto node_kind_color(NodeKind kind) -> Cool::Color
{
    switch (kind)
    {
#include "generated_node_kind/node_kind_color.inl"
    }
    return NodeColor::miscellaneous();
}

auto imgui_node_kind_dropdown(const char* label, NodeKind* node_kind) -> bool
{
#include "generated_node_kind/imgui_node_kind_dropdown.inl"
}

} // namespace Lab