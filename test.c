/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/03 17:11:27 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	// long long	i;
	// char		str[10];
	// int			num;
	char *test;

	// i = 0;
	// bzero(str, 10);
	// str[0] = NULL;
	// memset(test, 'a', 2147483648);
	// printf("%s\n", test);
	// printf("% d\n", 1000);
	// printf("% d\n", 1000);
	// printf("%x\n", 1000);
	// printf("%X\n", 1000);
	// printf("%p\n", &i);
	// num = printf("NULL %s NULL\n", NULL);
	// printf("%d\n", num);
	// printf("%s\n", str);
	// printf("%zu\n", strlen(str));
	// // printf("%zu\n", strlen(NULL));
	// strcpy(str, "test");
	// printf("%s\n", str);
	test = (char *)malloc(sizeof(char) * 2147483647);
	// if (test == NULL)
	// 	return (NULL);
	memset(test, 'a', 2147483647);
	printf("%s\n", test);
	free(test);
	return (0);
}