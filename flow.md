### FdF roadmap — from zero to finished project


## 1. Project skeleton and map parsing

**Goal:** Read a `.fdf` file and store all heights in memory.

- **1.1 Create basic structure**
  - **Files:** `main.c`, `parse.c`, `fdf.h`, `Makefile`
  - **Structs:**  
    - `t_map { int width; int height; int **z; }`

- **1.2 Implement file reading**
  - Use `open`, `get_next_line`, `close`
  - Read each line into a `char *`

- **1.3 Determine map dimensions**
  - First pass:
    - Count lines → `height`
    - For the first line, `ft_split` by space → `width`
    - Check all lines have same number of tokens

- **1.4 Allocate the map**
  - `z = malloc(sizeof(int *) * height);`
  - For each row: `z[y] = malloc(sizeof(int) * width);`

- **1.5 Fill the map**
  - Second pass:
    - For each line, `ft_split` by space
    - Convert each token with `ft_atoi`
    - Store in `z[y][x]`

- **Checkpoint:**  
  - You can print the map in the terminal and see the correct grid of integers.
  - No MLX yet. If this works, you’ve *started FdF properly*.

---

## 2. Minimal MLX setup

**Goal:** Open a window and draw a single pixel.

- **2.1 Extend structs**

```c
typedef struct s_fdf {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
    t_map   map;
} t_fdf;
```

- **2.2 Initialize MLX**
  - `mlx = mlx_init();`
  - `win = mlx_new_window(mlx, WIDTH, HEIGHT, "FdF");`
  - `img = mlx_new_image(mlx, WIDTH, HEIGHT);`
  - `addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);`

- **2.3 Implement `put_pixel`**
  - Compute pixel address in `addr`
  - Write color (e.g. `0xFFFFFF`)

- **2.4 Test**
  - Draw a few hardcoded pixels
  - `mlx_put_image_to_window(mlx, win, img, 0, 0);`
  - `mlx_loop(mlx);`

- **Checkpoint:**  
  - You see a window with some pixels → MLX is under control.

---

## 3. Basic 2D grid drawing (no projection yet)

**Goal:** Draw a flat 2D grid using your map, ignoring `z`.

- **3.1 Define a point struct**

```c
typedef struct s_point {
    float x;
    float y;
    float z;
} t_point;
```

- **3.2 Map grid to screen**
  - For now: `screen_x = x * zoom + offset_x`
  - `screen_y = y * zoom + offset_y`
  - Ignore `z`

- **3.3 Implement Bresenham line**
  - `draw_line(t_fdf *fdf, t_point a, t_point b)`
  - Use integer Bresenham to call `put_pixel`

- **3.4 Connect neighbors**
  - For each `(x, y)`:
    - Draw line to `(x+1, y)` if in bounds
    - Draw line to `(x, y+1)` if in bounds

- **Checkpoint:**  
  - You see a flat rectangular grid of lines.  
  - Still no 3D, but your drawing pipeline works.

---

## 4. Add 3D projection (isometric)

**Goal:** Turn the flat grid into a 3D wireframe.

- **4.1 Start using `z`**
  - Set `point.z = map.z[y][x] * z_scale;`

- **4.2 Implement isometric projection**

```c
void project_iso(t_point *p)
{
    float prev_x = p->x;
    float prev_y = p->y;
    float angle = 0.523599; // 30 degrees

    p->x = (prev_x - prev_y) * cos(angle);
    p->y = (prev_x + prev_y) * sin(angle) - p->z;
}
```

- **4.3 Integrate into drawing**
  - For each point:
    - Start with grid coords `(x, y, z)`
    - Apply scaling (zoom, z_scale)
    - Apply projection
    - Apply offsets (center on screen)

- **Checkpoint:**  
  - Your grid now looks like a 3D terrain.  
  - This is the “FdF moment”.

---

## 5. Add interaction (controls)

**Goal:** Make the view adjustable.

- **5.1 Add fields to `t_fdf`**
  - `float zoom;`
  - `float z_scale;`
  - `int offset_x;`
  - `int offset_y;`
  - `float angle;` (for rotation if you want)

- **5.2 Key handling**
  - Use `mlx_key_hook` or `mlx_hook`
  - On key press:
    - Arrows → change `offset_x`, `offset_y`
    - `+` / `-` → change `zoom`
    - `W/S` → change `z_scale`
    - Optional: `A/D` → change `angle` and rotate

- **5.3 Redraw on input**
  - Clear image
  - Recompute all points
  - Redraw all lines
  - `mlx_put_image_to_window`

- **Checkpoint:**  
  - You can move, zoom, and adjust altitude.  
  - The project is functionally complete.

---

## 6. Polish, colors, and cleanup

**Goal:** Make it robust, pretty, and norm‑compliant.

- **6.1 Colors**
  - Start with a single color
  - Optionally: color based on `z` (low = dark, high = bright)

- **6.2 Error handling**
  - Invalid file → error message + clean exit
  - Inconsistent row length → error
  - Allocation failures → clean free + exit

- **6.3 Memory cleanup**
  - Free `map.z[y]` rows
  - Free `map.z`
  - Destroy image, window, display (if needed)
  - Free MLX pointers if required by your version

- **6.4 Norm & structure**
  - Split long functions
  - Keep files focused: `parse.c`, `draw.c`, `project.c`, `controls.c`, `bresenham.c`, `main.c`

---
