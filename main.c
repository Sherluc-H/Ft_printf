#include "libftprintf.h"

int	main(int argv, char *argc[])
{
	int i;
	// ft_printf("a%d\n", 10);
	// ft_printf("\n");
	ft_printf("abc%c%c%c%%%s%p===%0d, %i, %u, %u, %x, %Xab\n", 'x', 'y', 'z', "mno", &i, 123456789, 017, 017, -15, 15, 15);
	printf("abc%c%c%c%%%s%p===%0d, %i, %u, %u, %x, %Xab\n", 'x', 'y', 'z', "mno", &i, 123456789, 017, 017, -15, 15, 15);

	// printf("%u\n", (unsigned int)-1);
	// printf("%ld\n", (unsigned long)&i);
	// printf("%p\n", &i);
	// printf("%d\n", (int)&i);
	// printf("%p\n", &i);
	// printf("%00000000*d\n", 2, 3);
	// printf("******ahkskj%-*dkhkj\n", 3, 3);
	// printf("ahkskj%+*.dkhkj\n", 3,  3);
	// printf("ahkskj%--*.dkhkj\n", 3,  3);
	// printf("ahkskj%*.*dkhkj\n", 3, 6, 3);
	// printf( "a%.*fa\n", 3, 3.14159265 ); /* 3.142 output */
	// printf( "a%*.fa\n", 3, 3.14159265 ); /* 3.142 output */


}
