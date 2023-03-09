#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	index3(int *a)
{
	if (a[0] < a[1] && a[0] < a[2] && a[1] > a[2])
	{
		sp(a, 0);
		rtp(a, 0);
	}
	if (a[0] > a[1] && a[0] < a[2])
		sp(a, 0);
	if (a[0] > a[1] && a[1] > a[2])
	{
		sp(a, 0);
		rrtp(a, 0);
	}
	if (a[0] > a[1] && a[1] < a[2])
		rtp(a, 0);
	if (a[0] < a[1] && a[0] > a[2])
		rrtp(a, 0);
}

void	index5(int *a, int *b)
{
	int	ns;
	int	nb;

	ns = checksmall(a);
	nb = checkbig(a);
	movenum(a, b, ns, nb);
	index3(a);
	if (b[0] < b[1])
		rtp(0, b);
	pp(b, a, 0);
	rtp(a, 0);
	pp(b, a, 0);
}
