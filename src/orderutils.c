/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:15:39 by aigarcia          #+#    #+#             */
/*   Updated: 2023/03/16 20:15:40 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

int	rotstack(int *a, int *alen, int check, int hold)
{
	int	small;

	small = a[checksmall(a, alen)];
	if (a[0] == small)
	{
		rtp(a, 0, alen, 0);
		check = 1;
	}
	if (check == 2)
	{
		while (a[0] < (a[checkbig(a, alen)]) - 4 && a[0] > a[*alen - 1])
			rtp(a, 0, alen, 0);
	}
	if (check == 1)
	{
		while (a[0] < a[*alen - 1] + 4 && a[0] < hold && a[0] > a[*alen - 1])
			rtp(a, 0, alen, 0);
	}
	return (check);
}

void	pushstack(int *a, int *b, int *alen, int *blen)
{
	int	check;

	check = pushpos(a, b, alen, blen);
	if (b[0] < a[0] && b[0] > a[*alen - 1])
		pa(b, a, blen, alen);
	if (check <= *alen / 2)
	{
		pushbup(a, b, alen, blen);
		pa(b, a, blen, alen);
	}
	else if (check > *alen / 2)
	{
		pushbdown(a, b, alen, blen);
		pa(b, a, blen, alen);
	}
}

int	pushpos(int *a, int *b, int *alen, int *blen)
{
	int	it;
	int	jt;
	int	check;

	check = 0;
	it = 1;
	jt = checkposdyn(b[0], a, alen);
	while (it < *blen)
	{
		if (checkposdyn(b[it], a, alen) + it < jt)
		{
			check = it;
			jt = checkposdyn(b[it], a, alen) + it;
		}
		if (checkposdyn(b[*blen - it], a, alen) + (*blen - it) < jt)
		{
			check = *blen - it;
			jt = checkposdyn(b[*blen - it], a, alen) + (*blen - it);
		}
		it++;
	}
	return (check);
}

void	pushbup(int *a, int *b, int *alen, int *blen)
{
	int	hold;
	int	holdb;

	holdb = b[pushpos(a, b, alen, blen)];
	hold = a[checkposta(holdb, a, alen)];
	while (a[0] != hold && b[0] != holdb)
	{
		if (checkposta(holdb, a, alen) <= *alen / 2)
			rtp(a, b, alen, blen);
		else
		{
			rtp(0, b, 0, blen);
			rrtp(a, 0, alen, 0);
		}
	}
	while (a[0] != hold && b[0] == holdb)
	{
		if (checkposta(holdb, a, alen) <= *alen / 2)
			rtp(a, 0, alen, 0);
		else
			rrtp(a, 0, alen, 0);
	}
	while (b[0] != holdb && a[0] == hold)
		rtp(0, b, 0, blen);
}

void	pushbdown(int *a, int *b, int *alen, int *blen)
{
	int	hold;
	int	holdb;

	holdb = b[pushpos(a, b, alen, blen)];
	hold = a[checkposta(holdb, a, alen)];
	while (a[0] != hold && b[0] != holdb)
	{
		if (checkposta(holdb, a, alen) > *alen / 2)
			rrtp(a, b, alen, blen);
		else
		{
			rrtp(0, b, 0, blen);
			rtp(a, 0, alen, 0);
		}
	}
	while (a[0] != hold && b[0] == holdb)
	{
		if (checkposta(holdb, a, alen) <= *alen / 2)
			rtp(a, 0, alen, 0);
		else
			rrtp(a, 0, alen, 0);
	}
	while (b[0] != holdb && a[0] == hold)
		rrtp(0, b, 0, blen);
}
