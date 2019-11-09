#include "libftprintf.h"

int	main(int argv, char *argc[])
{
	int i;
	// ft_printf("a%d\n", 10);
	// ft_printf("\n");
	// ft_printf("mine: abc%c%c%c%%%s%p===%000000d, %i, %u, %u, %x, %Xabc%0\n", 'x', 'y', 'z', "mno", &i, 123456789, 017, 017, -15, 15, 15);
	// printf("orig: abc%c%c%c%%%s%p===%000000d, %i, %u, %u, %x, %Xabc%0\n", 'x', 'y', 'z', "mno", &i, 123456789, 017, 017, -15, 15, 15);
	// ft_printf("mine: %00000000!%%%\n", 12);
	// printf("orig: %00000000!%%%\n", 12);
	// printf("mine: size= %d\n", ft_printf("mine: abc%c%c%c%%%s%p===%0d, %i, %u, %u, %x, %Xabc\n", 'x', 'y', 'z', "mno", &i, 123456789, 017, 017, -15, 15, 15));
	// printf("orig: size= %d\n", printf("orig: abc%c%c%c%%%s%p===%0d, %i, %u, %u, %x, %Xabc\n", 'x', 'y', 'z', "mno", &i, 123456789, 017, 017, -15, 15, 15));
	// printf("mine: size= %d\n", ft_printf("mine: %%00000000!%%%\n", 12));
	// printf("orig: size= %d\n", printf("orig: %%00000000!%%%\n", 12));
	// ft_printf("mine: dab\n", 12);
	// printf("%u\n", (unsigned int)-1);
	// printf("%ld\n", (unsigned long)&i);
	// printf("%p\n", &i);
	// printf("%d\n", (int)&i);
	// printf("%00000000*d\n", 2, 3);
	// printf("******ahkskj%-*dkhkj\n", 3, 3);
	// printf("ahkskj%+*.dkhkj\n", 3,  3);
	// printf("ahkskj%--*.dkhkj\n", 3,  3);
	// printf("ahkskj%*.*dkhkj\n", 3, 6, 3);
	// printf( "a%.*fa\n", 3, 3.14159265 ); /* 3.142 output */
	// printf( "a%*.fa\n", 3, 3.14159265 ); /* 3.142 output */
	// printf("orig:%d\n",5);
	printf("%d\n", ft_printf("mine:%-*1.10iabc\n", 15, -555555, 50));
	printf("%d\n", printf("orig:%-*1.10iabc\n", 15,-555555, 50));
	// ft_printf("mine:%.10.*d\n",8, 555555);
	// while(1);

}
