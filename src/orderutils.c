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

int	checktop(int *a, int *alen, int jt)
{
	int	it;
	int	top;
	int	mod;

	it = 0;
	top = 0;
	if (*alen > 100 || jt > 100)
		mod = 44;
	else
		mod = 19;
	while (it <= *alen / 2)
	{
		if (a[it] >= jt && a[it] <= jt + mod)
		{
			top = it;
			return (top);
		}
		it++;
	}
	return (*alen / 2);
}

int	checkbot(int *a, int *alen, int jt)
{
	int	it;
	int	bot;
	int	mod;

	it = *alen - 1;
	bot = 0;
	if (*alen > 100 || jt > 100)
		mod = 44;
	else
		mod = 19;
	while (it > *alen / 2)
	{
		if (a[it] >= jt && a[it] <= jt + mod)
		{
			bot = it;
			return (bot);
		}
		it--;
	}
	return (bot);
}

int	rotstack(int *a, int *alen, int check, int hold)
{
	int	small;

	small = a[checksmall(a, alen)];
	if (a[0] == small)
	{
		rtp(a, 0, alen, 0);
		check = 1;
	}
	while (check == 0 && a[0] > a[*alen - 1] && a[0] < (a[checkbig(a, alen)]) - 4)
		rtp(a, 0, alen, 0);
	while (check == 1 && a[0] < hold && a[0] > a[*alen - 1] && a[0] < a[*alen - 1] + 4)
		rtp(a, 0, alen, 0);
	return (check);
}

void	pushstack(int *a, int *b, int *alen, int *blen)
{
	if (b[0] < a[0] && b[0] > a[*alen - 1])
		pa(b, a, blen, alen);
	else if (a[checkposition2(b, a, alen, blen)] == a[0])
	{
		rrtp(0, b, 0, blen);
		pa(b, a, blen, alen);
	}
	else if (b[0] > a[checkbig(a, alen)] || b[0] < a[checksmall(a, alen)])
		pushexb(a, b, alen, blen);
	else
		pushrandom(a, b, alen, blen);
}

void	pushexb(int *a, int *b, int *alen, int *blen)
{
	int	it;
	int	n;

	n = a[checksmall(a, alen)];
	it = checksmall(a, alen);
	while (a[0] != n)
	{
		if (it <= *alen / 2)
			rtp(a, 0, alen, 0);
		else
			rrtp(a, 0, alen, 0);
	}
	pa(b, a, blen, alen);
}
