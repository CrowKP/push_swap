/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:25:20 by aigarcia          #+#    #+#             */
/*   Updated: 2023/01/31 18:25:21 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		*dostack(int argc);
int		main(int argc, char *argv[]);
void	swapprint(int *a, int *b);
int		*swapnumber(int *a);
void	push(int *src, int *dst);
int		*rotate(int *s);
void	rotateprint(int *a, int *b);
int		stacklen(int *s);
void	revrotprint(int *a, int *b);
int		*revrot(int *s);
void	savestack(int argc, char *argv[], int *s);

#endif
