#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed characters.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printx = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[Bsize];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == Bsize)
				print_buffer(buffer, &buff_ind);
			printedx++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printx += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printx);
}

/**
 * print_buffer - Prints the contents of the buffer
 * @buffer: Array of characters
 * @buff_ind: Index 
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
