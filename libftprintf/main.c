
/* 
#include <stdio.h>
#include "ft_printf_bonus.h"

int main(void)
{
    int ret_std, ret_ft;
    void *ptr = (void *)0x1234abcd;
    char *str = "Hello, 42!";
    unsigned int u = 4294967295;
    int d = -2147483648;
    int i = 42;
    // int d = -42;
    char c = 'A';

    // %c
    ret_std = printf("STD: %%c = [%c]\n", c);
    ret_ft  = ft_printf("FT : %%c = [%c]\n", c);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // %s
    ret_std = printf("STD: %%s = [%s]\n", str);
    ret_ft  = ft_printf("FT : %%s = [%s]\n", str);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // %d
    ret_std = printf("STD: %%d = [%d]\n", d);
    ret_ft  = ft_printf("FT : %%d = [%d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);


    // %u
    ret_std = printf("STD: %%u = [%u]\n", u);
    ret_ft  = ft_printf("FT : %%u = [%u]\n", u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // %x
    ret_std = printf("STD: %%x = [%x]\n", u);
    ret_ft  = ft_printf("FT : %%x = [%x]\n", u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // %X
    ret_std = printf("STD: %%X = [%X]\n", u);
    ret_ft  = ft_printf("FT : %%X = [%X]\n", u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // %p
    ret_std = printf("STD: %%p = [%p]\n", ptr);
    ret_ft  = ft_printf("FT : %%p = [%p]\n", ptr);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // %i
    ret_std = printf("STD: %%i = [%i]\n", i);
    ret_ft  = ft_printf("FT : %%i = [%i]\n", i);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // %%
    ret_std = printf("STD: %% = [%%]\n");
    ret_ft  = ft_printf("FT : %% = [%%]\n");
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    return 0;
} */

/////////////BONUS/////////////////////////////

/* 
#include <stdio.h>
#include "ft_printf_bonus.h"

int main(void)
{
    int ret_std, ret_ft;
    void *ptr = (void *)0x1234abcd;
    char *str = "Hello, 42!";
    unsigned int u = 4294967295;
    int i = 42;
    int d = -42;
    char c = 'A';

    // %c with width and left flag
    ret_std = printf("STD: %%c = [%-5c]\n", c);
    ret_ft  = ft_printf("FT : %%c = [%-5c]\n", c);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // %s with width, precision, left flag
    ret_std = printf("STD: %%s = [%-10.5s]\n", str);
    ret_ft  = ft_printf("FT : %%s = [%-10.5s]\n", str);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // %d with zero flag, width, precision
    ret_std = printf("STD: %%d = [%8.0d]\n", d);
    ret_ft  = ft_printf("FT : %%d = [%8.0d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);


    // %d with zero flag, width, precision
    ret_std = printf("STD: %%d = [%8.2d]\n", d);
    ret_ft  = ft_printf("FT : %%d = [%8.2d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // %i with left flag and width
    ret_std = printf("STD: %%i = [%-6i]\n", i);
    ret_ft  = ft_printf("FT : %%i = [%-6i]\n", i);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // %u with zero flag and width
    ret_std = printf("STD: %%u = [%010u]\n", u);
    ret_ft  = ft_printf("FT : %%u = [%010u]\n", u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // %x with width and precision
    ret_std = printf("STD: %%x = [%12.0x]\n", u);
    ret_ft  = ft_printf("FT : %%x = [%12.0x]\n", u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // %X with left flag and width
    ret_std = printf("STD: %%X = [%-12.X]\n", u);
    ret_ft  = ft_printf("FT : %%X = [%-12.X]\n", u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // %p with width
    ret_std = printf("STD: %%p = [%20p]\n", ptr);
    ret_ft  = ft_printf("FT : %%p = [%20p]\n", ptr);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // %% with width and left flag
    ret_std = printf("STD: %% = [%-5s]\n", "%");
    ret_ft  = ft_printf("FT : %% = [%-5s]\n", "%");
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // %p with width
    ret_std = printf("STD: %%p = [%20p]\n", ptr);
    ret_ft  = ft_printf("FT : %%p = [%20p]\n", ptr);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // %p with width
    ret_std = printf(NULL);
    ret_ft  = ft_printf(NULL);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    return 0;
} */



