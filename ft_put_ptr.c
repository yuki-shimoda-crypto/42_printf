/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/04 23:30:18by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static ssize_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static void	ft_output(uintptr_t num, ssize_t *num_len)
{
	if (num >= 16)
	{
		ft_output(num / 16, num_len);
		ft_output(num % 16, num_len);
	}
	else
	{
		if (num % 16 < 10)
			*num_len += ft_putchar(num + '0');
		else
			*num_len += ft_putchar(num + 'a' - 10);
	}
}

ssize_t	ft_put_ptr(uintptr_t num)
{
	ssize_t	num_len;
	
	num_len = write(1, "0x", 2);
	if (!num)
		num_len += write(1, "0", 1);
	else
		ft_output(num, &num_len);
	return (num_len);
}