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
	int	it;
	int	jt;

	it = 0;
	jt = *alen;
	while (*alen > 5)
	{
		if (jt == *alen + 45)
		{
			it += 45;
			jt = *alen;
		}
		else if (a[0] >= it && a[0] <= it + 44)
			pushstack(a, b, alen, blen);
		else if (a[0] > it + 44)
		{
			while (a[0] > it + 44)
				ft_printf("1");
		}
	}
	finalpush500(a, b, alen, blen);
}

void	rotb500(int *b, int *blen)
{
	int	it;
	int	n;

	it = checkbig(b, blen);
	n = b[checkbig(b, blen)];
	if (it <= *blen / 2)
	{
		while (b[0] != n)
			rtp(0, b, 0, blen);
	}
	else
	{
		while (b[0] != n)
			rrtp(0, b, 0, blen);
	}
}

void	finalpush500(int *a, int *b, int *alen, int *blen)
{
	int	it;
	int	slen;

	it = 0;
	slen = *blen;
	while (*alen > 0)
		pb(a, b, alen, blen);
	while (it < slen)
	{
		rotb500(b, blen);
		pa(b, a, blen, alen);
		it++;
	}
}
