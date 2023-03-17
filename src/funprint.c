/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:24:59 by aigarcia          #+#    #+#             */
/*   Updated: 2023/01/31 18:25:00 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	rtp(int *a, int *b, int *alen, int *blen)
{
	if (a && b == NULL)
	{
		if (rotate(a, alen) == 0)
			roterror(a, b);
		else
			ft_printf("ra\n");
	}
	if (b && a == NULL)
	{
		if (rotate(b, blen) == 0)
			roterror(a, b);
		else
			ft_printf("rb\n");
	}
	if (b && a)
	{
		if (rotate(a, alen) == 0 || rotate(b, blen) == 0)
			roterror(a, b);
		else
			ft_printf("rr\n");
	}
}

void	rrtp(int *a, int *b, int *alen, int *blen)
{
	if (a && b == NULL)
	{
		if (revrot(a, alen) == 0)
			roterror(a, b);
		else
			ft_printf("rra\n");
	}
	if (b && a == NULL)
	{
		if (revrot(b, blen) == 0)
			roterror(a, b);
		else
			ft_printf("rrb\n");
	}
	if (b && a)
	{
		if (revrot(a, alen) == 0 || revrot(b, blen) == 0)
			roterror(a, b);
		else
			ft_printf("rrr\n");
	}
}

void	sp(int *a, int *b, int *alen, int *blen)
{
	if (a && b == NULL)
	{
		if (swapnumber(a, alen) == 0)
			swaperror(a, b);
		else
			ft_printf("sa\n");
	}
	if (b && a == NULL)
	{
		if (swapnumber(b, blen) == 0)
			swaperror(a, b);
		else
			ft_printf("sb\n");
	}
	if (b && a)
	{
		if (swapnumber(a, alen) == 0 || swapnumber(b, blen) == 0)
			swaperror(a, b);
		else
			ft_printf("ss\n");
	}
}

void	pa(int *src, int *dst, int *slen, int *dlen)
{
	if (slen == 0)
	{
		ft_printf("Error pushing b to a.\n");
		freestacks(src, dst);
	}
	else
	{
		push(src, dst, slen, dlen);
		ft_printf("pa\n");
	}
}

void	pb(int *src, int *dst, int *slen, int *dlen)
{
	if (slen == 0)
	{
		ft_printf("Error pushing a to b.\n");
		freestacks(src, dst);
	}
	else
	{
		push(src, dst, slen, dlen);
		ft_printf("pb\n");
	}
}
