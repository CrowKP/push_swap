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

	it = 0;
	top = 0;
	while (it <= *alen / 2)
	{
		if (a[it] >= jt && a[it] <= jt + 19)
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

	it = *alen - 1;
	bot = 0;
	while (it > *alen / 2)
	{
		if (a[it] >= jt && a[it] <= jt + 19)
		{
			bot = it;
			return (bot);
		}
		it--;
	}
	return (bot);
}

void	rotstack(int *a, int *alen, int top, int bottom)
{
	int	hold;

	if (top <= *alen - bottom)
	{
		hold = a[top];
		while (a[0] != hold)
			rtp(a, 0, alen, 0);
	}
	else if (top > *alen - bottom)
	{
		hold = a[bottom];
		while (a[0] != hold)
			rrtp(a, 0, alen, 0);
	}
}
