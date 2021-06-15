
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	count;
	int rr;

	// count = ft_printf("[%*c]\n", 1, 'a');
	// printf("count == %d\n", count);
	// count = ft_printf("[%2c]\n", 'a');
	// printf("count == %d\n", count);
	// count = ft_printf("[%-2c]\n", 'a');
	// printf("count == %d\n", count);


	count = ft_printf("[%3.d]\n", 0);
	printf("count == %d\n", count);
	count = printf("[%3.d]\n", 0);
	printf("count == %d\n", count);

	count = ft_printf("[%3.d]\n", 1);
	printf("count == %d\n", count);
	count = printf("[%3.d]\n", 1);
	printf("count == %d\n", count);

	// count = ft_printf("[%p]\n", 1234);
	// printf("count == %d\n", count);
	// count = printf("[%p]\n", 1234);
	// printf("count == %d\n", count);

	// count = ft_printf("[%p]\n", 0);
	// printf("count == %d\n", count);
	// count = printf("[%p]\n", 0);
	// printf("count == %d\n", count);

	// count = ft_printf("[%p]\n", 1234);
	// printf("count == %d\n", count);
	// count = printf("[%p]\n", 1234);
	// printf("count == %d\n", count);
	
	// rr = 123;
	// count = ft_printf("[%-13.5sdasdf%c3342]\n", "123456790",'a');
	// printf("count == %d\n", count);
	// count = printf("[%-13.5sdasdf%c3342]\n", "123456790",'a');
	// printf("count == %d\n", count);
	// count = printf("[%-13.5s]\n", "123456790");
	// printf("count == %d\n", count);
	
	// count = ft_printf("[%-1.-2d]\n", 0);
	// printf("count == %d\n", count);
	// count = printf("[%-1.-2d]\n", 0);
	// printf("count == %d\n", count);

    // count = ft_printf("%5s", NULL);
	// printf("count == %d\n", count);
	// count = printf("%5s", NULL);
	// printf("count == %d\n", count);
	// count = ft_printf("%5s", "454");
	// printf("count == %d\n", count);
	// count = printf("%5s", "454");
	// printf("count == %d\n", count);

	// count = printf("[%21.1c]\n", 'a');
	// printf("count == %d\n", count);
	// count = printf("[%12.19s]\n", "01234567890");
	// printf("count == %d\n", count);
	// count = ft_printf("[%11c]\n", 'a');
	// printf("count == %d\n", count);
	system("leaks a.out");
	return (0);
}
