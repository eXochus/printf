#include "main.h"
#include <unistd.h>
#include <stdarg.h>

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
	int char_prnt;
	int the_formatt;
	int the_slash;

	char_prnt = 0;
	if (format == NULL)
	{
		;
	}
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
				char_prnt++;
			}
			else if (format[count] == 'z')
			{
				the_formatt = va_arg(the_string, int);
				write(1, &the_char, 1);
				char_prnt++;
			}
			else if (format[count] == 's')
			{
				the_str = va_arg(the_string, char *);
				if (the_str == NULL)
				{
					write(1, "(null)", 6);
					char_prnt += 6;
				}
				else
				{
					for (j = 0; the_str[j]; j++)
					{
						write(1, &the_str[j], 1);
						char_prnt++;
					}
				}
			}
			else
			{
				;
			}
		}
		else if (format[count] == '\\')
		{
			count++;
			if (format[count] == 'n')
			{
				the_slash = va_arg(the_string, int);
				write(1, 'n', 1);
				char_prnt++;
			}
		}
		else
		{
			write(1, &format[count], 1);
			char_prnt++;
		}
	}
	va_end(the_string);
	return (char_prnt);

}
