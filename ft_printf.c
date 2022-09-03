/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:20:46 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/04 01:11:22 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_proc_per(const char **format, size_t *printed, va_list *ap)
{
	(*format)++;
	if (**format == 'c')
		*printed += ft_put_char((char)va_arg(*ap, int));
	else if (**format == 's')
		*printed += ft_put_str((char *)va_arg(*ap, char *));
	else if (**format == 'p')
		*printed += ft_put_hex(format, (uintptr_t)va_arg(*ap, uintptr_t));
	else if (**format == 'd' || **format == 'i')
		*printed += ft_put_int(format, (int)va_arg(*ap, int));
	else if (**format == 'u')
		*printed += ft_put_int(format, (unsigned int)va_arg(*ap, unsigned int));
	else if (**format == 'x' || **format == 'X')
		*printed += ft_put_hex(format, (unsigned int)va_arg(*ap, unsigned int));
	else if (**format == '%')
		*printed += write(1, "%", 1);
	(*format)++;
}

static void	ft_print_str(const char **start, const char **format,
		size_t *printed)
{
	while (**format != '%' && **format)
		(*format)++;
	*printed += write(1, *start, *format - *start);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		printed;
	const char	*start;

	printed = 0;
	va_start(ap, format);
	while (*format && printed < INT_MAX)
	{
		start = format;
		if (*format != '%')
			ft_print_str(&start, &format, &printed);
		else
			ft_proc_per(&format, &printed, &ap);
	}
	va_end(ap);
	if (printed >= INT_MAX)
		return (-1);
	return (printed);
}

// int main(void)
// {
// 	int	i;

// 	i = 0;
// 	ft_printf("abc\t%c\t%s\t%d\t%i\t%u\t%x\t%X\t%p\n", 'd', "def", 1, 10, 100,
// 			1000, 1000, &i);
// 	printf("abc\t%c\t%s\t%d\t%i\t%u\t%x\t%X\t%p\n", 'd', "def", 1, 10, 100,
// 			1000, 1000, &i);
// 	return (0);
// }
