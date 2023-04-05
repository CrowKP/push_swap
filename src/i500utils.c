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

	small = a[checksmall(a, alen)];
	if (a[0] == small)
	{
		rtp(a, 0, alen, 0);
		check = 1;
	}
	else if (a[0] <= 50)
	{
		rtp(a, 0, alen, 0);
		check = 1;
	}
	else if (check == 1)
	{
		while (a[0] < a[*alen - 1] + 10 && a[0] < hold && a[0] > a[*alen - 1])
			rtp(a, 0, alen, 0);
	}
	return (check);
}
