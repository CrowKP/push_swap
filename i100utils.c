/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i100utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:07:01 by aigarcia          #+#    #+#             */
/*   Updated: 2023/03/14 15:07:02 by aigarcia         ###   ########.fr       */
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
			it++;
		else
		{
			a[jt] = it;
			jt++;
			it = 0;
		}
	}
}
