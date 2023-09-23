#include "main.h"

/**
 * handle_size - Calculates the size
 * @format: Format
 * @i: arguments to be printed.
 *
 * Return: size
 */
int get_size(const char *format, int *i)
{
	int store_i = *i + 1;
	int size = 0;

	if (format[store_i] == 'l')
		size = S_LONG;
	else if (format[store_i] == 's')
		size = S_SHORT;

	if (size == 0)
		*i = store_i - 1;
	else
		*i = store_i;

	return (size);
}
