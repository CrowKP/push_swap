/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:06:57 by aigarcia          #+#    #+#             */
/*   Updated: 2023/03/09 13:06:58 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	freestacks(int *a, int *b)
{
	if (a)
		free(a);
	if (b)
		free(b);
	exit(0);
}

void	freestacksatoi(int *s, int sign)
{
	if (sign == -1)
		ft_printf("One of the numbers is too small.\n");
	if (sign == 1)
		ft_printf("One of the numbers is too big.\n");
	if (s)
		free(s);
	exit(0);
}

void	swap(int *n1, int *n2)
{
	int	temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
