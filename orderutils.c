#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

int	checktop(int *a, int *alen)
{
	int	it;
	int	top;

	it = 0;
	while (it <= *alen / 2)
	{
		if (a[it] >= 0 || a[it] <= 19)
			top = it;
		it++;
	}
	return (top);
}

int	checkbot(int *a, int *alen)
{
	int	it;
	int	bot;

	it = *alen;
	while (it > *alen / 2)
	{
		if (a[it] >= 0 || a[it] <= 19)
			bot = it;
		it--;
	}
	return (bot);
}

void	rotstack(int *a, int *alen, int top, int bottom)
{
	if (*alen - top > bottom - *alen)
	{
		while (top > 0)
		{
			rtp(a, 0, alen, 0);
			top--;
		}
	}
	if (*alen - top < bottom - *alen)
	{
		while (bottom < *alen)
		{
			rrtp(a, 0, alen, 0);
			bottom++;
		}
	}
}

void	pushstack(int *a, int *b, int *alen, int *blen)
{
	if (*blen == 0 || (*blen == 1 && a[0] > b[0]))
		pb(a, b, alen, blen);
	else if (*blen == 1 && a[0] < b[0])
	{
		pb(a, b, alen, blen);
		sp(0, b, 0, blen);
	}
	else if (a[0] > b[0] && a[0] < b[*blen - 1])
		pb(a, b, alen, blen);
	else if (a[0] > b[checkbig(b, blen)])
	{
		pushexb(a, b, alen, blen);
	}
	else if (a[0] < b[checksmall(b, blen)])
	{
		pushexb(a, b, alen, blen);
		rtp(0, b, 0, blen);
	}
	else
	{
		pushrandom(a, b, alen, blen);
	}
}

void	pushexb(int *a, int *b, int *alen, int *blen)
{
	int	it;
	int	n;

	n = b[checkbig(b, blen)];
	it = checkbig(b, blen);
	while (b[0] != n)
	{
		if (it <= *blen / 2)
			rtp(0, b, 0, blen);
		else
			rrtp(0, b, 0, blen);
	}
	pb(a, b, alen, blen);
}
