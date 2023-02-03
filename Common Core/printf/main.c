#include "ft_printf.h"

int main(int argc, char **argv)
{
    int     len;
    int     len2;
    int     n;
    char    *str;
    char    c;
    char    *out;
    
    out = " %s |\n";
    char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
    len = ft_printf(out, "-");
    len2 = printf(out, "-");
    printf(
        "ft_printf   len %i\nprintf      len %i\n",
        len,
        len2
    );
}

// • %c Prints a single character. DONE
// • %s Prints a string (as defined by the common C convention). 
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.