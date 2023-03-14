#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	index3(int *a, int *alen)
{
	if (a[0] < a[1] && a[0] < a[2] && a[1] > a[2])
	{
		sp(a, 0, alen, 0);
		rtp(a, 0, alen, 0);
	}
	if (a[0] > a[1] && a[0] < a[2])
		sp(a, 0, alen, 0);
	if (a[0] > a[1] && a[1] > a[2])
	{
		sp(a, 0, alen, 0);
		rrtp(a, 0, alen, 0);
	}
	if (a[0] > a[1] && a[1] < a[2])
		rtp(a, 0, alen, 0);
	if (a[0] < a[1] && a[0] > a[2])
		rrtp(a, 0, alen, 0);
}

void	index5(int *a, int *b, int *alen, int *blen)
{
	int	ns;
	int	nb;

	ns = checksmall(a, alen);
	nb = checkbig(a, alen);
	movenum(a, b, ns, nb, alen, blen);
	index3(a, alen);
	if (b[0] < b[1])
		rtp(0, b, 0, blen);
	pp(b, a, 0, blen, alen);
	rtp(a, 0, alen, 0);
	pp(b, a, 0, blen, alen);
}

void	index100(int *a, int *b, int *alen, int *blen)
{
	int	*tst;
	
	tst = dostack(*alen);
	cpystack(tst, a, alen);
	sortstack(tst, alen);
	easystack(a, tst, alen);
	rtp(a, b, alen, blen);
}
