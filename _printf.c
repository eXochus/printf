#include <stdarg.h>
#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * _printf - printf whatever is given to stdo
 * @format: format specifier
 * @...: variadic variable
 *
 * Return: returns the number of character printed
 */
int _printf(const char *format, ...)
{
	va_list the_string;
	unsigned int count;
	int the_char;

	va_start(the_string, format);
	for (count = 0; format[count] != '\0'; count++)
	{
		if (format[count] == '%')
		{
			count++;
			if (format[count] == 'c')
			{
				the_char = va_arg(the_string, int);
				write(1, &the_char, 1);
			}
		}
		write(1, &format[count], 1);
	}
	va_end(the_string);
	return (strlen(format));

}
