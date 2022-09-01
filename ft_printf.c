/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#             */
/*   Updated: 2022/08/27 19:16:30y yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static char *ft_dec_to_hex(unsigned int num)
{
	char	ptr[9];
	int		i;

	i = 8;
	ptr[i] = '\0';
	while (num)
	{
		if (num % 16 < 10)
			ptr[--i] = num % 16 + '0';
		else if (num % 16 == 10)
			ptr[--i] = 'a';
		else if (num % 16 == 11)
			ptr[--i] = 'b';
		else if (num % 16 == 12)
			ptr[--i] = 'c';
		else if (num % 16 == 13)
			ptr[--i] = 'd';
		else if (num % 16 == 14)
			ptr[--i] = 'e';
		else if (num % 16 == 15)
			ptr[--i] = 'f';
		num /= 16;
	}
	return (ft_strdup(&ptr[i]));
}

static size_t ft_put_hex(const char **format, unsigned int num)
{
	char	*hex;
	size_t	printed;
	int		i;

	hex = ft_dec_to_hex(num);
	printed = ft_strlen(hex);
	i = 0;
	if (**format == 'X')
	{
		while (i < printed)
		{
			hex[i] = ft_toupper(hex[i]);
			i++;
		}
	}
	if (**format == 'p')
	{
		write(1, "0", 1);
		write(1, "x", 1);
	}
	write(1, hex, printed);
	return (printed);
}

static char *ft_uitoa(unsigned int num)
{
	char			ptr[11];
	int				i;

	i = 10;
	ptr[i] = '\0';
	while (num)
	{
		ptr[--i] = num % 10 + '0';
		num /= 10;
	}
	return (ft_strdup(&ptr[i]));
}

static size_t ft_put_int(const char **format, int d)
{
	char	*num;
	size_t	printed;

	if (**format == 'u')
		num = ft_uitoa(d);
	else
		num = ft_itoa(d);
	printed = ft_strlen(num);
	write(1, num, printed);
	return (printed);
}

static size_t ft_put_str(char *str)
{
	size_t	printed;

	printed = ft_strlen(str);
	write(1, str, printed);
	return (printed);
}

static size_t ft_put_char(int c)
{
	write(1, &c, 1);
	return (1);
}

static void	ft_proc_per(const char **start, const char **format, size_t *printed, va_list ap)
{
	(*format)++;
	if (**format == 'c')
		*printed += ft_put_char(va_arg(ap, int));
	else if (**format == 's')
		*printed += ft_put_str(va_arg(ap, char *));
	else if (**format == 'p')
		*printed += ft_put_hex(format, va_arg(ap, uintptr_t));
	else if (**format == 'd')
		*printed += ft_put_int(format, va_arg(ap, int));
	else if (**format == 'i')
		*printed += ft_put_int(format, va_arg(ap, int));
	else if (**format == 'u')
		*printed += ft_put_int(format, va_arg(ap, unsigned int));
	else if (**format == 'x')
		*printed += ft_put_hex(format, va_arg(ap, unsigned int));
	else if (**format == 'X')
		*printed += ft_put_hex(format, va_arg(ap, unsigned int));
	(*format)++;
}

static void	ft_print_str(const char **start, const char **format, size_t *printed)
{
	while (**format != '%' && **format)
		(*format)++;
	write(1, *start, *format - *start);
	*printed += *format - *start;
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		printed;
	const char *start;

	printed = 0;
	va_start(ap, format);
	while (*format && printed <= INT_MAX)
	{
		start = format;
		if (*format != '%')
			ft_print_str(&start, &format, &printed);
		else
			ft_proc_per(&start, &format, &printed, ap);
	}
	va_end(ap);
	return (printed);
}

int main(void)
{
	int	i;

	i = 0;
	ft_printf("abc\n%c\n%s\n%d\n%i\n%u\n%x\n%X\n%p\n", 'd', "def", 1, 10, 100, 1000, 1000, &i);
	return (0);
}

// #define MAX_ARGS 3	/* 可変引数の最大個数 */
// int add(int n, ...)
// {
//   int total = 0;
//   va_list ap;
//   va_start(ap, n);
//   for(int i = 0; (i < n) && (i < MAX_ARGS); i++) {
//     total += va_arg(ap, int);
//   }
//   va_end(ap);
//   return total;
// }
// 
// int main(int argc, char *argv[]) {
//   printf("test 1:%d\n", add(0));
//   printf("test 2:%d\n", add(1, 10));
//   printf("test 3:%d\n", add(2, 10, 20));
//   printf("test 4:%d\n", add(3, 10, 20, 30));
//   printf("test 5:%d\n", add(4, 10, 20, 30, 40));
// }