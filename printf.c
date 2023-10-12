#include <stdarg.h>
#include <stdio.h>

/**
 * my_printf - this function work like printf stdout
 * to do this we use variadic function
 * @args: number of args
 * Return: 0
 **/

int my_printf(const char *format, ...)
{
    va_list list;
    va_start(list, format);

    while(*(format) != '\0')
    {
        if (*format == '%')
        {
            switch(*(++format))
            {
                case 'd':
                printf("%d", va_arg(list, int));
                break;
                case 's':
                printf("%s", va_arg(list, char*));
                break;
                default:
                printf("Unknown format specifier: %c\n", *format);

            }
        } else {
            printf("%c", *format);
        }
        format++;
    }
    va_end(list);

    return(0);
}


int main()
{
    my_printf("my name is %s \nI am %d years old\nI am student at %s.\n", "Yadamzer Terefe", 21, "Kotebe");
    my_printf("the sum of %d and %d is : %d", 200, 250, (200 + 250));

    return (0);
}
