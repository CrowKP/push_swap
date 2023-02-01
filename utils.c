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