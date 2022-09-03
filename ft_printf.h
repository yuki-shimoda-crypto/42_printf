/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:27:06 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/03 17:33:38 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int			ft_printf(const char *format, ...);
size_t		ft_put_char(char c);
size_t		ft_put_str(char *str);
size_t		ft_put_int(const char **format, int d);
size_t		ft_put_hex(const char **format, unsigned long num);

#endif