#include "main.h"
#include <string.h>

/**
 * _print_i - Prints an integer.
 * @i: The integer to print.
 * @ap: A variable argument list that contains the integer to be printed.
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
 * _print_d - Prints the integer of a decimal.
 * @d: Decimal to print.
 * @ap: A variable argument list that contains the integer to be printed.
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
