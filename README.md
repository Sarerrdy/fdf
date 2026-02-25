# FdF

*This project has been created as part of the 42 curriculum by eina.*

## Description

**FdF** is a graphical 3D wireframe renderer built using **MiniLibX**.  
It reads a map file containing altitude values and projects the 3D terrain into a 2D isometric view.

The project focuses on:

- 3D → 2D projection (isometric projection)
- pixel plotting and line drawing (Bresenham)
- event handling (keyboard input)
- image buffering and rendering
- working with MiniLibX (window, image, hooks)
- parsing and validating map files

You load a `.fdf` map, and the program displays a wireframe representation that you can move, zoom, rotate, and scale.

---

## Features

- Parse `.fdf` heightmaps into a 2D integer matrix  
- Compute min/max Z range for dynamic color scaling  
- Render a full wireframe grid using Bresenham’s algorithm  
- Isometric projection  
- Keyboard controls:
  - Move view (arrow keys)
  - Zoom in/out (`+` / `-`)
  - Increase/decrease Z scale (`W` / `S`)
  - Rotate (`A` / `D`)
  - Exit (`ESC`)
- Clean shutdown and full memory cleanup

---

## Instructions

### **Compilation**

```
make
```

This builds the `fdf` executable and compiles `libft` automatically.  
MiniLibX is expected to be installed system‑wide (e.g., `/usr/local/lib` and `/usr/local/include`).

### **Execution**

```
./fdf maps/42.fdf
```

The program opens a window and displays the rendered wireframe.

---

## Project Structure

```
fdf/
│
├── src/
│   ├── parse/          # map parsing and validation
│   ├── draw/           # drawing, line algorithm, pixel plotting
│   ├── project/        # projection math (isometric)
│   ├── utils/          # cleanup, error handling
│
├── get_next_line/      # GNL implementation
│
├── libft/              # custom libft library
│
├── includes/
│   └── fdf.h           # main header
│
├── Makefile
└── README.md
```

---

## Controls

| Key        | Action               |
|------------|----------------------|
| Arrows     | Move view            |
| `+` / `-`  | Zoom in/out          |
| `W` / `S`  | Increase/decrease Z  |
| `A` / `D`  | Rotate left/right    |
| `ESC`      | Exit program         |

---

## Resources

### **Useful references**

- MiniLibX documentation (42)
- Bresenham’s line algorithm
- Isometric projection math
- UNIX graphics programming basics
- X11 event handling

---

## Additional Notes

- This repository contains the **mandatory part** of FdF.  
- MLX is expected to be installed system‑wide to avoid Norminette scanning MLX sources.  
- The project is fully leak‑free and Norm‑compliant.