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
		if (b[0] == n)
			rtp(a, 0, alen, 0);
		else if (checkposition2(b, blen, top) > *blen / 2)
		{
			rtp(a, 0, alen, 0);
			rrtp(0, b, 0, blen);
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
	while (a[0] != bot)
	{
		ft_printf("%d\n", b[0]);
		if (b[0] == n)
			rrtp(a, 0, alen, 0);
		else if (checkposition2(b, blen, bot) < *blen / 2)
		{
			rrtp(a, 0, alen, 0);
			rtp(0, b, 0, blen);
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
