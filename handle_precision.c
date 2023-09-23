#include "main.h"

/**
 * handle_precision - Calculates the precision
 * @format: format
 * @i: arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int handle_precision(const char *format, int *i, va_list list)
{
	int store_i = *i + 1;
	int precision = -1;

	if (format[store_i] != '.')
		return (precision);

	precision = 0;

	for (store_i += 1; format[store_i] != '\0'; store_i++)
	{
		if (is_digit(format[store_i]))
		{
			precision *= 10;
			precision += format[store_i] - '0';
		}
		else if (format[store_i] == '*')
		{
			store_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = store_i - 1;

	return (precision);
}
