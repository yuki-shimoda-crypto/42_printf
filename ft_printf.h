/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:43:29 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/05 13:43:32 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <inttypes.h>

int			ft_printf(const char *format, ...);
ssize_t		ft_put_char(char c);
ssize_t		ft_put_str(char *str);
ssize_t		ft_put_ptr(uintptr_t num);

#endif