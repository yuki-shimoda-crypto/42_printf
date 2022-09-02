/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/01 17:40:17 by yshimoda         ###   ########.fr       */
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

size_t ft_put_hex(const char **format, unsigned int num)
{
	char	*hex;
	size_t	printed;
	size_t		i;

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

size_t ft_put_int(const char **format, int d)
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
