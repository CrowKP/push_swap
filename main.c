/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:24:44 by aigarcia          #+#    #+#             */
/*   Updated: 2023/01/31 18:24:46 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;
	int	it = 0;

	a = dostack(argc);
	savestack(argc, argv, a);
	argcheck(a, argc);
	b = dostack(argc);
	checklen(a, b, argc);
	ft_printf("Stack a:\n");
	while (it < argc - 1)
	{
		ft_printf("%d\n", a[it]);
		it++;
	}
	it = 0;
	ft_printf("Stack b:\n");
	while (b[it])
	{
		ft_printf("%d\n", b[it]);
		it++;
	}
	return (0);
}

void	checknums(char *argv, int *s)
{
	int	it;

	it = 0;
	while (argv[it])
	{
		if ((argv[it] == '-' || argv[it] == '+'))
			if (ft_isdigit(argv[it + 1]) == 1)
				it++;
		if (ft_isdigit(argv[it]) == 0)
		{
			ft_printf("Some elements are not numbers.\n");
			freestacks(s, 0);
		}
		it++;
	}
}

int	*dostack(int argc)
{
	int	*s;

	s = NULL;
	if (argc < 2)
	{
		ft_printf("There are no input numbers.\n");
		exit(0);
	}
	s = (int*)malloc(sizeof(int) * argc);
	ft_bzero(s, argc);
	if (!s)
	{
		ft_printf("Failed to allocate memory.\n");
		exit(0);
	}
	return (s);
}

void	savestack(int argc, char **argv, int *s)
{
	int	it;
	int	jt;

	it = 0;
	jt = 1;
	while (jt < argc)
	{
		checknums(argv[jt], s);
		s[it] = ft_atoi(argv[jt], s);
		it++;
		jt++;
	}
}

void	argcheck(int *s, int argc)
{
	int	it;
	int	jt;

	it = 0;
	jt = 1;
	while (it < argc - 1)
	{
		while (jt < argc - 1)
		{
			if (s[it] == s[jt])
			{
				ft_printf("Some number(s) appear twice or more.\n");
				freestacks(s, 0);
			}
			jt++;
		}
		jt = (it + 2);
		it++;
	}
}
