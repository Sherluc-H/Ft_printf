#include "libftprintf.h"

int	main(int argv, char *argc[])
{
	int i;
	// ft_printf("a%d\n", 10);
	// ft_printf("\n");
	// ft_printf("mine: abc%c%c%c%%%s%p===%000000d, %i, %u, %u, %x, %Xabc\n", 'x', 'y', 'z', "mno", &i, 123456789, 017, 017, -15, 15, 15);
	// printf("orig: abc%c%c%c%%%s%p===%000000d, %i, %u, %u, %x, %Xabc\n", 'x', 'y', 'z', "mno", &i, 123456789, 017, 017, -15, 15, 15);
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
	// printf("%d\n", ft_printf("mine:%*.10iabc\n", 15, -555555, 50));
	// printf("%d\n", printf("orig:%*.10iabc\n", 15, -555555, 50));
	// printf("%d\n", ft_printf("mine:%-0*.0cabc\n", 50, 'a', 50));
	// printf("%d\n", printf("orig:%-0*.0cabc\n", 50, 'a', 50));
	// printf("%d\n", ft_printf("orig:%-0***10.5cabc\n", 50, 'a', 150));
	// printf("%d\n", printf("orig:%-0***10.5cabc\n", 50, 'a', 150));
	// printf("%d\n", ft_printf("mine:%", 50, 'a', 50));
	// printf("%d\n", printf("orig:%", 50, 'a', 50));
	// printf("%d\n", ft_printf("mine:%*.50sttt", 10, NULL, 50));
	// printf("%d\n", printf("orig:%*.50sttt", 10, NULL, 50));
	printf("%d\n", ft_printf("mine:%-0*.3sttt", 10, NULL, 50));
	printf("%d\n", printf("orig:%-0*.3sttt", 10, NULL, 50));
	// printf("%d\n", ft_printf("mine:%0*.5cttt", 10, '0', 50));
	// printf("%d\n", printf("orig:%0*.5cttt", 10, '0', 50));
	// printf("%d\n", ft_printf("mine:%-0*.0cabc\n", 50, '\0', 50));
	// printf("%d\n", printf("orig:%-0*.0cabc\n", 50, '\0', 50));
	// printf("%d\n", ft_printf("mine:%cabc\n", '\0', 50));
	// printf("%d\n", printf("orig:%cabc\n", '\0', 50));
	// printf("size= %d\n", ft_printf("mine: %-..**20da\n", 100, 1));
	// printf("size= %d\n", printf("orig: %-..**20da\n", 100, 1));
	// printf("%d123%d%d%d%d%d%dabc%sz\n", 0, 4, 5, 6, 7, 8, 9, "defhghijklmnopqrstuvwxy");
	// ft_printf("%d123%d%d%d%d%d%dabc%sz\n", 0, 4, 5, 6, 7, 8, 9, "defhghijklmnopqrstuvwxy");
	// printf("mine: size= %d\n", ft_printf("%c", 0));
	// printf("orig: size= %d\n", printf("%c", 0));
	// ft_printf("lol %*sabd", 100, "kek");
	// while(1);
	// printf("%d\n", ft_printf("mine:%-0*.50sttt", 10, NULL, 50));
	// printf("%d\n", printf("orig:%-0*.50sttt", 10, NULL, 50));
	printf("%d\n", ft_printf("mine:%-0*.50sttt", 10, "abcdef", 50));
	printf("%d\n", printf("orig:%-0*.50sttt", 10, "abcdef", 50));


}
	// printf("orig: abc%c%c%c%%%s%p===%000000d, %i, %u, %u, %x, %Xabc%0\n", 'x', 'y', 'z', "mno", &i, 123456789, 017, 017, -15, 15, 15);
//bizzare rien ne s'affiche