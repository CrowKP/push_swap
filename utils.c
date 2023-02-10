#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	freestacks(int *a, int *b)
{
	if (a)
		free(a);
	if (b)
		free(b);
	exit(0);
}

void	freestacksatoi(int *s, int sign)
{
	if (sign == -1)
		ft_printf("One of the numbers is too small.\n");
	if (sign == 1)
		ft_printf("One of the numbers is too big.\n");
	if (s)
		free(s);
	exit(0);
}

void	checknums(char *argv, int *s)
{
	int	it;

	it = 0;
	while (argv[it])
	{
		if ((argv[it] == '-' || argv[it] == '+'))
			if (ft_isdigit(argv[it + 1]) == 1)
				it++;
		if (ft_isdigit(argv[it]) == 0)
		{
			ft_printf("Some elements are not numbers.\n");
			freestacks(s, 0);
		}
		it++;
	}
}

void	checklen(int *a, int *b)
{
	int	len;

	len = stacklen(a);
	if (len == 3)
		index3(a);
	if (len == 5)
		index5(a, b);
}