/////////////////////  NULLS AND SOME SPECIAL CASES  ////////////////////////////////////


//mandantory
/* #include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    int ret_std, ret_ft;
    char *null_str = NULL;
    void *null_ptr = NULL;
    void *valid_ptr = (void *)0xdeadbeef;

    // Empty string
    ret_std = printf("STD: Empty string: [%s]\n", "");
    ret_ft  = ft_printf("FT : Empty string: [%s]\n", "");
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // NULL string
    ret_std = printf("STD: NULL string: [%s]\n", null_str);
    ret_ft  = ft_printf("FT : NULL string: [%s]\n", null_str);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // NULL pointer
    ret_std = printf("STD: NULL pointer: [%p]\n", null_ptr);
    ret_ft  = ft_printf("FT : NULL pointer: [%p]\n", null_ptr);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // Valid pointer
    ret_std = printf("STD: Valid pointer: [%p]\n", valid_ptr);
    ret_ft  = ft_printf("FT : Valid pointer: [%p]\n", valid_ptr);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // Zero values
    ret_std = printf("STD: Zero int: [%d], Zero unsigned: [%u], Zero hex: [%x]\n", 0, 0u, 0u);
    ret_ft  = ft_printf("FT : Zero int: [%d], Zero unsigned: [%u], Zero hex: [%x]\n", 0, 0u, 0u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // INT_MIN and INT_MAX
    ret_std = printf("STD: INT_MIN: [%d], INT_MAX: [%d]\n", INT_MIN, INT_MAX);
    ret_ft  = ft_printf("FT : INT_MIN: [%d], INT_MAX: [%d]\n", INT_MIN, INT_MAX);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // UINT_MAX
    ret_std = printf("STD: UINT_MAX: [%u], Hex: [%x], HEX: [%X]\n", UINT_MAX, UINT_MAX, UINT_MAX);
    ret_ft  = ft_printf("FT : UINT_MAX: [%u], Hex: [%x], HEX: [%X]\n", UINT_MAX, UINT_MAX, UINT_MAX);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // Mixed specifiers
    ret_std = printf("STD: Char: [%c], String: [%s], Int: [%d], Hex: [%x], Percent: [%%]\n", 'Z', "42", 42, 42);
    ret_ft  = ft_printf("FT : Char: [%c], String: [%s], Int: [%d], Hex: [%x], Percent: [%%]\n", 'Z', "42", 42, 42);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // Repeated specifiers
    ret_std = printf("STD: [%d][%d][%d]\n", 1, 2, 3);
    ret_ft  = ft_printf("FT : [%d][%d][%d]\n", 1, 2, 3);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // Empty format string
    ret_std = printf(" ");
    ret_ft  = ft_printf("");
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // Only percent signs
    ret_std = printf("STD: [%%%%]\n");
    ret_ft  = ft_printf("FT : [%%%%]\n");
    printf("\nReturn STD: %d | FT: %d\n\n", ret_std, ret_ft);

    return 0;
} */

/////////////// PRECISION - DECIMALS//////////////
/* 

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret_std, ret_ft;
    int d = 42;

    // --- Precision only ---
    ret_std = printf("STD: [%.0d]\n", d);
    ret_ft  = ft_printf("FT : [%.0d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%.2d]\n", d);
    ret_ft  = ft_printf("FT : [%.2d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Width + precision ---
    ret_std = printf("STD: [%8.0d]\n", d);
    ret_ft  = ft_printf("FT : [%8.0d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%8.2d]\n", d);
    ret_ft  = ft_printf("FT : [%8.2d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%8.5d]\n", d);
    ret_ft  = ft_printf("FT : [%8.5d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Zero flag + width + precision ---
    ret_std = printf("STD: [%08.0d]\n", d);
    ret_ft  = ft_printf("FT : [%08.0d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%08.2d]\n", d);
    ret_ft  = ft_printf("FT : [%08.2d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%08.5d]\n", d);
    ret_ft  = ft_printf("FT : [%08.5d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Left flag (-) + width + precision ---
    ret_std = printf("STD: [%-8.0d]\n", d);
    ret_ft  = ft_printf("FT : [%-8.0d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%-8.2d]\n", d);
    ret_ft  = ft_printf("FT : [%-8.2d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%-8.5d]\n", d);
    ret_ft  = ft_printf("FT : [%-8.5d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Negative value tests ---
    d = -42;
    ret_std = printf("STD: [%8.3d]\n", d);
    ret_ft  = ft_printf("FT : [%8.3d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%08.3d]\n", d);
    ret_ft  = ft_printf("FT : [%08.3d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%-8.3d]\n", d);
    ret_ft  = ft_printf("FT : [%-8.3d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    return (0);
} */

