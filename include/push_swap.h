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
void	sp(int *a, int *b, int *alen, int *blen);
int		*swapnumber(int *a, int *len);
void	push(int *src, int *dst, int *slen, int *dlen);
int		*rotate(int *s, int *len);
void	rtp(int *a, int *b, int *alen, int *blen);
void	rrtp(int *a, int *b, int *alen, int *blen);
int		*revrot(int *s, int *len);
void	savestack(int argc, char *argv[], int *s);
void	pa(int *src, int *dst, int *slen, int *dlen);
void	pb(int *src, int *dst, int *slen, int *dlen);
void	argcheck(int *s, int argc);
void	freestacks(int *a, int *b);
void	freestacksatoi(int *s, int sign);
void	checknums(char *argv, int *s);
void	checklen(int *a, int *b, int argc);
void	index3(int *a, int *len);
void	index5(int *a, int *b, int *alen, int *blen);
void	swaperror(int *a, int *b);
void	roterror(int *a, int *b);
int		checksmall(int *a, int *len);
void	movenum(int *a, int *b, int *alen, int *blen);
void	movenum2(int *a, int *b, int *alen, int *blen);
void	movenum3(int *a, int *b, int *alen, int *blen);
void	movenum4(int *a, int *b, int *alen, int *blen);
int		checkbig(int *a, int *len);
void	index100(int *a, int *b, int *alen, int *blen);
void	cpystack(int *t, int *a, int *len);
void	sortstack(int *t, int *len);
void	swap(int *n1, int *n2);
void	easystack(int *a, int *t, int *len);
void	movesmall(int *a, int *b, int *alen, int *blen);
void	index4(int *a, int *b, int *alen, int *blen);
void	ordercheck(int *s, int argc);
void	ordersmall(int *a, int *b, int *alen, int *blen);
void	orderit(int *a, int *b, int *alen, int *blen);
int		rotstack(int *a, int *alen, int check, int hold);
int		checkposition(int *b, int *a, int *alen);
void	finalpush(int *a, int *b, int *alen, int *blen);
void	index500(int *a, int *b, int *alen, int *blen);
void	order500(int *a, int *b, int *alen, int *blen);
void	rotb500(int *b, int *blen);
void	finalpush500(int *a, int *b, int *alen, int *blen);
void	pushstack(int *a, int *b, int *alen, int *blen);
int		checkposition2(int *b, int *a, int *alen, int *blen);
int		pushpos(int *a, int *b, int *alen, int *blen);
void	pushbup(int *a, int *b, int *alen, int *blen);
void	pushbdown(int *a, int *b, int *alen, int *blen);
int		checkposdyn(int b, int *a, int *alen);
int		checkposta(int b, int *a, int *alen);
int		posmodup(int *a, int b, int *alen, int it);
int		posmodown(int *a, int b, int *alen, int it);
int		rotstack500(int *a, int *alen, int check, int hold);
void	rota(int *a, int *b, int *alen, int *blen);

#endif
