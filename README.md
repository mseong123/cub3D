# cub3D

`cub3d` is a 42 school team project to render a 2D map into a 3D viewport using raycasting algorithm (like [Wolfenstein 3D](https://fr.wikipedia.org/wiki/Wolfenstein_3D) which was the first FPS ever). The project is implemented using the [MiniLibX library](https://github.com/42Paris/minilibx-linux) and written in C language.

![mandatory gif](https://github.com/mseong123/cub3D/blob/main/assets/mandatory.gif)

![bonus gif](https://github.com/mseong123/cub3D/blob/main/assets/bonus.gif)

## Status

Validated 4/9/2023. Grade: 120%. Project duration: 3 weeks.

## Clone

Clone the repository including the MiniLibX (for macOS) library:

```
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
```
./cub3D ./maps/working1.cub
```
For bonus:
```
./cub3D_bonus ./maps/sonic_bonus.cub
```
## Controls

Controls for movement and rotation are:

- `W`: move forward
- `S`: move backward
- `A`: strafe left
- `D`: strafe right
- `left arrow`: rotate left
- `right arrow`: rotate right
- `mouse`: rotate by moving the mouse (bonus only)

## Useful Resources

Useful resources for this project are:

- Raycasting: [Lode's Computer Graphics Tutorial - Raycasting](https://lodev.org/cgtutor/raycasting.html)
- Raycasting: [Permadi's Raycasting tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
- MinilibX tutorial : [harm-smits.github.io](https://harm-smits.github.io/42docs/libs/minilibx.html)
- [Subject PDF](https://github.com/mseong123/cub3D/blob/main/en.subject.pdf)


---
Team Project by [mseong123](https://github.com/mseong123) and [lewislee42](https://github.com/lewislee42)
