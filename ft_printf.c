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

static void ft_init_flags(t_flags *specication)
{
	// specication->flags = -1;
	// specication->width = -1;
	// specication->precision = -1;
	// specication->modifier = -1;
	specication->conversion = -1;
	// specication->putnum = -1;
	// specication->putlen = -1;
}

static void	ft_proc_per(const char **start, const char **format, int *n)
{
	t_flags	specication;
	
specication.conversion = ft_strchr("cspdiuxX%", **start);

}

static void	ft_print_str(const char **start, const char **format, int *n)
{
	while (**format != '%' && **format)
		(*format)++;
	write(1, *start, *format - *start);
	*n += *format - *start;
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			n;
	const char *start;

	n = 0;
	va_start(ap, format);
	while (*format && *format)
	{
		start = format;
		if (*format != '%')
			ft_print_str(&start, &format, &n);
		else
			ft_proc_per(&start, &format, &n);
	}
	va_end(ap);
	return (n);
}

int main(void)
{
	// printf("%zu\n", ft_strlen("strlen"));
	ft_printf("aiueol");
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