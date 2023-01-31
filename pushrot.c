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

void	rotateprint(int *a, int *b)
{
	if (a && b == NULL)
	{
		if (rotate(a) == 0)
			ft_printf("Error in rotating a.\n");
		else
			ft_printf("ra\n");
	}
	if (b && a == NULL)
	{
		if (rotate(b) == 0)
			ft_printf("Error in rotating b.\n");
		else
			ft_printf("rb\n");
	}
	if (b && a)
	{
		if (rotate(a) == 0 || rotate(b) == 0)
			ft_printf("Error in rotating a, b or both.\n");
		else
			ft_printf("rr\n");
	}
}

int	*rotate(int *s)
{
	int	it;
	int	temp;

	it = 0;
	if (s[2])
	{
		temp = s[0];
		while (s[it])
		{
			s[it] = s[it + 1];
			it++;
		}
		s[it - 1] = temp;
		return (s);
	}
	return (0);
}

void	revrotprint(int *a, int *b)
{
	if (a && b == NULL)
	{
		if (revrot(a) == 0)
			ft_printf("Error in reverse rotating a.\n");
		else
			ft_printf("rra\n");
	}
	if (b && a == NULL)
	{
		if (revrot(b) == 0)
			ft_printf("Error in reverse rotating b.\n");
		else
			ft_printf("rrb\n");
	}
	if (b && a)
	{
		if (revrot(a) == 0 || revrot(b) == 0)
			ft_printf("Error in reverse rotating a, b or both.\n");
		else
			ft_printf("rrr\n");
	}
}

int	*revrot(int *s)
{
	int	it;
	int	temp;

	it = stacklen(s) - 1;
	if (s[2])
	{
		temp = s[it];
		while (s[it])
		{
			s[it] = s[it - 1];
			it--;
		}
		s[0] = temp;
		return (s);
	}
	return (0);
}

void	push(int *src, int *dst)
{
	int	it;

	it = 0;
	if (src[0])
	{
		if (dst[0])
		{
			it = stacklen(dst) + 1;
			while (it > 0)
			{
				dst[it] = dst[it - 1];
				it--;
			}
		}
		it = 0;
		dst[0] = src[0];
		while (src[it])
		{
			src[it] = src[it + 1];
			it++;
		}
		src[it] = '\0';
	}
	else
		ft_printf("Pushing error.\n");
}