///////////////////////////// PRECISION - UNSIGNED INT /////////////
/* #include <stdio.h>
#include "ft_printf_bonus.h"

int main(void)
{
    unsigned int u = 4294967295; // UINT_MAX
    unsigned int small = 42;     // smaller value for zero-padding tests
    int ret_std, ret_ft;

    // --- Basic and width/zero flag tests with UINT_MAX ---
    ret_std = printf("STD: %%u = [%u]\n", u);
    ret_ft  = ft_printf("FT : %%u = [%u]\n", u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%u = [%10u]\n", u);
    ret_ft  = ft_printf("FT : %%u = [%10u]\n", u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%u = [%010u]\n", u);
    ret_ft  = ft_printf("FT : %%u = [%010u]\n", u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Precision tests with smaller value ---
    ret_std = printf("STD: %%u = [%.5u]\n", small);
    ret_ft  = ft_printf("FT : %%u = [%.5u]\n", small);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%u = [%.8u]\n", small);
    ret_ft  = ft_printf("FT : %%u = [%.8u]\n", small);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Width + precision ---
    ret_std = printf("STD: %%u = [%10.5u]\n", small);
    ret_ft  = ft_printf("FT : %%u = [%10.5u]\n", small);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Zero flag + precision (zero flag ignored) ---
    ret_std = printf("STD: %%u = [%010.5u]\n", small);
    ret_ft  = ft_printf("FT : %%u = [%010.5u]\n", small);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Left align + precision ---
    ret_std = printf("STD: %%u = [%-10.5u]\n", small);
    ret_ft  = ft_printf("FT : %%u = [%-10.5u]\n", small);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Edge case: value = 0 with precision = 0 ---
    ret_std = printf("STD: %%u = [%.0u]\n", 0u);
    ret_ft  = ft_printf("FT : %%u = [%.0u]\n", 0u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    return 0;
}

 */

 //////////////////////////// PRECISION - HEX /////////
