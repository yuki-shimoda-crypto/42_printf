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

	i = 0;
	printf("% d\n", 1000);
	printf("% d\n", 1000);
	printf("%x\n", 1000);
	printf("%X\n", 1000);
	printf("%p\n", &i);

	return (0);
}