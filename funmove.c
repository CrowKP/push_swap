/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaput.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:25:09 by aigarcia          #+#    #+#             */
/*   Updated: 2023/01/31 18:25:10 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

int	*swapnumber(int *a)
{
	int	temp;

	if (a[0] && a[1])
	{
		temp = a[0];
		a[0] = a[1];
		a[1] = temp;
		return (a);
	}
	return (0);
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
