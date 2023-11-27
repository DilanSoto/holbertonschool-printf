#include "main.h"
#include <string.h> /**
* _write_char - writes the character c to stdout
* @c: the character to print
*
* Return: the number of characters printed (always 1).
*/
int _write_char(char c)
{
	return (write(1, &c, 1));
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - prints a character to stdout
 * @ap: the arguments pointer
 *
 * Return: the number of characters printed (always 1).
 */
int _print_char(va_list ap)
{
	int buffer = va_arg(ap, int);

	write(1, &buffer, 1);
	return (1);
}

/**
 * print_string - prints a string to stdout
 * @ap: the argument pointer
 *
 * Return: the number of characters printed
 */
int _print_string(va_list ap)
{
	char *str;

	str = va_arg(ap, char *);

	if (str == NULL)
		str = "(null)";
	return (write(1, str, strlen(str)));
}

/**
 * _print_percent - prints a percent symbol to stdout
 * @ap: the argument pointer
 * Return: the number of characters printed
 */
int _print_percent(va_list ap)
{
	(void)ap;
	return (_write_char('%'));
}

/**
 * print_i - Prints an integer.
 * @i: The integer to print.
 *
 * Return: Chars and digits printed in to stdout.
 */
int _print_int(va_list ap)
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
 * print_d - Prints the integer of a decimal.
 * @d: Decimal to print.
 *
 * Return: Chars and digits printed in to the stdout.
 */
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
