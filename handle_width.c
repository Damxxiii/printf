#include "main.h"

/**
 * handle_width - Calculates the width for
 * @format: Format
 * @i: arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int handle_width(const char *format, int *i, va_list list)
{
	int store_i;
	int width = 0;

	for (store_i = *i + 1; format[store_i] != '\0'; store_i++)
	{
		if (is_digit(format[store_i]))
		{
			width *= 10;
			width += format[store_i] - '0';
		}
		else if (format[store_i] == '*')
		{
			store_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = store_i - 1;

	return (width);
}
