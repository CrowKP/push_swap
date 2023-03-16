#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

int	checkposition(int *a, int *b, int *blen)
{
	int	it;

	it = 1;
	while (it < *blen)
	{
		if (a[0] > b[it] && a[0] < b[it - 1])
			return (it);
		it++;
	}
	return (0);
}

void	pushrandom(int *a, int *b, int *alen, int *blen)
{
	int	it;
	int	n;

	n = b[checkposition(a, b, blen)];
	it = checkposition(a, b, blen);
	if (it <= *blen / 2)
	{
		while (b[0] != n)
			rtp(0, b, 0, blen);
	}
	else
	{
		while (b[0] != n)
			rrtp(0, b, 0, blen);
	}
	pb(a, b, alen, blen);
}

void	rotb(int *b, int *blen)
{
	int	it;
	int	n;

	it = checkbig(b, blen);
	n = b[checkbig(b, blen)];
	if (it <= *blen / 2)
	{
		while (b[0] != n)
			rtp(0, b, 0, blen);
	}
	else
	{
		while (b[0] != n)
			rrtp(0, b, 0, blen);
	}
}
