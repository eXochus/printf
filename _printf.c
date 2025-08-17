#include "main.h"
#include <unistd.h>

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
	char *the_str;
	int j;

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
			else if (format[count] == 's')
			{
				the_str = va_arg(the_string, char *);
				for (j = 0; the_str[j]; j++)
					write(1, &the_str[j], 1);
			}
			else
			{
				;
			}
		}
		else
		{
			write(1, &format[count], 1);
		}
	}
	va_end(the_string);
	return (count);

}
