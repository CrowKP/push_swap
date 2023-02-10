#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	index3(int *a)
{
	if (a[0] < a[1] && a[0] < a[2] && a[1] > a[2])
	{
		swapprint(a, 0);
		rotateprint(a, 0);
	}
	if (a[0] > a[1] && a[0] < a[2])
		swapprint(a, 0);
	if (a[0] > a[1] && a[1] > a[2])
	{
		swapprint(a, 0);
		revrotprint(a, 0);
	}
	if (a[0] > a[1] && a[1] < a[2])
		rotateprint(a, 0);
	if (a[0] < a[1] && a[0] > a[2])
		revrotprint(a ,0);
}

void	index5(int *a, int *b)
{
	if (a && b)
		ft_printf("I'm here.\n");
}