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

	it = 0;
	while (it < *alen)
	{
		if (b < a[it] && b > a[it - 1])
			return (it);
		it++;
	}
	if (b > a[checkbig(a, alen)] || b < a[checksmall(a, alen)])
		return (checksmall(a, alen));
	exit (0);
}
