# FDF
This project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.
FDF means 'fil de fer' in French which means ’wireframe model’.

## Introduction
The representation in 3D of a landscape is a critical aspect of modern mapping. For example, in these times of spatial exploration, to have a 3D representation of Mars is a prerequisite condition to its conquest.

As another example, comparing various 3D representations of an area of high tectonic activity will allow you to better understand these phenomena and their evolution, and as a result, be better prepared.

Today we modelize some 3D magnificent landscapes, imaginary or not.

## Objectives
To use the school graphical library: the MiniLibX! This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events.

This will be the opportunity to get familiar with the MiniLibX, to discover the basics of graphics programming, especially how to place points in space, join them and, most important, how to see the scene from a specific viewpoint.

## Mandatory part
This project is about creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments (edges).
Your project must comply with the following rules:
- You must use the MiniLibX. Either the version available on the school machines, or installing it using its sources.
- You have to turn in a Makefile which will compile your source files. It must not relink.
- Global variables are forbidden.

## Rendering
The program has to represent the model in isometric projection. The coordinates of the landscape are stored in a .fdf file passed as a parameter to
your program. (Some maps are provided in test_maps).Here is an example:

![map_example](https://github.com/Sumi111/FDF/blob/main/images/MAP_EXAMPLE.png)

Each number represents a point in space:
- The horizontal position corresponds to its axis.
- The vertical position corresponds to its ordinate.
- The value corresponds to its altitude.

Rendered landscape should be similar to:
![map_output](https://github.com/Sumi111/FDF/blob/main/images/Screen%20Shot%202022-10-18%20at%203.49.05%20PM.png)

## Graphic management
- Your program has to display the image in a window.
- The management of your window must remain smooth (changing to another window, minimizing, and so forth).
- Pressing ESC must close the window and quit the program in a clean way.
- Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
- The use of the images of the MiniLibX is mandatory.

### Shown some of the outputs are shown below:
![map_output1](https://github.com/Sumi111/FDF/blob/main/images/Screen%20Shot%202022-10-18%20at%203.52.32%20PM.png)
![map_output2](https://github.com/Sumi111/FDF/blob/main/images/Screen%20Shot%202022-10-18%20at%203.50.31%20PM.png)
![map_output3](https://github.com/Sumi111/FDF/blob/main/images/Screen%20Shot%202022-10-18%20at%203.53.51%20PM.png)
![map_output4](https://github.com/Sumi111/FDF/blob/main/images/Screen%20Shot%202022-10-18%20at%203.55.19%20PM.png)
![map_output5](https://github.com/Sumi111/FDF/blob/main/images/Screen%20Shot%202022-10-18%20at%203.55.00%20PM.png)
