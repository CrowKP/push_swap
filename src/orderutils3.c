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

int	calclen(int *alen, int *blen)
{
	int	len;

	len = 0;
	if (*alen > 100 || *blen > 100)
	{
		while (len < *blen && *blen >= len + 45)
			len += 45;
	}
	else if (*alen < 100 || *blen < 100)
	{
		while (len < *blen && *blen >= len + 20)
			len += 20;
	}
	return (len);
}

void	rotbtran(int *a, int *b, int *alen, int *blen)
{
	int	top;
	int	it;
	int	n;

	it = calclen(alen, blen);
	top = a[checktop(a, alen, it)];
	n = b[checkposition2(b, blen, top)];
	while (a[0] != top)
	{
		if (*alen > 100 || *blen > 100)
		{
			if (b[0] >= it && b[0] <= it + 44)
				rtp(a, 0, alen, 0);
		}
		else if (*alen < 100 || *blen < 100)
		{
			if (b[0] >= it && b[0] <= it + 19)
				rtp(a, 0, alen, 0);
		}
		else
			rtp(a, b, alen, blen);
	}
}

void	rotbbran(int *a, int *b, int *alen, int *blen)
{
	int	bot;
	int	it;
	int	n;

	it = calclen(alen, blen);
	bot = a[checkbot(a, alen, it)];
	n = b[checkposition2(b, blen, bot)];
	//This loop does not break, chek it.
	while (a[0] != bot)
	{
		if (*alen > 100 || *blen > 100)
		{
			if (b[0] >= it && b[0] <= it + 44)
				rrtp(a, 0, alen, 0);
		}
		else if (*alen < 100 || *blen < 100)
		{
			if (b[0] >= it && b[0] <= it + 19)
				rrtp(a, 0, alen, 0);
		}
		else
			rrtp(a, b, alen, blen);
	}
}

int	checkposition2(int *b, int *blen, int pos)
{
	int	it;

	it = 1;
	while (it < *blen)
	{
		if (pos > b[it] && pos < b[it - 1])
			return (it);
		it++;
	}
	return (0);
}
