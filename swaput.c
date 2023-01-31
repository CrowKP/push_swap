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

int	stacklen(int *s)
{
	int	it;

	it = 0;
	while (s[it])
		it++;
	return (it);
}

int	*dostack(int argc)
{
	int	*s;

	s = NULL;
	if (argc < 2)
	{
		ft_printf("Error\n");
	}
	s = malloc((argc - 1) * sizeof * s);
	return (s);
}

void	savestack(int argc, char **argv, int *s)
{
	int	it;
	int	jt;

	it = 0;
	jt = 1;
	while (argc > jt)
	{
		s[it] = ft_atoi(argv[jt]);
		it++;
		jt++;
	}
}

void	swapprint(int *a, int *b)
{
	if (a && b == NULL)
	{
		if (swapnumber(a) == 0)
			ft_printf("Error in swapping a.\n");
		else
			ft_printf("sa\n");
	}
	if (b && a == NULL)
	{
		if (swapnumber(b) == 0)
			ft_printf("Error in swapping b.\n");
		else
			ft_printf("sb\n");
	}
	if (b && a)
	{
		if (swapnumber(a) == 0 || swapnumber(b) == 0)
			ft_printf("Error in swapping a, b or both.\n");
		else
			ft_printf("ss\n");
	}
}

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
