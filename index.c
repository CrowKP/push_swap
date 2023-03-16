/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:15:13 by aigarcia          #+#    #+#             */
/*   Updated: 2023/03/16 20:15:14 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	index3(int *a, int *alen)
{
	if (*alen == 2)
	{
		if (a[0] > a[1])
			sp(a, 0, alen, 0);
	}
	else if (a[0] < a[1] && a[0] < a[2] && a[1] > a[2])
	{
		sp(a, 0, alen, 0);
		rtp(a, 0, alen, 0);
	}
	else if (a[0] > a[1] && a[0] < a[2])
		sp(a, 0, alen, 0);
	else if (a[0] > a[1] && a[1] > a[2])
	{
		sp(a, 0, alen, 0);
		rrtp(a, 0, alen, 0);
	}
	else if (a[0] > a[1] && a[1] < a[2])
		rtp(a, 0, alen, 0);
	else if (a[0] < a[1] && a[0] > a[2])
		rrtp(a, 0, alen, 0);
}

void	index4(int *a, int *b, int *alen, int *blen)
{
	movesmall(a, b, alen, blen);
	index3(a, alen);
	pa(b, a, blen, alen);
}

void	index5(int *a, int *b, int *alen, int *blen)
{
	movenum(a, b, alen, blen);
	index3(a, alen);
	if (b[0] < b[1])
		rtp(0, b, 0, blen);
	pa(b, a, blen, alen);
	rtp(a, 0, alen, 0);
	pa(b, a, blen, alen);
}

void	index100(int *a, int *b, int *alen, int *blen)
{
	int	*tst;

	tst = dostack(*alen);
	cpystack(tst, a, alen);
	sortstack(tst, alen);
	easystack(a, tst, alen);
	if (*alen > 20)
		orderit(a, b, alen, blen);
	else
		ordersmall(a, b, alen, blen);
}

void	index500(int *a, int *b, int *alen, int *blen)
{
	int	*tst;

	tst = dostack(*alen);
	cpystack(tst, a, alen);
	sortstack(tst, alen);
	easystack(a, tst, alen);
	order500(a, b, alen, blen);
}
