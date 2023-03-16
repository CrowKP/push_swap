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
	ordercheck(a, argc);
	b = dostack(argc);
	checklen(a, b, argc);
	ft_printf("Stack a:\n");
	while (it < argc - 1)
	{
		ft_printf("%d\n", a[it]);
		it++;
	}
	return (0);
}

int	*dostack(int argc)
{
	int	*s;

	s = NULL;
	if (argc < 2)
	{
		ft_printf("There are not enough numbers.\n");
		exit(0);
	}
	s = (int *)malloc(sizeof(int) * argc);
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

void	ordercheck(int *s, int argc)
{
	int	*t;
	int	it;
	int	len;

	it = 0;
	len = argc - 1;
	t = dostack(len);
	cpystack(t, s, &len);
	sortstack(t, &len);
	while (it < len)
	{
		if (s[it] != t[it])
			break ;
		it++;
	}
	if (s[it] == t[it])
	{
		ft_printf("The stack is already in order.\n");
		freestacks(s, t);
	}
	free(t);
}
