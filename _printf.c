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
	char *the_int;
	int k;
	int the_intt;

	char_prnt = 0;
	va_start(the_string, format);
	if (!format)
	{
		return (-1);
	}
	for (count = 0; format[count] != '\0'; count++)
	{
		if (format[count] == '%')
		{
			count++;
			if (format[count] == '\0')
			{
				va_end(the_string);
				return (-1);
			}
			
			if (format[count] == 'c')
			{
				the_char = va_arg(the_string, int);
				write(1, &the_char, 1);
				char_prnt++;
			}
			else if (format[count] == '%')
			{
				the_formatt = format[count];
				write(1, &the_formatt, 1);
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
			else if (format[count] == 'd')
			{
				the_int = va_arg(the_string, char *);
				for (k = 0; the_int[k] != '\0'; k++)
				{
					write(1, &the_int[k], 1);
					char_prnt++;
				}
			}
			else if (format[count] == 'i')
			{
				the_intt = va_arg(the_string, int);
				write(1, &the_intt, 1);
				char_prnt++;
			}
			else
			{
				write(1, &format[count - 1], 1);
				write(1, &format[count], 1);
				char_prnt +=2;
			}
		}
		else if (format[count] == '\\')
		{
			count++;
			if (format[count] == 'n')
			{
				the_slash = '\n';
				write(1, &the_slash, 1);
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
