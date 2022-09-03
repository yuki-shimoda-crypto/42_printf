/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/03 13:20:09 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int main(void)
{
	int	i;

	i = 0;
	// ft_printf("abc\t%c\t%s\t%d\t%i\t%u\t%x\t%X\t%p\t", 'd', "def", 1, 10, 100, 1000, 1000, &i);
	// printf("abc\t%c\t%s\t%d\t%i\t%u\t%x\t%X\t%p\t", 'd', "def", 1, 10, 100, 1000, 1000, &i);
	ft_printf("abc\t%c\t%s\t%d\t%i\t%u\t%x\t%X\t%p\n", 'd', "def", 1, 10, 100, 1000, 1000, &i);
	printf("abc\t%c\t%s\t%d\t%i\t%u\t%x\t%X\t%p\n", 'd', "def", 1, 10, 100, 1000, 1000, &i);
	return (0);
}