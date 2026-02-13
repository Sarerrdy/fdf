# ft_printf

> *Because `ft_putnbr()` and `ft_putstr()` aren’t enough.*

---

## 📖 Overview
`ft_printf` is a custom implementation of the standard C `printf` function.  
It is delivered as a static library (`libftprintf.a`) and can be linked into any C project.  
The goal is to reproduce the behavior of `printf` while learning about variadic functions, format parsing, and output formatting.

This project is part of the 42 curriculum and builds upon `libft`.

---

## ⚙️ Specifications

- **Program name:** `libftprintf.a`  
- **Turn-in files:** `Makefile`, headers (`*.h`, `*/*.h`), sources (`*.c`, `*/*.c`)  
- **Makefile rules:** `NAME`, `all`, `clean`, `fclean`, `re`  
- **External functions allowed:**  
  - `malloc`, `free`, `write`  
  - `va_start`, `va_arg`, `va_copy`, `va_end`  
- **Libft authorized:** Yes  
- **Library creation:** must use `ar` (not `libtool`)  
- **Output:** `libftprintf.a` at the root of the repository  

---

## 📌 Mandatory Part

### Prototype
```c
int ft_printf(const char *format, ...);
```
## 📜 Requirements
- Do not implement the original printf’s buffer management.
- Must handle the following conversions: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`.
- Implementation will be evaluated against the behavior of the original `printf`.
- Must use `ar` to create the library.
- The mandatory part must be perfect before bonus features are evaluated.

## 🔤 Conversions Implemented
- `%c` → prints a single character  
- `%s` → prints a string (null‑terminated)  
- `%p` → prints a pointer address in hexadecimal format, prefixed with `0x`  
- `%d` → prints a signed decimal (base 10) number  
- `%i` → prints a signed integer (base 10)  
- `%u` → prints an unsigned decimal (base 10) number  
- `%x` → prints a number in lowercase hexadecimal (base 16)  
- `%X` → prints a number in uppercase hexadecimal (base 16)  
- `%%` → prints a literal percent sign 
```

## 🛠️ Implementation Notes
```
- **Variadic arguments**: handled using `va_start`, `va_arg`, `va_end`.  
- **Parsing**: format string is scanned character by character; when `%` is found, the parser interprets flags, width, precision, and conversion type.  
- **Output**: written directly with `write()` (no internal buffering).  
- **Helper functions**:  
  - `ft_putnbr_abs_fd` → prints absolute value of an integer safely (handles `INT_MIN`).  
  - `ft_print_pad` → prints padding characters (`' '` or `'0'`).  
  - `ft_int_len` → computes digit length for width/precision calculations.  
- **Return value**: matches `printf` by returning the total number of characters printed.  
```
## 🎯 Bonus Part (Stage 1)
```
The first bonus implemented extends `ft_printf` with flag management:
- `-` → left alignment  
- `0` → zero padding  
- `.` → precision 
- `+` → plus 
- ` ` → space 
- `#` → alternate  

- minimum field width → applied to all conversions 
```

## 🛠️ Build
```bash
make
```

## 🛠️ Build
```c
make
```

🧹 Clean

```c
make clean
make fclean
```

## 🔄 Rebuild
```c
make re
```
```
##📜 License
This project is part of the 42 curriculum. Feel free to use and adapt for learning purposes.
