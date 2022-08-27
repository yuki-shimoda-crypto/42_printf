/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:57:55 by yshimoda          #+#    #+#             */
/*   Updated: 2022/08/27 19:24:34 by yshimoda         ###   ########.fr       */
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

#endif