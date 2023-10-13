#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: is a character string.
 * Return: int 
 */

int _printf(const char *format, ...)
{
int count = 0, i;
char ch;
char *st;
va_list(ap);
va_start(ap, format);
for (i = 0; format[i] != '\0'; i++)
        {
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				break;
			}
			switch (format[i])
			{
				case 'c':
					ch = va_arg(ap, int);
					putchar(ch);
					count++;
					break;
				case 's':
					st = va_arg(ap, char *);
					while (*st != '\0')
					{
						putchar(*st);
						st++;
						count++;
					}
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(format[i]);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
	}
va_end(ap);
return (count);
}

