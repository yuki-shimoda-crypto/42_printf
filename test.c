/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/03 12:36:51 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int main(void)
{
	long long	i;
	char		str[10];
	int			num;

	i = 0;
	bzero(str, 10);
	// str[0] = NULL;
	printf("% d\n", 1000);
	printf("% d\n", 1000);
	printf("%x\n", 1000);
	printf("%X\n", 1000);
	printf("%p\n", &i);
	num = printf("NULL %s NULL\n", NULL);
	printf("%d\n", num);
	printf("%s\n", str);
	printf("%zu\n", strlen(str));
	// printf("%zu\n", strlen(NULL));
	strcpy(str, "test");
	printf("%s\n", str);
	return (0);
}