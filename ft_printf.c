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

static size_t ft_put_int(int d)
{
	char	*num;
	size_t	printed;

	num = ft_itoa(d);
	printed = ft_strlen(num);
	write(1, num, printed);
	ft_itoa(d);
	return (printed);
}

static size_t ft_put_char(int c)
{
	write(1, &c, 1);
	return (1);
}

static size_t ft_put_str(char *str)
{
	size_t	printed;

	printed = ft_strlen(str);
	write(1, str, printed);
	return (printed);
}

static void ft_init_flags(t_flags *specication)
{
	// specication->flags = -1;
	// specication->width = -1;
	// specication->precision = -1;
	// specication->modifier = -1;
	specication->conversion = -1;
	// specication->putnum = -1;
}

static void	ft_proc_per(const char **start, const char **format, size_t *printed, va_list ap)
{
	// t_flags	specication;
	
	// specication.conversion = ft_strchr("cspdiuxX%", **start);
	(*format)++;
	if (**format == 'c')
		*printed += ft_put_char(va_arg(ap, int));
	else if (**format == 's')
		*printed += ft_put_str(va_arg(ap, char *));
	else if (**format == 'p')
		*printed += ft_put_ptr(va_arg(ap, char *));
	else if (**format == 'd')
		*printed += ft_put_int(va_arg(ap, int));
	else if (**format == 'i')
		*printed += ft_put_int(va_arg(ap, int));
	else if (**format == 'u')
		*printed += ft_put_udec(va_arg(ap, int));
	else if (**format == 'x')
		*printed += ft_put_uhex(va_arg(ap, int));
	else if (**format == 'X')
		*printed += ft_put_uhex(va_arg(ap, int));
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
	// printf("%zu\n", ft_strlen("strlen"));
	ft_printf("abc\n%c\n%s\n", 'd', "def");
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