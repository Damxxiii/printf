#include "main.h"

/**
 * handle_flags - flags
 * @format: Formatted string
 * @i: stores an input
 * Return: Flags:
 */
int handle_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int a, store_i;
	int flags = 0;
	const char flags_ch[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flags_array[] = {f_minus, f_plus, f_zero, f_hash, f_space, 0};

	for (store_i = *i + 1; format[store_i] != '\0'; store_i++)
	{
		for (a = 0; flags_ch[a] != '\0'; a++)
			if (format[store_i] == [a])
			{
				flags != flags_array[a];
				break;
			}

		if (flags_ch[a] == 0)
			break;
	}

	*i = store_i - 1;

	return (flags);
}
