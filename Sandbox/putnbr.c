#include <stdio.h>
#include <stdlib.h>


void	print_bits(char unsigned c)
{
	unsigned int	i;

	i = 7;
	printf("Here is your byte : ");
	while (i < 8)
	{
		if (c & 1 << i)
			printf("1");
		else
			printf("0");
		i --;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	char	c[10] = "Bonjour";
	char	*s;
	long int long	x;

	print_bits(1);
	s = (char []){"Salut\n"};
	printf("%c\n", 2[c]);
	printf("%s", s);
	_Generic(x, long long int: printf("long int long\n"), default: printf("No\n"));
	return (0);
}
