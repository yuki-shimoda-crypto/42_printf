/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/05 12:36:51y yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	int	i;

	i = 0;
	printf("#c\n");
	ft_printf("%c\t%c\n", 'c', '%');
	printf("%c\t%c\n\n", 'c', '%');

	printf("#str\n");
	ft_printf("%s\t%s\t%s\n", "42Tokyo", "", NULL);
	printf("%s\t%s\t%s\n\n", "42Tokyo", "", NULL);

	printf("#int\n");
	ft_printf("%d\t%d\t%d\t%d\n", i, 100, INT_MAX, INT_MIN);
	printf("%d\t%d\t%d\t%d\n\n", i, 100, INT_MAX, INT_MIN);

	printf("#uint\n");
	ft_printf("%u\t%u\t%u\n", i, 100, UINT_MAX);
	printf("%u\t%u\t%u\n\n", i, 100, UINT_MAX);

	printf("#hex\n");
	printf("%x\t%x\t%x\n", i, 255, UINT_MAX);
	printf("%x\t%x\t%x\n\n", i, 255, UINT_MAX);

	printf("#HEX\n");
	printf("%x\t%X\t%X\n", i, 255, UINT_MAX);
	printf("%x\t%X\t%X\n\n", i, 255, UINT_MAX);

	printf("#ptr\n");
	ft_printf("%p\t%p\t%p\t%p\n", &i, SIZE_MAX, NULL, 0);
	printf("%p\t%p\t%p\t%p\n\n", &i, SIZE_MAX, NULL, 0);

	printf("#percent\n");
	ft_printf("%%\n");
	printf("%%\n\n");

	printf("#mix\n");
	ft_printf("abc\t%c\t%s\t%d\t%i\t%u\t%x\t%X\t%p\t%%\n", 'd', "def", 1, 10,
			100, 100, 100, &i);
	printf("abc\t%c\t%s\t%d\t%i\t%u\t%x\t%X\t%p\t%%\n\n", 'd', "def", 1, 10, 100,
			100, 100, &i);

	printf("#return\n");
	printf("%d\n", ft_printf("abc\t%c\t%s\t%d\t%i\t%u\t%x\t%X\t%p\t%%\n", 'c',
				"str", 1, 10, 100, 255, 255, &i));
	printf("%d\n", printf("abc\t%c\t%s\t%d\t%i\t%u\t%x\t%X\t%p\t%%\n", 'c',
				"str", 1, 10, 100, 255, 255, &i));
	return (0);
}
