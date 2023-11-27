#include "main.h"
#include <string.h>

int _write_char(char ch) {
    return (write(1, &ch, 1));
}

int _putchar(char ch) {
    return (write(1, &ch, 1));
}

int _print_char(va_list args) {
    int buffer = va_arg(args, int);
    return (_write_char(buffer));
}

int _print_string(va_list args) {
    char *str = va_arg(args, char *);
    if (str == NULL)
        str = "(null)";
    return (write(1, str, strlen(str)));
}

int _print_percent(va_list args) {
    (void)args;
    return (_write_char('%'));
}

int _print_int(va_list args) {
    return _print_num(args, 0);
}

int _print_nint(va_list args) {
    return _print_num(args, 0);
}

int _print_num(va_list args, int uppercase) {
    int digits[10], j, m, num, sum, count = 0;
    num = va_arg(args, int);
    m = 1000000000;
    digits[0] = num / m;

    for (j = 1; j < 10; j++) {
        m /= 10;
        digits[j] = (num / m) % 10;
    }
    if (num < 0) {
        _putchar('-');
        count++;
        for (j = 0; j < 10; j++)
            digits[j] *= -1;
    }
    for (j = 0, sum = 0; j < 10; j++) {
        if (sum != 0 || j == 9) {
            char ch = uppercase ? '0' + digits[j] - 32 : '0' + digits[j];
            count += _write_char(ch);
        }
        sum += digits[j];
    }
    return count;
}
#include "main.h"
#include <string.h>

int _write_char(char ch) {
    return (write(1, &ch, 1));
}

int _putchar(char ch) {
    return (write(1, &ch, 1));
}

int _print_char(va_list args) {
    int buffer = va_arg(args, int);
    return (_write_char(buffer));
}

int _print_string(va_list args) {
    char *str = va_arg(args, char *);
    if (str == NULL)
        str = "(null)";
    return (write(1, str, strlen(str)));
}

int _print_percent(va_list args) {
    (void)args;
    return (_write_char('%'));
}

int _print_int(va_list args) {
    return _print_num(args, 0);
}

int _print_nint(va_list args) {
    return _print_num(args, 0);
}

int _print_num(va_list args, int uppercase) {
    int digits[10], j, m, num, sum, count = 0;
    num = va_arg(args, int);
    m = 1000000000;
    digits[0] = num / m;

    for (j = 1; j < 10; j++) {
        m /= 10;
        digits[j] = (num / m) % 10;
    }
    if (num < 0) {
        _putchar('-');
        count++;
        for (j = 0; j < 10; j++)
            digits[j] *= -1;
    }
    for (j = 0, sum = 0; j < 10; j++) {
        if (sum != 0 || j == 9) {
            char ch = uppercase ? '0' + digits[j] - 32 : '0' + digits[j];
            count += _write_char(ch);
        }
        sum += digits[j];
    }
    return count;
}
