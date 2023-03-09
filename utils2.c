/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:07:04 by aigarcia          #+#    #+#             */
/*   Updated: 2023/03/09 13:07:05 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	movenum(int *a, int *b, int ns, int nb)
{
	if ((ns == 0 && nb == 1) || (ns == 1 && nb == 0))
	{
		pp(a, b, 1);
		pp(a, b, 1);
	}
	if ((ns == 0 && nb == 2) || (nb == 0 && ns == 2))
	{
		pp(a, b, 1);
		sp(a, 0);
		pp(a, b, 1);
	}
	if ((ns == 0 && nb == 3) || (nb == 0 && ns == 3))
	{
		pp(a, b, 1);
		rrtp(a, 0);
		rrtp(a, 0);
		pp(a, b, 1);
	}
	else
		movenum2(a, b, ns, nb);
}

void	movenum2(int *a, int *b, int ns, int nb)
{
	if ((ns == 0 && nb == 4) || (nb == 0 && ns == 4))
	{
		rrtp(a, 0);
		pp(a, b, 1);
		pp(a, b, 1);
	}
	if ((ns == 1 && nb == 2) || (nb == 1 && ns == 2))
	{
		rtp(a, 0);
		pp(a, b, 1);
		pp(a, b, 1);
	}
	if ((ns == 1 && nb == 3) || (nb == 1 && ns == 3))
	{
		rtp(a, 0);
		pp(a, b, 1);
		sp(a, 0);
		pp(a, b, 1);
	}
	else
		movenum3(a, b, ns, nb);
}

void	movenum3(int *a, int *b, int ns, int nb)
{
	if ((ns == 1 && nb == 4) || (nb == 1 && ns == 4))
	{
		sp(a, 0);
		rrtp(a, 0);
		pp(a, b, 1);
		pp(a, b, 1);
	}
	if ((ns == 2 && nb == 3) || (nb == 2 && ns == 3))
	{
		rtp(a, 0);
		rtp(a, 0);
		pp(a, b, 1);
		pp(a, b, 1);
	}
	if ((ns == 2 && nb == 4) || (nb == 2 && ns == 4))
	{
		rrtp(a, 0);
		pp(a, b, 1);
		rtp(a, 0);
		rtp(a, 0);
		pp(a, b, 1);
	}
	else
		movenum4(a, b, ns, nb);
}

void	movenum4(int *a, int *b, int ns, int nb)
{
	if ((ns == 3 && nb == 4) || (nb == 3 && ns == 4))
	{
		rrtp(a, 0);
		rrtp(a, 0);
		pp(a, b, 1);
		pp(a, b, 1);
	}
}

int	checkbig(int *a)
{
	int	it;
	int	n;

	it = 0;
	n = 0;
	while (a[it])
	{
		if (a[it] > a[n])
			n = it;
		it++;
	}
	return (n);
}
