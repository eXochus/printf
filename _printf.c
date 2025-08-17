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
	int the_arg;
	int the_char;
	char * the_str;
	char the_spec;
	int str_count;

	count = 0;
	va_start(the_string, format);
	while (format[count] != '\0')
	{
		the_arg = format[count];
		switch (the_arg)
		{
		case 'c':
			the_char = va_arg(the_string, int);
			write(1, &the_char, 1);
			break;
		case 's':
			the_str = va_arg(the_string, char *);
			for (str_count = 0; the_str[str_count] != '\0'; str_count++)
				write(1, &the_str[str_count], 1);
			break;
		case '%':
			the_spec = va_arg(the_string, int);
			write(1, &the_spec, 1);
			break;
		default:
			write(1, "\n", 1);
			break;
		}
		count++;
	}
	va_end(the_string);
	return (strlen(the_str));
}
