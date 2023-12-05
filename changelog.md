# Changelog

- [🐣beta-10 WIP](#beta-10-wip)
- [🐣beta-9](#beta-9)
- [🐣beta-8](#beta-8)
- [🐣beta-7](#beta-7)
- [🐣beta-6](#beta-6)
- [🐣beta-5](#beta-5)
- [🐣beta-4](#beta-4)
- [🐣beta-3](#beta-3)
- [🐣beta-2](#beta-2)
- [🐣beta-1](#beta-1)
- [🐣beta-0](#beta-0)

## 🐣beta-10 WIP

- ✨ Added Audio support! You can now import an audio file and play it while you generate your images. You can also use its volume and waveform to control your images.
- Added new nodes that you can use with waveform or spectrum: fill function, function to shape, add displacement
- 🐛 Fixed crash on Linux when opening a file explorer.

## 🐣beta-9

- ✨ Added MIDI support! You can now plug-in your MIDI keyboard, select your knob / slider by index, and use its value to control parameters of your nodes.
![image](https://github.com/CoolLibs/.github/assets/45451201/5a8d4950-57a0-4282-b549-6c66487448c3)
- ✨ Added the "Paint" blend mode.

| ![image](https://github.com/CoolLibs/.github/assets/45451201/6f57a43d-a422-4056-81e1-c691e4c85d84)  | ![image](https://github.com/CoolLibs/.github/assets/45451201/9b12b5bf-7f15-408b-93e9-552e0caa30ea)  |
|---|----|
| "Light" mode (what was already there in Coollab) | "Paint" mode (the new blend mode) |

- ✨ Added an Output window that you can project during live shows, while still having your View window on your screen to move the camera and the widgets. To open this window, go in the `Commands` menu and select `Open output window`.
![image](https://github.com/CoolLibs/.github/assets/45451201/3d6a14ec-69ca-44b1-81e0-1d4139b72544)
- ✨ Added "Open Backup" in case you accidentally refused to save your unsaved changes.
![image](https://github.com/CoolLibs/.github/assets/45451201/99287d7b-15a1-480b-98d4-0ca5c4777b86)
- 🐛 Fix: the transparency information was sometimes getting lost between nodes.
- 🐛 Fix: crash on Linux "Too many open files".
- ⚡️ Fix lag when editing the color gradient on a Color Ramp node.
- 👩‍💻 Replaced CIELAB color space with Oklab
- 👩‍💻 Replaced HSLuv color space with Okhsl

## 🐣beta-8

- ✨ Added project files: you can now save and open projects, allowing you to keep and share your work!
![image](https://github.com/CoolLibs/Lab/assets/45451201/00270343-3a45-4e92-93cc-729f0f674c1e)
- ✨ Coollab now has an installer! You don't need to download the raw executable anymore.
![image](https://github.com/CoolLibs/Lab/assets/45451201/a1042659-e003-4dcf-b917-79505c84c28e)
- ✨ Added the "Webcam" node!
![image](https://github.com/CoolLibs/Lab/assets/45451201/77fd1a74-2e7c-43eb-914a-90a711ce2cae)
- ✨ Added feedback loops! Check out the "Feedback" node.
![ezgif-5-a3c56b1c92](https://github.com/CoolLibs/Lab/assets/45451201/d6513535-6f53-4932-b260-20a54c032380)
- 🚚 Renamed "Space Transformation" category as "2D Modifier".
- 🐛 Fix: some nodes had the wrong color.
- 🐛 Fix: on Linux, for some window managers like i3, the context menu was not behaving properly. (Now by default we disable multi-viewport in you use one of these custom window managers, which fixes the issue but prevents you from dragging windows outside of the main Coollab window. This can be changed in the Settings menu.) 

## 🐣beta-7

- ✨ Only one camera (either 2D or 3D) can be active at the same time.
- ✨ Improved "Distortion Map" node.
- ✨ Added several "3D Shape from 2D" nodes.
- 🚚 Renamed "Boolean" categories as "Blend".
- 🚚 Renamed "Blend" nodes as "Mix".
- 🚚 Moved "Time" node to the "Input" category.
- 🐛 Fixed implicit conversion between numbers and angles: a number equal to 1 (white) now corresponds to a full turn (360 degrees).

## 🐣beta-6

- ✨ Added many Shape Booleans.
- ⚡️ Big performance improvements. If you experienced lag spikes before, they should be gone now!
- 🐛 Fix: some nodes had the wrong color.

## 🐣beta-5

- ✨ Added gizmos on the view that allow you to edit Point2Ds visually.
![Animation](https://github.com/CoolLibs/Lab/assets/45451201/b2a5ad91-e9bf-42d6-ab7a-c60e86e97c40)

- ✨ Added Bezier Curve node.
- ✨ Added a full 3D renderer node.
![Animation-min](https://github.com/CoolLibs/Lab/assets/45451201/5996fb72-258b-46ff-b87d-4195bda21215)

- ✨ Added tips that will show up from time to time and teach you about the subtleties and shortcuts of Coollab.
![image](https://github.com/CoolLibs/Lab/assets/45451201/112c4431-5e68-4617-9bcb-6591755aae05)

- ✨ Main input pins now have a different icon to distinguish them from the other pins.
![image](https://github.com/CoolLibs/Lab/assets/45451201/73191129-3c1a-4fb0-afa8-6651100399aa)

- 🐛 Fix: prevent panning the nodes while you are panning the camera.
- 🐛 Fixed the camera controls not working when the View window was on another screen.

## 🐣beta-4

- ✨ Improved quite a few existing nodes.
- ✨ Added new nodes. Check out our "Cloud" renderer for 3D Shapes!
- ✨ Node pins now have a color that reflects the kind of node that you can plug into them. (e.g. a pin that wants a Shape 3D will be yellow, just like the Shape 3D nodes.)
- ✨ Smarter automatic main node selection.
- ✨ All nodes can now be viewed by themselves, without requiring a "renderer" node (which used to be the case for Curves and 3D Shapes).
- ✨ Added buttons on the view to freeze / enable the 2D and 3D cameras.
- 🐛 Fixed some effects (Space Transformations) not being applied on top of 3D shapes.

## 🐣beta-3

- ✨ Added many 3D nodes.
- ✨ Added a Frame (Comment) node.
- ✨ In the "Export" menu, added a button to share your image online in [Coollab's Gallery](https://coollab-art.com/Gallery).
- 💄 Completely overhauled UI.
- 💄 New logo.
- 💄 Added Settings to change your color theme.
- 💄 Improved the Dark color theme.
- 💄 Added a Light color theme.
- 💄 Added an option to use the color theme set by your OS (Dark or Light).
- 💄 The View now uses a fixed aspect ratio by default (you can change this in the Preview menu).
- 💄 Improved Cameras window + added an option to lock one of the two cameras (2D or 3D) when using both 2D and 3D nodes.
- 🐛 Fixed the camera controls when using a fixed aspect ratio or fixed number of pixels.
- 🐛 Fix: the nodes categories were not sorted on MacOS.
- 🐛 Fix: could not place a node that had the same name as its category.
- 👩‍💻 Node files: now support the `#define` macro, just like any glsl file.
- 👩‍💻 Node files: added boolean and matrices types for INPUTs, main function and helper functions (they can be used anywhere like any other type now).

## 🐣beta-2

- Fix "Reserved built-in name" error on some GPUs
- Fix: properly display error messages when loading (parsing) a node failed (very useful for people creating new nodes)
- Started using icons all over the place (window titles, buttons, menus, ...)
- Many more nodes, and improvements to existing nodes

## 🐣beta-1

- Fix the huge visual glitches that appeared on some computers
- Image Node: fix the ghost error messages that it would create and that couldn't be removed
- Nodes:
  - New nodes
  - Fixes
  - Improvements
  - Added presets for some of them
  - Reorganized categories a bit
- All shapes are now nicely anti-aliased
- Added the debug options menu to the released executables
- Added debug option to get an info dump in order to help developers debug

## 🐣beta-0

- First version
