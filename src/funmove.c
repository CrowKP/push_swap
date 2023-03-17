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

int	*swapnumber(int *a, int *len)
{
	int	temp;

	if (*len > 1)
	{
		temp = a[0];
		a[0] = a[1];
		a[1] = temp;
		return (a);
	}
	return (0);
}

int	*revrot(int *s, int *len)
{
	int	it;
	int	temp;

	it = *len - 1;
	if (*len >= 2)
	{
		temp = s[it];
		while (it >= 0)
		{
			s[it] = s[it - 1];
			it--;
		}
		s[0] = temp;
		return (s);
	}
	return (0);
}

void	push(int *src, int *dst, int *slen, int *dlen)
{
	int	it;

	if (*dlen > 0)
	{
		it = *dlen + 1;
		while (it > 0)
		{
			dst[it] = dst[it - 1];
			it--;
		}
	}
	*dlen = *dlen + 1;
	it = 0;
	dst[0] = src[0];
	while (it <= *slen)
	{
		src[it] = src[it + 1];
		it++;
	}
	*slen = *slen - 1;
	src[it] = '\0';
}

int	*rotate(int *s, int *len)
{
	int	it;
	int	temp;

	it = 0;
	if (*len >= 2)
	{
		temp = s[0];
		while (it < *len)
		{
			s[it] = s[it + 1];
			it++;
		}
		s[it - 1] = temp;
		return (s);
	}
	return (0);
}
