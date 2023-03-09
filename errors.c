#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	swaperror(int *a, int *b)
{
	if (a && b == NULL)
	{
		ft_printf("Error in swapping a.\n");
		freestacks(a, b);
	}
	if (b && a == NULL)
	{
		ft_printf("Error in swapping b.\n");
		freestacks(a, b);
	}
	if (b && a)
	{
		ft_printf("Error in swapping a, b or both.\n");
		freestacks(a, b);
	}
}

void	roterror(int *a, int *b)
{
	if (a && b == NULL)
	{
		ft_printf("Error in rotating a.\n");
		freestacks(a, b);
	}
	if (b && a == NULL)
	{
		ft_printf("Error in rotating b.\n");
		freestacks(a, b);
	}
	if (b && a)
	{
		ft_printf("Error in rotating a, b or both.\n");
		freestacks(a, b);
	}
}
