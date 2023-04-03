/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderutils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:15:51 by aigarcia          #+#    #+#             */
/*   Updated: 2023/03/16 20:15:52 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

int	checkposition2(int *b, int *a, int *alen, int *blen)
{
	int	it;

	it = 1;
	while (it < *alen)
	{
		if (b[*blen - 1] < a[it] && b[*blen - 1] > a[it - 1])
			return (it);
		it++;
	}
	return (0);
}
