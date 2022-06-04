/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_opr5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:55:15 by nnakarac          #+#    #+#             */
/*   Updated: 2022/06/04 11:54:52 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_chunks_push(t_stack *stk_a, t_stack *stk_b, t_decs *decs, int chk)
{
	int	mid;

	mid = (stk_a->max_chnks[chk] + stk_a->min_chnks[chk]) / 2;
	if (decs->depth <= decs->height)
	{
		if (stk_a->stack_cnt > 1)
			decs->depth--;
		ft_stack_n_ra(stk_a, stk_b, decs->depth);
	}
	else
		ft_stack_n_rra(stk_a, stk_b, decs->height);
	ft_stack_pb(stk_a, stk_b);
	if (stk_b->top->content <= mid)
	{
		ft_find_hold_positions(stk_a, decs, chk);
		if (decs->depth <= decs->height && decs->depth > 1)
			ft_stack_rr(stk_a, stk_b);
		else
			ft_stack_rb(stk_a, stk_b, 0);
	}
}

void	ft_find_positions(t_stack *stk_b, t_decs *decs_tab, int val)
{
	ft_reset_decs(decs_tab);
	ft_find_position_down(stk_b, decs_tab, val);
	ft_find_position_up(stk_b, decs_tab, val);
}

void	ft_find_position_down(t_stack *stk_b, t_decs *decs_tab, int val)
{
	t_node	*down;

	down = stk_b->top;
	while (down)
	{
		decs_tab->depth++;
		decs_tab->depth_min = down->content;
		if (down->content == val)
		{
			decs_tab->depth_min = down->content;
			break ;
		}
		down = down->prev;
	}
}

void	ft_find_position_up(t_stack *stk_b, t_decs *decs_tab, int val)
{
	t_node	*up;

	up = stk_b->bottom;
	while (up)
	{
		decs_tab->height++;
		decs_tab->height_min = up->content;
		if (up->content == val)
		{
			decs_tab->height_min = up->content;
			break ;
		}
		up = up->next;
	}
}

void	ft_chunks_pull(t_stack *stk_a, t_stack *stk_b, t_decs *decs, int val)
{
	if (decs->depth <= decs->height)
	{
		if (decs->depth_min == val)
		{
			ft_stack_n_rb(stk_a, stk_b, decs->depth - 1);
			ft_stack_pa(stk_a, stk_b);
		}
	}
	else
	{
		if (decs->height_min == val)
		{
			ft_stack_n_rrb(stk_a, stk_b, decs->height);
			ft_stack_pa(stk_a, stk_b);
		}
	}
	ft_reset_decs(decs);
}
