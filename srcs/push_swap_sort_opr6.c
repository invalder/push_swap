/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_opr6.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 01:12:07 by nnakarac          #+#    #+#             */
/*   Updated: 2022/06/12 05:26:06 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_min_push(t_stack *stk_a, t_stack *stk_b, t_decs *decs_min);

void	ft_find_min_push(t_stack *stk_a, t_stack *stk_b)
{
	t_decs	decs_min;
	t_node	*p_node;
	int		min;

	(void)stk_b;
	p_node = stk_a->top->prev;
	min = stk_a->top->content;
	ft_reset_decs(&decs_min);
	while (p_node)
	{
		if (p_node->content < min)
			min = p_node->content;
		p_node = p_node->prev;
	}
	ft_find_positions(stk_a, &decs_min, min);
	ft_min_push(stk_a, stk_b, &decs_min);
}

static void	ft_min_push(t_stack *stk_a, t_stack *stk_b, t_decs *decs_min)
{
	if (decs_min->depth <= decs_min->height)
	{
		decs_min->depth--;
		ft_stack_n_ra(stk_a, stk_b, decs_min->depth);
		ft_stack_pb(stk_a, stk_b, 0);
	}
	else
	{
		ft_stack_n_rra(stk_a, stk_b, decs_min->height);
		ft_stack_pb(stk_a, stk_b, 0);
	}
}
