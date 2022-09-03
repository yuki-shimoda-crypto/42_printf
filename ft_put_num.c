/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:27:57 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/03 17:34:40yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static char	*ft_dec_to_hex(unsigned long num)
{
	char	ptr[13];
	int		i;

	if (num == 0)
		return (ft_strdup("0"));
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

void	ft_put_hex(const char **format, unsigned long num, size_t *printed)
{
	char	*hex;
	size_t	i;

	hex = ft_dec_to_hex(num);
	i = 0;
	if (**format == 'X')
	{
		while (hex[i] != '\0')
		{
			hex[i] = (char)ft_toupper(hex[i]);
			i++;
		}
	}
	if (**format == 'p')
		*printed += write(1, "0x", 2);
	*printed += write(1, hex, ft_strlen(hex));
	free(hex);
}

static char	*ft_uitoa(unsigned int num)
{
	char	ptr[11];
	int		i;

	if (num == 0)
		return (ft_strdup("0"));
	i = 10;
	ptr[i] = '\0';
	while (num)
	{
		ptr[--i] = num % 10 + '0';
		num /= 10;
	}
	return (ft_strdup(&ptr[i]));
}

void	ft_put_int(const char **format, int d, size_t *printed)
{
	char	*num;

	if (**format == 'u')
		num = ft_uitoa(d);
	else
		num = ft_itoa(d);
	*printed += write(1, num, ft_strlen(num));
	free(num);
}
