/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/05 12:36:51 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int	i;

	i = 0;
	
	ft_printf("abc\t%c\t%s\t%d\t%i\t%u\t%x\t%X\t%p\n", 'd', "def", 1, 10, 100,
			1000, 1000, &i);
	printf("abc\t%c\t%s\t%d\t%i\t%u\t%x\t%X\t%p\n", 'd', "def", 1, 10, 100,
			1000, 1000, &i);
	printf("#int\n");
	ft_printf("%d\t%d\t%d\t%d\n", i, 100, INT_MAX, INT_MIN);
	printf("%d\t%d\t%d\t%d\n", i, 100, INT_MAX, INT_MIN);

	printf("#uint\n");
	ft_printf("%u\t%u\t%u\n", i, 100, UINT_MAX);
	printf("%u\t%u\t%u\n", i, 100, UINT_MAX);

	printf("#hex\n");
	printf("%x\t%x\t%x\n", i, 255, UINT_MAX);
	printf("%x\t%x\t%x\n", i, 255, UINT_MAX);

	printf("#HEX\n");
	printf("%x\t%X\t%X\n", i, 255, UINT_MAX);
	printf("%x\t%X\t%X\n", i, 255, UINT_MAX);

	printf("#ptr\n");
	ft_printf("%p\t%p\t%p\t%p\n", &i, SIZE_MAX, NULL, 0);
	printf("%p\t%p\t%p\t%p\n", &i, SIZE_MAX, NULL, 0);
	return (0);

} 
