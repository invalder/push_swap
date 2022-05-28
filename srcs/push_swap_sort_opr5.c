/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_opr5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:55:15 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/29 01:04:23 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_chunks_push(t_stack *stk_a, t_stack *stk_b, t_decs *decs, int chk)
{
	int	mid;

	mid = (stk_a->max_chnks[chk] + stk_a->min_chnks[chk]) / 2;
	// use top
	if (decs->depth <= decs->height)
	{
		ft_stack_n_ra(stk_a, stk_b, decs->depth - 1);
		ft_stack_pb(stk_a, stk_b);
		if (stk_b->top->content <= mid)
			ft_stack_rb(stk_a, stk_b, 0);
		else if (stk_b->top->prev &&
			stk_b->top->content <= stk_b->top->prev->content)
			ft_stack_sb(stk_a, stk_b, 0);
		// ft_stack_n_rra(stk_a, stk_b, (decs->depth - 1) / 2);
	}
	// use height
	else
	{
		ft_stack_n_rra(stk_a, stk_b, decs->height);
		ft_stack_pb(stk_a, stk_b);
		if (stk_b->top->content <= mid)
			ft_stack_rb(stk_a, stk_b, 0);
		else if (stk_b->top->prev &&
			stk_b->top->content <= stk_b->top->prev->content)
			ft_stack_sb(stk_a, stk_b, 0);
		// ft_stack_n_rra(stk_a, stk_b, (decs->height) / 2);
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
	// use top
	if (decs->depth <= decs->height)
	{
		if (decs->depth_min == val)
		{
			ft_stack_n_rb(stk_a, stk_b, decs->depth - 1);
			ft_stack_pa(stk_a, stk_b);
			// ft_stack_n_rrb(stk_a, stk_b, decs->depth - 2);
		}
		// ft_stack_n_ra(stk_a, stk_b, decs->depth - 1);
		// ft_stack_pb(stk_a, stk_b);
		// if (stk_b->top->content <= mid)
		// 	ft_stack_rb(stk_a, stk_b, 0);
	}
	// use height
	else
	{
		if (decs->height_min == val)
		{
			ft_stack_n_rrb(stk_a, stk_b, decs->height);
			ft_stack_pa(stk_a, stk_b);
			// ft_stack_n_rb(stk_a, stk_b, decs->height - 1);
		}
		// ft_stack_n_rra(stk_a, stk_b, decs->depth);
		// ft_stack_pb(stk_a, stk_b);
		// if (stk_b->top->content <= mid)
		// 	ft_stack_rb(stk_a, stk_b, 0);
	}
}
