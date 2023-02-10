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
	int it = 0;

	a = dostack(argc);
	a = savestack(argc, argv, a);
	argcheck(a);
	b = dostack(argc);
	checklen(a, b);
	while (a[it])
	{
		ft_printf("%d\n", a[it]);
		it++;
	}
	return (0);
}

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
		ft_printf("There are no input numbers.\n");
		exit(0);
	}
	s = malloc((argc - 1) * sizeof * s);
	if (!s)
	{
		ft_printf("Failed to allocate memory.\n");
		exit(0);
	}
	return (s);
}

int	*savestack(int argc, char **argv, int *s)
{
	int	it;
	int	jt;

	it = 0;
	jt = 1;
	while (argc > jt)
	{
		checknums(argv[jt], s);
		s[it] = ft_atoi(argv[jt], s);
		it++;
		jt++;
	}
	return (s);
}

void	argcheck(int *s)
{
	int	it;
	int	jt;

	it = 0;
	jt = 1;
	while (s[it])
	{
		while (s[jt])
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
