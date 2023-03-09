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
# include <limits.h>

int		*dostack(int argc);
int		main(int argc, char *argv[]);
void	sp(int *a, int *b);
int		*swapnumber(int *a);
void	push(int *src, int *dst);
int		*rotate(int *s);
void	rtp(int *a, int *b);
int		stacklen(int *s);
void	rrtp(int *a, int *b);
int		*revrot(int *s);
int		*savestack(int argc, char *argv[], int *s);
void	pp(int *src, int *dst, int check);
void	argcheck(int *s);
void	freestacks(int *a, int *b);
void	freestacksatoi(int *s, int sign);
void	checknums(char *argv, int *s);
void	checklen(int *a, int *b);
void	index3(int *a);
void	index5(int *a, int *b);
void	swaperror(int *a, int *b);
void	roterror(int *a, int *b);
int		checksmall(int *a);
void	movenum(int *a, int *b, int ns, int nb);
void	movenum2(int *a, int *b, int ns, int nb);
void	movenum3(int *a, int *b, int ns, int nb);
void	movenum4(int *a, int *b, int ns, int nb);
int		checkbig(int *a);

#endif
