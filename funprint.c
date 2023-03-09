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

void	rtp(int *a, int *b)
{
	if (a && b == NULL)
	{
		if (rotate(a) == 0)
			roterror(a, b);
		else
			ft_printf("ra\n");
	}
	if (b && a == NULL)
	{
		if (rotate(b) == 0)
			roterror(a, b);
		else
			ft_printf("rb\n");
	}
	if (b && a)
	{
		if (rotate(a) == 0 || rotate(b) == 0)
			roterror(a, b);
		else
			ft_printf("rr\n");
	}
}

void	rrtp(int *a, int *b)
{
	if (a && b == NULL)
	{
		if (revrot(a) == 0)
			roterror(a, b);
		else
			ft_printf("rra\n");
	}
	if (b && a == NULL)
	{
		if (revrot(b) == 0)
			roterror(a, b);
		else
			ft_printf("rrb\n");
	}
	if (b && a)
	{
		if (revrot(a) == 0 || revrot(b) == 0)
			roterror(a, b);
		else
			ft_printf("rrr\n");
	}
}

void	sp(int *a, int *b)
{
	if (a && b == NULL)
	{
		if (swapnumber(a) == 0)
			swaperror(a, b);
		else
			ft_printf("sa\n");
	}
	if (b && a == NULL)
	{
		if (swapnumber(b) == 0)
			swaperror(a, b);
		else
			ft_printf("sb\n");
	}
	if (b && a)
	{
		if (swapnumber(a) == 0 || swapnumber(b) == 0)
			swaperror(a, b);
		else
			ft_printf("ss\n");
	}
}

void	pp(int *src, int *dst, int check)
{
	if (!src[0])
	{
		if (check == 0)
			ft_printf("Error pushing b to a.\n");
		if (check == 1)
			ft_printf("Error pushing a to b.\n");
		freestacks(src, dst);
	}
	if (src[0])
	{
		push(src, dst);
		if (check == 0)
			ft_printf("pa\n");
		if (check == 1)
			ft_printf("pb\n");
	}
}
