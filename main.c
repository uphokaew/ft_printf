#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("\t |  Len: %d\n", ft_printf("123456"));
	printf("\t |  Len: %d (Real)\n", printf("123456"));

	printf("\t |  Len: %d\n", ft_printf("Test1: ff%222", "5"));
	printf("\t |  Len: %d (Real)\n", printf("Test1: ff%222", "5"));

	printf("\t |  Len: %d\n", ft_printf("Test2: ff%M %222", "4"));
	printf("\t |  Len: %d (Real)\n", printf("Test2: ff%M %222", "4"));

	printf("\t |  Len: %d\n", ft_printf("Test3: %sff%M%222", "g"));
	printf("\t |  Len: %d (Real)\n", printf("Test3: %sff%M%222", "g"));

	printf("\t |  Len: %d\n", ft_printf("Test4: %sff%M %M22", "g"));
	printf("\t |  Len: %d (Real)\n", printf("Test4: %sff%M %M22", "g"));

	ft_printf("C_Test: %s\n", "4");
	printf("R_Test: %s\n", "4");
	ft_printf("C_Test2: %M\n", -200000);
	printf("R_Test2: %M\n", -200000);
	return (0);
}
