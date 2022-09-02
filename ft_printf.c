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

static void	ft_proc_per(const char **format, size_t *printed, va_list ap)
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
			ft_proc_per(&format, &printed, ap);
	}
	va_end(ap);
	return (printed);
}

// int main(void)
// {
// 	int	i;

// 	i = 0;
// 	ft_printf("abc\n%c\n%s\n%d\n%i\n%u\n%x\n%X\n%p\n", 'd', "def", 1, 10, 100, 1000, 1000, &i);
// 	return (0);
// }

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