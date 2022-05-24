/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_opr2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:08:49 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/24 09:03:03 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting_decision(t_stack *stk_a, t_stack *stk_b, t_decs *decs_tab)
{
	int	key;

	key = stk_b->top->content;
	if (decs_tab->depth < decs_tab->height)
	{
		decs_tab->depth--;
		if (decs_tab->depth)
			ft_stack_n_ra(stk_a, stk_b, decs_tab->depth);
		ft_stack_pa(stk_a, stk_b);
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
		ft_stack_pa(stk_a, stk_b);
		ft_stack_n_ra(stk_a, stk_b, decs_tab->height + 1);
	}
}

void	ft_3_rand_nums(t_stack *stk_a, t_stack *stk_b)
{
	int	mid;

	mid = stk_a->top->prev->content;
	if (mid < stk_a->top->content && mid < stk_a->bottom->content)
	{
		if (stk_a->top->content < stk_a->bottom->content)
			ft_stack_sa(stk_a, stk_b, 0);
		else
			ft_stack_ra(stk_a, stk_b, 0);
	}
	else if (mid > stk_a->top->content && mid > stk_a->bottom->content)
	{
		if (stk_a->top->content < stk_a->bottom->content)
		{
			ft_stack_sa(stk_a, stk_b, 0);
			ft_stack_ra(stk_a, stk_b, 0);
		}
		else
			ft_stack_rra(stk_a, stk_b, 0);
	}
	else if (mid < stk_a->top->content && mid > stk_a->bottom->content)
	{
		ft_stack_ra(stk_a, stk_b, 0);
		ft_stack_sa(stk_a, stk_b, 0);
	}
	else
	{
		ft_stack_sa(stk_a, stk_b, 0);
		ft_stack_rra(stk_a, stk_b, 0);
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
		// if (decs_top.depth < decs_bottom.depth)
		// 	ft_5_rand_decision(stk_a, stk_b, &decs_top);
		// else
		// 	ft_stack_rb(stk_a, stk_b, 0);
	}
}

void	ft_rand_nums(t_stack *stk_a, t_stack *stk_b)
{
	t_decs	decs;

	while (stk_b->stack_cnt > 0)
	{
		ft_reset_decs(&decs);
		ft_stack_find_min_diff(stk_a, stk_b->top->content, &decs);
		ft_sorting_decision(stk_a, stk_b, &decs);
	}
}

void	ft_5_rand_decision(t_stack *stk_a, t_stack *stk_b, t_decs *decs_tab)
{
	int	key;

	key = stk_b->top->content;
	if (decs_tab->depth <= decs_tab->height)
	{
		decs_tab->depth--;
		if (decs_tab->depth)
			ft_stack_n_ra(stk_a, stk_b, decs_tab->depth);
		ft_stack_pa(stk_a, stk_b);
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
		ft_stack_pa(stk_a, stk_b);
		ft_stack_n_ra(stk_a, stk_b, decs_tab->height + 1);
	}
}
