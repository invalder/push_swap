/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_opr3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:46:58 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/29 22:30:23 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_chunk_calculator(t_stack *stk_a, t_stack *stk_b, long *samples)
{
	(void) stk_b;
	if (stk_a->stack_cnt >= 500)
		stk_a->nchunks = 9;
	else if (stk_a->stack_cnt >= 100)
		stk_a->nchunks = 5;
	else
		stk_a->nchunks = 5;
	ft_chunks_alloc(stk_a, stk_b, samples);
	ft_chunks_assign(stk_a, stk_b, samples);
	ft_print_samples(samples, stk_a->stack_cnt);

	ft_100_plus_sorting(stk_a, stk_b);
	ft_chunks_cleanup(stk_a, stk_b, samples);
}

void	ft_chunks_alloc(t_stack *stk_a, t_stack *stk_b, long *samples)
{
	(void) stk_b;
	if (stk_a->nchunks)
	{
		stk_a->max_chnks = (int *)malloc(sizeof(int) * stk_a->nchunks);
		stk_a->min_chnks = (int *)malloc(sizeof(int) * stk_a->nchunks);
		ft_chunks_validate(stk_a, stk_b, samples);
	}
}

void	ft_chunks_validate(t_stack *stk_a, t_stack *stk_b, long *samples)
{
	if (!stk_a->min_chnks || !stk_a->max_chnks)
	{
		ft_chunks_cleanup(stk_a, stk_b, samples);
		ft_stacks_cleanup(stk_a, stk_b);
		exit(1);
	}
}

void	ft_chunks_cleanup(t_stack *stk_a, t_stack *stk_b, long *samples)
{
	if (stk_a->min_chnks)
	{
		free(stk_a->min_chnks);
		stk_a->min_chnks = NULL;
	}
	if (stk_a->max_chnks)
	{
		free(stk_a->max_chnks);
		stk_a->max_chnks = NULL;
	}
	if (samples)
		free(samples);
	samples = NULL;
	stk_a->nchunks = 0;
	stk_b->nchunks = 0;
}

void	ft_chunks_assign(t_stack *stk_a, t_stack *stk_b, long *samples)
{
	int	nchk;
	int	chklen;
	int	cnt;

	(void)stk_b;
	cnt = 0;
	nchk = stk_a->nchunks;
	chklen = stk_a->stack_cnt / nchk;
	while (cnt < nchk)
	{
		stk_a->min_chnks[cnt] = (int)samples[cnt * chklen];
		stk_a->max_chnks[cnt] = (int)samples[(cnt * chklen) + chklen - 1];
		if (cnt == nchk - 1)
			stk_a->max_chnks[cnt] = (int)samples[stk_a->stack_cnt - 1];
		cnt++;
	}
	cnt = 0;
	while (cnt < nchk)
	{
		ft_printf("cnt: %d\t min: %d\t max: %d\n", cnt, stk_a->min_chnks[cnt], stk_a->max_chnks[cnt]);
		cnt++;
	}
}
