/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:20:46 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/04 21:36:40 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static ssize_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

static	void	ft_put_ptr(uintptr_t ptr, ssize_t *ptr_len)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16, ptr_len);
		ft_put_ptr(ptr % 16, ptr_len);
	}
	else
	{
		if (ptr % 16 < 10)
			*ptr_len += ft_putchar_fd(ptr + '0', 1);
		else
			*ptr_len += ft_putchar_fd(ptr + 'a' - 10, 1);
	}
}

static	ssize_t	ft_ptr(uintptr_t ptr)
{
	ssize_t	ptr_len;
	
	ptr_len = write(1, "0x", 2);
	if (!ptr)
		ptr_len += write(1, "0", 1);
	else
		ft_put_ptr(ptr, &ptr_len);
	return (ptr_len);
}

static	ssize_t	ft_putnbr_base(ssize_t nbr, char *base)
{
	ssize_t	base_len;
	ssize_t	nbr_len;
	ssize_t	power_index;

	base_len = ft_strlen(base);
	nbr_len = 0;
	power_index = 1;
	if (nbr < 0)
	{
		nbr_len += write(1, "-", 1);
		nbr *= -1;
	}
	while (nbr >= base_len * power_index)
		power_index *= base_len;
	while (power_index)
	{
		nbr_len += write(1, &base[nbr / power_index % base_len], 1);
		nbr %= power_index;
		power_index /= base_len;
	}
	return (nbr_len);
}

static void	ft_proc_per(const char **format, ssize_t *printed, va_list *ap)
{
	(*format)++;
	if (**format == 'c')
		*printed += ft_put_char((char)va_arg(*ap, int));
	else if (**format == 's')
		*printed += ft_put_str(va_arg(*ap, char *));
	else if (**format == 'p')
	{
		*printed += write(1, "0x", 2);
		*printed += ft_putnbr_base(va_arg(*ap, uintptr_t), "0123456789abcdef");
	}
	else if (**format == 'd' || **format == 'i')
		*printed += ft_putnbr_base((ssize_t)va_arg(*ap, int), "0123456789");
	else if (**format == 'u')
		*printed += ft_putnbr_base((ssize_t)va_arg(*ap, unsigned int), "0123456789");
	else if (**format == 'x')
		*printed += ft_putnbr_base((ssize_t)va_arg(*ap, unsigned int), "0123456789abcdef");
	else if (**format == 'X')
		*printed += ft_putnbr_base((ssize_t)va_arg(*ap, unsigned int), "0123456789ABCDEF");
	else if (**format == '%')
		*printed += write(1, "%", 1);
	(*format)++;
}
// va_argをキャストするのはreturn値がvoidポインタが帰ってきてしまうときが

static void	ft_print_str(const char **format, ssize_t *printed)
{
	const char	*start;

	start =	*format;
	while (**format != '%' && **format)
		(*format)++;
	*printed += write(1, start, *format - start);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	ssize_t		printed;

	printed = 0;
	va_start(ap, format);
	while (*format && printed < INT_MAX)
	{
		if (*format != '%')
			ft_print_str(&format, &printed);
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