/* 
 #include <stdio.h>
#include "ft_printf_bonus.h"

int main(void)
{
    unsigned int hx = 0x2a;        // small value (42 decimal)
    unsigned int big = 0xFFFFFFFF; // UINT_MAX
    int ret_std, ret_ft;

    // --- Basic printing ---
    ret_std = printf("STD: %%x = [%x]\n", hx);
    ret_ft  = ft_printf("FT : %%x = [%x]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%X = [%X]\n", hx);
    ret_ft  = ft_printf("FT : %%X = [%X]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Width only ---
    ret_std = printf("STD: %%10x = [%10x]\n", hx);
    ret_ft  = ft_printf("FT : %%10x = [%10x]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%10X = [%10X]\n", hx);
    ret_ft  = ft_printf("FT : %%10X = [%10X]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Zero flag + width ---
    ret_std = printf("STD: %%010x = [%010x]\n", hx);
    ret_ft  = ft_printf("FT : %%010x = [%010x]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%010X = [%010X]\n", hx);
    ret_ft  = ft_printf("FT : %%010X = [%010X]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Precision only ---
    ret_std = printf("STD: %%.5x = [%.5x]\n", hx);
    ret_ft  = ft_printf("FT : %%.5x = [%.5x]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%.5X = [%.5X]\n", hx);
    ret_ft  = ft_printf("FT : %%.5X = [%.5X]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Width + precision ---
    ret_std = printf("STD: %%10.5x = [%10.5x]\n", hx);
    ret_ft  = ft_printf("FT : %%10.5x = [%10.5x]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%10.5X = [%10.5X]\n", hx);
    ret_ft  = ft_printf("FT : %%10.5X = [%10.5X]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Zero flag + width + precision (zero flag ignored) ---
    ret_std = printf("STD: %%010.5x = [%010.5x]\n", hx);
    ret_ft  = ft_printf("FT : %%010.5x = [%010.5x]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%010.5X = [%010.5X]\n", hx);
    ret_ft  = ft_printf("FT : %%010.5X = [%010.5X]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Left align ---
    ret_std = printf("STD: %%-10x = [%-10x]\n", hx);
    ret_ft  = ft_printf("FT : %%-10x = [%-10x]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%-10X = [%-10X]\n", hx);
    ret_ft  = ft_printf("FT : %%-10X = [%-10X]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Left align + precision ---
    ret_std = printf("STD: %%-10.5x = [%-10.5x]\n", hx);
    ret_ft  = ft_printf("FT : %%-10.5x = [%-10.5x]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%-10.5X = [%-10.5X]\n", hx);
    ret_ft  = ft_printf("FT : %%-10.5X = [%-10.5X]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Edge case: value = 0 with precision = 0 (prints nothing) ---
    ret_std = printf("STD: %%.0x = [%.0x]\n", 0u);
    ret_ft  = ft_printf("FT : %%.0x = [%.0x]\n", 0u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%.0X = [%.0X]\n", 0u);
    ret_ft  = ft_printf("FT : %%.0X = [%.0X]\n", 0u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Large value (UINT_MAX) ---
    ret_std = printf("STD: %%X = [%X]\n", big);
    ret_ft  = ft_printf("FT : %%X = [%X]\n", big);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%x = [%x]\n", big);
    ret_ft  = ft_printf("FT : %%x = [%x]\n", big);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    return 0;
} */

//////////////////////////// PRECISION, PLUS AND SPACE /////////

#include <stdio.h>
#include "ft_printf_bonus.h"

