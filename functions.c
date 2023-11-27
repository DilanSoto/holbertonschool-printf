#include "main.h"
#include <string.h>
/**
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
