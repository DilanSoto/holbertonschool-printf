#include "main.h"
#include <string.h>

/**
* write_char - writes the character ch to stdout
* @ch: the character to print
*
* Return: the number of characters printed (always 1).
*/
int _write_char(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * _putchar - writes the character ch to stdout
 * @ch: The character to print
 * Return: On success 1.
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * _print_char - prints a character to stdout
 * @args: the arguments pointer
 *
 * Return: the number of characters printed (always 1).
 */
int _print_char(va_list args)
{
	int buffer = va_arg(args, int);
	return (_write_char(buffer));
}

/**
 * _print_string - prints a string to stdout
 * @args: the argument pointer
 *
 * Return: the number of characters printed
 */
int _print_string(va_list args)
{
	char *str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	return (write(1, str, strlen(str)));
}

/**
 * _print_percent - prints a percent symbol to stdout
 * @args: the argument pointer
 * Return: the number of characters printed
 */
int _print_percent(va_list args)
{
	(void)args;
	return (_write_char('%'));
}

/**
 * _print_int - Prints an integer.
 * @args: The integer to print.
 *
 * Return: Chars and digits printed in to stdout.
 */
int _print_num(va_list args, int uppercase)
{
    return _print_num(args, 0); 
}


/**
 * _print_nint - Prints the integer of a decimal.
 * @args: Decimal to print.
 *
 * Return: Chars and digits printed in to the stdout.
 */
int _print_nint(va_list args)
{
	int _print_nint(va_list ap)
{
	int a[10];
	int j, m, n, sum, count;

	n = va_arg(ap, int);
	count = 0;
	m = 1000000000;

	a[0] = n / m;

	for (j = 1; j < 10; j++)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}

	if (n < 0)
	{
		_putchar('-');
		count++;
		for (j = 0; j < 10; j++)
		{
			a[j] *= -1;
		}
	}

	for (j = 0, sum = 0; j < 10; j++)
	{
		sum += a[j];

		if (sum != 0 || j == 9)
		{
			_putchar('0' + a[j]);
			count++;
		}
	}
	return (count);
}

/**
 * Helper function to print numbers in any base
 * @args: arguments list
 * @base: numeric base
 * @uppercase: flag for uppercase printing
 * Return: count of printed characters
 */
int _print_num(va_list args, int uppercase)
{
	int digits[10], j, m, num, sum, count = 0;
	num = va_arg(args, int);
	m = 1000000000;
	digits[0] = num / m;

	for (j = 1; j < 10; j++)
	{
		m /= 10;
		digits[j] = (num / m) % 10;
	}
	if (num < 0)
	{
		_putchar('-');
		count++;
		for (j = 0; j < 10; j++)
			digits[j] *= -1;
	}
	for (j = 0, sum = 0; j < 10; j++)
	{
		if (sum != 0 || j == 9)
		{
			char ch = uppercase ? '0' + digits[j] : '0' + digits[j] + 32;
			count += _write_char(ch);
		}
		sum += digits[j];
	}
	return count;
}
