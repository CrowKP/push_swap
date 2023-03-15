#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	movesmall(int *a, int *b, int ns, int *alen, int *blen)
{
	if (ns == 0)
		pp(a, b, 1, alen, blen);
	else if (ns == 1)
	{
		sp(a, 0, alen, 0);
		pp(a, b, 1, alen, blen);
	}
	else if (ns == 2)
	{
		rtp(a, 0, alen, 0);
		sp(a, 0, alen, 0);
		pp(a, b, 1, alen, blen);
	}
	else if (ns == 3)
	{
		rrtp(a, 0, alen, 0);
		pp(a, b, 1, alen, blen);
	}
}