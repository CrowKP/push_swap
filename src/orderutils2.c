/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderutils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:15:51 by aigarcia          #+#    #+#             */
/*   Updated: 2023/03/16 20:15:52 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

int	checkposition(int *b, int *a, int *alen)
{
	int	it;

	it = 1;
	while (it < *alen)
	{
		if (b[0] < a[it] && b[0] > a[it - 1])
			return (it);
		it++;
	}
	if (b[0] > a[checkbig(a, alen)] || b[0] < a[checksmall(a, alen)])
		return (checksmall(a, alen));
	exit (0);
}

int	checkposdyn(int b, int *a, int *alen)
{
	int	it;

	it = 1;
	while (it < *alen)
	{
		if (b < a[it] && b > a[it - 1])
		{
			if (it > *alen / 2)
				return (*alen - it);
			return (it);
		}
		it++;
	}
	if (b > a[checkbig(a, alen)] || b < a[checksmall(a, alen)])
	{
		if (checksmall(a, alen) > *alen / 2)
			return (*alen - checksmall(a, alen));
		return (checksmall(a, alen));
	}
	if (b < a[0] && b > a[*alen - 1])
		return (0);
	exit (0);
}

int	checkposta(int b, int *a, int *alen)
{
	int	it;

	it = 1;
	while (it < *alen)
	{
		if (b < a[it] && b > a[it - 1])
			return (it);
		it++;
	}
	if (b > a[checkbig(a, alen)] || b < a[checksmall(a, alen)])
		return (checksmall(a, alen));
	if (b < a[0] && b > a[*alen - 1])
		return (0);
	exit (0);
}
