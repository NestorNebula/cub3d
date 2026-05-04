_This project has been created as part of the 42 curriculum by nhoussie, cmonmire._

---

### Table of Contents

- [Description](#description)
- [Instructions](#instructions)
  - [Usage](#usage)
- [Resources](#resources)

---

## Description

This project is about creating a realistic 3D graphical representation of the inside of a maze from a first-person perspective, using the ray-casting principles.

The program renders different textures depending on the side faced by the wall (North, South, East, West) and allows the player to move inside the maze.

## Instructions

1. Build the program:

```sh
make
```

2. Execute the program:

```sh
./cub3D scene_file
```

For more details on the scene file argument, read the [usage section](#usage).

### Usage

The program must be called with exactly one argument:

```sh
./cub3d scene_file
```

The `scene_file` argument must be a file containing all the informations needed by the `cub3D` program to display the maze. This file must have a `.cub` extension.

Firstly, the file must contain informations about the program's textures/colors.

Four textures are expected (North, South, East and West). The lines with their informations must be in the following format:

```
XX ./path_to_the_texture
```

- `XX` being the first two letters of the texture (e.g. `NO` for North)
- `./path_to_the_texture` being the path to a file containing the texture to load

Two colors are expected, for the Floor and the Ceiling. The lines must be in the following format:

```
X 0,0,0
```

- `X` must be `F` or `C`, representing either the Floor or the Ceiling
- The three numbers must be separated by commas and each one must have a value between 0 and 255 inclusive, to represent a valid RGB value

The textures can be set in any order in the scene file, as long as all the textures are set before the map.

Secondly, after the textures, there must be a map representing the maze that will be used by the program.

That map must respect the given rules:

- It must be composed of only 6 possible characters:
  -- `0` for an empty space
  -- `1` for a wall
  -- `N`, `S`, `E`, `W` for the player's start position and spawning orientation (only one of theses four characters must appear in the map, as there cannot be multiple spawning positions)
- It must be surrounded by walls

Here is an example of a valid `scene_file` (considering that it has a `.cub` extension):

```
NO textures/north.xpm

SO textures/south.xpm

WE textures/west.xpm

EA textures/east.xpm

F 60,52,46
C 110,105,95

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

## Resources

[This article](https://lodev.org/cgtutor/raycasting.html) was used as a reference for the Raycasting part of the project.

This project was inspired by the [Wolfenstein 3D](https://en.wikipedia.org/wiki/Wolfenstein_3D) game.

AI was used for testing and as an help to better understand and implement the mathematics concepts.