int main(void)
{
    int ret_std, ret_ft;
    int d = -42;

    // --- Precision only ---
    ret_std = printf("STD: [%.0d]\n", d);
    ret_ft  = ft_printf("FT : [%.0d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%.4d]\n", 0);
    ret_ft  = ft_printf("FT : [%.4d]\n", 0);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Width + precision ---
    ret_std = printf("STD: [%8.0d]\n", d);
    ret_ft  = ft_printf("FT : [%8.0d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%8.2d]\n", d);
    ret_ft  = ft_printf("FT : [%8.2d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%8.5d]\n", d);
    ret_ft  = ft_printf("FT : [%8.5d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Zero flag + width + precision ---
    ret_std = printf("STD: [%08.0d]\n", d);
    ret_ft  = ft_printf("FT : [%08.0d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%08.2d]\n", d);
    ret_ft  = ft_printf("FT : [%08.2d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%08.5d]\n", d);
    ret_ft  = ft_printf("FT : [%08.5d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Left flag (-) + width + precision ---
    ret_std = printf("STD: [%-8.0d]\n", d);
    ret_ft  = ft_printf("FT : [%-8.0d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%-8.2d]\n", d);
    ret_ft  = ft_printf("FT : [%-8.2d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%-8.5d]\n", d);
    ret_ft  = ft_printf("FT : [%-8.5d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Negative value tests ---
    d = -42;
    ret_std = printf("STD: [%8.3d]\n", d);
    ret_ft  = ft_printf("FT : [%8.3d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%08.3d]\n", d);
    ret_ft  = ft_printf("FT : [%08.3d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [%-8.3d]\n", d);
    ret_ft  = ft_printf("FT : [%-8.3d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- PLUS flag tests ---
    d = 42;
    ret_std = printf("STD: [%+d]\n", d);
    ret_ft  = ft_printf("FT : [%+d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    d = -42;
    ret_std = printf("STD: [%+d]\n", d);
    ret_ft  = ft_printf("FT : [%+d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- SPACE flag tests ---
    d = 42;
    ret_std = printf("STD: [% d]\n", d);
    ret_ft  = ft_printf("FT : [% d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    d = -42;
    ret_std = printf("STD: [% d]\n", d);
    ret_ft  = ft_printf("FT : [% d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Width + PLUS/SPACE ---
    d = 42;
    ret_std = printf("STD: [%+8d]\n", d);
    ret_ft  = ft_printf("FT : [%+8d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

       d = 42;
    ret_std = printf("STD: [%+8.0d]\n", d);
    ret_ft  = ft_printf("FT : [%+8.0d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

       d = 42;
    ret_std = printf("STD: [%+8.d]\n", d);
    ret_ft  = ft_printf("FT : [%+8.d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

       d = 42;
    ret_std = printf("STD: [%+8.1d]\n", d);
    ret_ft  = ft_printf("FT : [%+8.1d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

       d = 42;
    ret_std = printf("STD: [%+8.4d]\n", d);
    ret_ft  = ft_printf("FT : [%+8.4d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

       d = 42;
    ret_std = printf("STD: [%+08.4d]\n", d);
    ret_ft  = ft_printf("FT : [%+08.4d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: [% d]\n", d);
    ret_ft  = ft_printf("FT : [% d]\n", d);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    return (0);
}

//////////////////////////// ALTERNATE (#) /////////
/* #include <stdio.h>
#include "ft_printf_bonus.h"

int main(void)
{
    unsigned int hx = 0x2a; 
    unsigned int big = 0xFFFFFFFF; 
    int ret_std, ret_ft;

    // --- Basic # flag ---
    ret_std = printf("STD: %%#x = [%#x]\n", hx);
    ret_ft  = ft_printf("FT : %%#x = [%#x]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%#X = [%#X]\n", hx);
    ret_ft  = ft_printf("FT : %%#X = [%#X]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Width + # ---
    ret_std = printf("STD: %%#10x = [%#10x]\n", hx);
    ret_ft  = ft_printf("FT : %%#10x = [%#10x]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%#10X = [%#10X]\n", hx);
    ret_ft  = ft_printf("FT : %%#10X = [%#10X]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Zero flag + # ---
    ret_std = printf("STD: %%#010x = [%#010x]\n", hx);
    ret_ft  = ft_printf("FT : %%#010x = [%#010x]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%#010X = [%#010X]\n", hx);
    ret_ft  = ft_printf("FT : %%#010X = [%#010X]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Precision + # ---
    ret_std = printf("STD: %%#.5x = [%#.5x]\n", hx);
    ret_ft  = ft_printf("FT : %%#.5x = [%#.5x]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%#.5X = [%#.5X]\n", hx);
    ret_ft  = ft_printf("FT : %%#.5X = [%#.5X]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Width + precision + # ---
    ret_std = printf("STD: %%#10.5x = [%#10.5x]\n", hx);
    ret_ft  = ft_printf("FT : %%#10.5x = [%#10.5x]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%#10.5X = [%#10.5X]\n", hx);
    ret_ft  = ft_printf("FT : %%#10.5X = [%#10.5X]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Left align + # ---
    ret_std = printf("STD: %%#-10x = [%#-10x]\n", hx);
    ret_ft  = ft_printf("FT : %%#-10x = [%#-10x]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%#-10X = [%#-10X]\n", hx);
    ret_ft  = ft_printf("FT : %%#-10X = [%#-10X]\n", hx);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Edge case: value = 0 with # ---
    ret_std = printf("STD: %%#.0x = [%#.0x]\n", 0u);
    ret_ft  = ft_printf("FT : %%#.0x = [%#.0x]\n", 0u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%#.0X = [%#.0X]\n", 0u);
    ret_ft  = ft_printf("FT : %%#.0X = [%#.0X]\n", 0u);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // --- Large value with # ---
    ret_std = printf("STD: %%#x = [%#x]\n", big);
    ret_ft  = ft_printf("FT : %%#x = [%#x]\n", big);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    ret_std = printf("STD: %%#X = [%#X]\n", big);
    ret_ft  = ft_printf("FT : %%#X = [%#X]\n", big);
    printf("Return STD: %d | FT: %d\n\n", ret_std, ret_ft);

    return 0;
} */
