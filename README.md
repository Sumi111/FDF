# FDF
This project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.
FDF means 'fil de fer' in French which means ’wireframe model’.

## Introduction
The representation in 3D of a landscape is a critical aspect of modern mapping. For example, in these times of spatial exploration, to have a 3D representation of Mars is a prerequisite condition to its conquest.

As another example, comparing various 3D representations of an area of high tectonic activity will allow you to better understand these phenomena and their evolution, and as a result, be better prepared.

Today we modelize some 3D magnificent landscapes, imaginary or not.

## Objectives
To use the school graphical library: the MiniLibX! This library was developed internally and includes basic necessary tools to open a window, create images
and deal with keyboard and mouse events.

This will be the opportunity to get familiar with the MiniLibX, to discover the basics of graphics programming, especially how to place points in space, join them and, most important, how to see the scene from a specific viewpoint.

## Mandatory part
This project is about creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments (edges).
Your project must comply with the following rules:
- You must use the MiniLibX. Either the version available on the school machines, or installing it using its sources.
- You have to turn in a Makefile which will compile your source files. It must not relink.
- Global variables are forbidden.

### Rendering
Your program has to represent the model in isometric projection. The coordinates of the landscape are stored in a .fdf file passed as a parameter to
your program. (Some maps are provided in test_maps).
