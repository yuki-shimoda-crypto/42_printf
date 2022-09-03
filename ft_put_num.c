/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/03 13:01:11yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static char	*ft_dec_to_hex(unsigned int num)
{
	char	ptr[13];
	int		i;

	i = 12;
	ptr[i] = '\0';
	while (num)
	{
		if (num % 16 < 10)
			ptr[--i] = num % 16 + '0';
		else
			ptr[--i] = num % 16 + 'a' - 10;
		num /= 16;
	}
	return (ft_strdup(&ptr[i]));
}

size_t	ft_put_hex(const char **format, unsigned int num)
{
	char	*hex;
	size_t	printed;
	size_t	i;

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
		printed += write(1, "0x", 2);
	write(1, hex, printed);
	free(hex);
	return (printed);
}

static char	*ft_uitoa(unsigned int num)
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

size_t	ft_put_int(const char **format, int d)
{
	char	*num;
	size_t	printed;

	if (**format == 'u')
		num = ft_uitoa(d);
	else
		num = ft_itoa(d);
	free(num);
	printed = ft_strlen(num);
	write(1, num, printed);
	return (printed);
}
