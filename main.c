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
	int	it;

	it = 0;
	b = dostack(argc);
	a = dostack(argc);
	savestack(argc, argv, a);
	return (0);
}
