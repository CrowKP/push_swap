/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i500utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:14:34 by aigarcia          #+#    #+#             */
/*   Updated: 2023/03/16 20:14:35 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	order500(int *a, int *b, int *alen, int *blen)
{
	int	check;
	int	hold;

	hold = a[*alen - 1];
	check = 0;
	while (a[0] != hold)
	{
		check = rotstack500(a, alen, check, hold);
		pb(a, b, alen, blen);
	}
	while (*blen > 0)
		pushstack(a, b, alen, blen);
	hold = a[checksmall(a, alen)];
	if (checksmall(a, alen) <= *alen / 2)
	{
		while (a[0] != hold)
			rtp(a, 0, alen, 0);
	}
	else
	{
		while (a[0] != hold)
			rrtp(a, 0, alen, 0);
	}
}

int	rotstack500(int *a, int *alen, int check, int hold)
{
	int	small;
	int	it;

	small = a[checksmall(a, alen)];
	if (a[0] == small)
	{
		rtp(a, 0, alen, 0);
		check = 1;
	}
	else if (check == 0 && a[0] <= 25)
	{
		hold = a[0];
		rtp(a, 0, alen, 0);
		check = 2;
		it = a[scan500(a, alen)];
	}
	while (a[0] != it && check == 2)
		return (check);
	if (a[0] < hold && check == 1)
		rtp(a, 0, alen, 0);
	else if (check == 2 && a[0] < (a[*alen - 1] + 5))
		rtp(a, 0, alen, 0);
	return (check);
}

void	rota(int *a, int *b, int *alen, int *blen)
{
	int	hold;
	int	holdb;
	int	it;

	holdb = b[pushpos(a, b, alen, blen)];
	it = checkposta(holdb, a, alen);
	hold = a[checkposta(holdb, a, alen)];
	while (a[0] != hold && b[0] == holdb)
	{
		if (it <= *alen / 2)
			rtp(a, 0, alen, 0);
		else
			rrtp(a, 0, alen, 0);
	}
}

int	scan500(int *a, int *alen)
{
	int	it;
	int	jt;
	int	check;
	int	count;

	it = 0;
	while (it < *alen)
	{
		check = it;
		if (a[it] < a[*alen - 1])
			it++;
		else if (a[it] - a[*alen - 1] < jt || !jt)
		{
			if (countsmall(a, alen, it) > count || !count)
			{
				jt = (a[it] - a[*alen - 1]);
				check = it;
				count = countsmall(a, alen, it);
			}
			it++;
		}
		else if (a[it] - a[*alen - 1] >= jt)
			it++;
	}
	return (check);
}

int	countsmall(int *a, int *alen, int it)
{
	int	count;
	int	ref;

	count = 0;
	ref = a[it];
	while (it < *alen)
	{
		if (a[it] < ref + 5 && a[it] > ref)
		{
			ref = a[it];
			count++;
		}
		it++;
	}
	return (count);
}
