#include "main.h"

/**
 * _convert - converts an unsigned integer to a string in the given base
 * @num_to_convert: the number to be converted
 * @conv_base: the base to convert to
 *
 * Return: the converted number as a string
 */
char *_convert(unsigned int num_to_convert, int conv_base)
{
	const char representation[] = "0123456789ABCDEF";
	static char conv_buffer[50];
	char *ptr;

	ptr = &conv_buffer[49];
	*ptr = '\0';

	while (num_to_convert != 0)
	{
		*--ptr = representation[num_to_convert % conv_base];
		num_to_convert /= conv_base;
	}

	return (ptr);
}

/**
 * _print_reverse - prints a string in reverse
 * @args: action pointer
 *
 * Return: Number of characters printed
 */
int _print_reverse(va_list args)
{
	int len = 0;
	int i;
	char *str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (str[len])
		++len;
	i = len - 1;
	while (i >= 0)
		_putchar(str[i--]);
	return (len);
}

/**
 * _print_rot13 - encodes a string using rot13
 * @args: action pointer
 *
 * Return: length of the string
 */
int _print_rot13(va_list args)
{
	int i, j;
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13_alphabet[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	for (i = 0; str[i]; ++i)
	{
		for (j = 0; alphabet[j]; ++j)
		{
			if (alphabet[j] == str[i])
			{
				_putchar(rot13_alphabet[j]);
				break;
			}
		}
		if (!alphabet[j])
			_putchar(str[i]);
	}
	return (i);
}

/**
 * _print_unsigned - prints an unsigned integer
 * @args: action pointer
 *
 * Return: number of digits printed
 */
int _print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = _convert(num, 10);

	return (write(1, str, strlen(str)));
}

/**
 * _print_octal - prints an octal number
 * @args: action pointers
 *
 * Returns: number of digits printed
 */
int _print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = _convert(num, 8);

	return (write(1, str, strlen(str)));
}

/**
 * _print_number_base - function that prints a number in a given base
 * @args: the action pointer
 * @num_base: the base to print the number in
 * @is_uppercase: flag to determine if the letters should be in uppercase
 *
 * Return: the count
 */
int _print_number_base(va_list args, int num_base, int is_uppercase)
{
	int i;
	unsigned int num;
	char *str;
	int count = 0;

	num = va_arg(args, unsigned int);
	str = _convert(num, num_base);

	if (!num)
		count += _putchar('0');

	for (i = 0; str[i]; i++)
	{
		if (is_uppercase && str[i] >= 'a' && str[i] <= 'f')
			count += _putchar(str[i] - 32); /* convert to uppercase*/
		else
			count += _putchar(str[i]);
	}
	return (count);
}

/**
 * _print_binary - function that prints a binary number from int
 * @args: the action pointer
 *
 * Return: the binary number
 */
int _print_binary(va_list args)
{
	return (_print_number_base(args, 2, 0));
}

/**
 * _print_hex_u - function that prints a hex number from int (uppercase)
 * @args: the action pointer
 *
 * Return: to count
 */
int _print_hex_u(va_list args)
{
	return (_print_number_base(args, 16, 1));
}

/**
 * _print_hex_l - function that prints a hex number from int (lowercase)
 * @args: the action pointer
 *
 * Return: count
 */
int _print_hex_l(va_list args)
{
	return (_print_number_base(args, 16, 0));
}
