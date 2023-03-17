/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i500utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:14:34 by aigarcia          #+#    #+#             */
/*   Updated: 2023/03/17 14:44:09 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	cpystack(int *t, int *a, int *len)
{
	int	it;

	it = 0;
	while (it < *len)
	{
		t[it] = a[it];
		it++;
	}
}

void	sortstack(int *t, int *len)
{
	int	it;
	int	jt;

	it = 0;
	jt = 0;
	while (jt < *len)
	{
		while (it < *len - 1)
		{
			if (t[it] > t[it + 1])
				swap(&t[it], &t[it + 1]);
			it++;
		}
		it = 0;
		jt++;
	}
}

void	easystack(int *a, int *t, int *len)
{
	int	it;
	int	jt;

	it = 0;
	jt = 0;
	while (jt < *len)
	{
		if (a[jt] != t[it])
		{
			it++;
		}
		else
		{
			a[jt] = it;
			jt++;
			it = 0;
		}
	}
}

void	ordersmall(int *a, int *b, int *alen, int *blen)
{
	int	it;
	int	slen;

	slen = *alen - 1;
	it = 0;
	while (it < slen)
	{
		while (a[0] != it)
		{
			if (checksmall(a, alen) <= *alen / 2)
				rtp(a, 0, alen, 0);
			else
				rrtp(a, 0, alen, 0);
		}
		pb(a, b, alen, blen);
		it++;
	}
	it = 0;
	while (it < slen)
	{
		pa(b, a, blen, alen);
		it++;
	}
}

void	orderit(int *a, int *b, int *alen, int *blen)
{
	int	it;
	int	top;
	int	bottom;
	int	jt;

	it = 0;
	jt = *alen;
	while (*alen > 0)
	{
		if (jt == *alen + 20)
		{
			it += 20;
			jt = *alen;
		}
		else if (a[0] >= it && a[0] <= it + 19)
			pb(a, b, alen, blen);
		else if (a[0] > it + 19)
		{
			top = checktop(a, alen, it);
			bottom = checkbot(a, alen, it);
			while (a[0] > it + 19)
				rotstack(a, alen, top, bottom);
		}
	}
	finalpush(a, b, alen, blen);
}
