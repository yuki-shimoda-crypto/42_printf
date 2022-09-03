/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:57:55 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/03 11:33:55 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct s_flags
{
	// int		flags;
	// int		width;
	// int		precision;
	// int		modifier;
	int		conversion;
	int		putnum;
	int		putlen;
}				t_flags;

int			ft_printf(const char *format, ...);
size_t		ft_put_char(int c);
size_t		ft_put_str(char *str);
size_t		ft_put_int(const char **format, int d);
size_t		ft_put_hex(const char **format, unsigned int num);

#endif