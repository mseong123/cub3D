# 42KL - cub3D

`cub3d` is a 42 school team project to render a 2D map into a 3D viewport using raycasting algorithm (like [Wolfenstein 3D](https://fr.wikipedia.org/wiki/Wolfenstein_3D) which was the first FPS ever). The project is implemented using the [MiniLibX library](https://github.com/42Paris/minilibx-linux).

![mandatory gif](https://github.com/mseong123/cub3D/blob/main/assets/mandatory.gif)

## Status

Validated 4/9/2023. Grade: 120%.

## Clone

Clone the repository including the MiniLibX (for macOS) library:

```shell
git clone https://github.com/mseong123/cub3D.git
```
## Compile and Run

The program is split into a mandatory part and a bonus part. The bonus part adds wall collision, a rotating minimap, a (Sonic!) sprite and the ability to rotate the view by moving the mouse.

To compile the mandatory part, `cd` into the cloned directory and:

```shell
make
```

To compile the bonus part, `cd` into the cloned directory and:

```shell
make bonus
```

To run the program:

For mandatory:
```shell
./cub3D ./maps/working1.cub
```
For bonus:
```shell
./cub3D_bonus ./maps/sonic_bonus.cub
```

