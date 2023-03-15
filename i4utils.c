#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	movesmall(int *a, int *b, int *alen, int *blen)
{
	int	ns;

	ns = checksmall(a, alen);
	if (ns == 0)
		pb(a, b, alen, blen);
	else if (ns == 1)
	{
		sp(a, 0, alen, 0);
		pb(a, b, alen, blen);
	}
	else if (ns == 2)
	{
		rtp(a, 0, alen, 0);
		sp(a, 0, alen, 0);
		pb(a, b, alen, blen);
	}
	else if (ns == 3)
	{
		rrtp(a, 0, alen, 0);
		pb(a, b, alen, blen);
	}
}
