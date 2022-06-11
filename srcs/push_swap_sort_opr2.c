/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_opr2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:08:49 by nnakarac          #+#    #+#             */
/*   Updated: 2022/06/12 00:58:23 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_3_ra_decision(t_stack *stk_a, t_stack *stk_b);
static void	ft_3_rra_decision(t_stack *stk_a, t_stack *stk_b);

void	ft_3_rand_nums(t_stack *stk_a, t_stack *stk_b)
{
	int	mid;

	mid = stk_a->top->prev->content;
	if (mid < stk_a->top->content && mid < stk_a->bottom->content)
	{
		if (stk_a->top->content < stk_a->bottom->content)
			ft_stack_sa(stk_a, stk_b, 0);
		else
			ft_3_ra_decision(stk_a, stk_b);
	}
	else if (mid > stk_a->top->content && mid > stk_a->bottom->content)
	{
		if (stk_a->top->content < stk_a->bottom->content)
		{
			ft_stack_sa(stk_a, stk_b, 0);
			ft_3_ra_decision(stk_a, stk_b);
		}
		else
			ft_3_rra_decision(stk_a, stk_b);
	}
	else if (mid < stk_a->top->content && mid > stk_a->bottom->content)
	{
		ft_stack_sa(stk_a, stk_b, 0);
		ft_3_rra_decision(stk_a, stk_b);
	}
}

void	ft_5_rand_nums(t_stack *stk_a, t_stack *stk_b)
{
	t_decs	decs_top;

	while (stk_b->stack_cnt > 0)
	{
		ft_reset_decs(&decs_top);
		ft_stack_find_min_diff(stk_a, stk_b->top->content, &decs_top);
		ft_5_rand_decision(stk_a, stk_b, &decs_top);
	}
}

void	ft_5_rand_decision(t_stack *stk_a, t_stack *stk_b, t_decs *decs_tab)
{
	int	key;

	key = stk_b->top->content;
	if (decs_tab->depth <= decs_tab->height
		|| decs_tab->depth - 1 == decs_tab->height)
	{
		decs_tab->depth--;
		if (decs_tab->depth)
			ft_stack_n_ra(stk_a, stk_b, decs_tab->depth);
		ft_stack_pa(stk_a, stk_b, 0);
		if (key > stk_a->top->prev->content)
			ft_stack_sa(stk_a, stk_b, 0);
		if (decs_tab->depth)
			ft_stack_n_rra(stk_a, stk_b, decs_tab->depth);
	}
	else
	{
		if (!decs_tab->height_isneg)
			decs_tab->height--;
		if (decs_tab->height)
			ft_stack_n_rra(stk_a, stk_b, decs_tab->height);
		ft_stack_pa(stk_a, stk_b, 0);
		ft_stack_n_ra(stk_a, stk_b, decs_tab->height + 1);
	}
}

static void	ft_3_ra_decision(t_stack *stk_a, t_stack *stk_b)
{
	if (stk_b->stack_cnt)
	{
		if (stk_b->top->content < stk_b->bottom->content)
			ft_stack_rr(stk_a, stk_b, 0);
		else
			ft_stack_ra(stk_a, stk_b, 0);
	}
	else
		ft_stack_ra(stk_a, stk_b, 0);
}

static void	ft_3_rra_decision(t_stack *stk_a, t_stack *stk_b)
{
	if (stk_b->stack_cnt)
	{
		if (stk_b->top->content < stk_b->bottom->content)
			ft_stack_rrr(stk_a, stk_b, 0);
		else
			ft_stack_rra(stk_a, stk_b, 0);
	}
	else
		ft_stack_rra(stk_a, stk_b, 0);
}
