/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_cmd2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:39:42 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/09 15:12:48 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_pa(t_stack *stk_a, t_stack *stk_b)
{
	t_node	*pop_node;

	if (stk_b->top && stk_b->bottom && stk_b->stack_cnt > 0)
	{
		pop_node = ft_stack_pop(stk_b);
		ft_stack_push_node(stk_a, pop_node);
		ft_printf("pa\n");
		return (0);
	}
	return (1);
}

int	ft_stack_pb(t_stack *stk_a, t_stack *stk_b)
{
	t_node	*pop_node;

	if (stk_a->top && stk_a->bottom && stk_a->stack_cnt > 0)
	{
		pop_node = ft_stack_pop(stk_a);
		ft_stack_push_node(stk_b, pop_node);
		ft_printf("pb\n");
		return (0);
	}
	return (1);
}

int	ft_stack_ra(t_stack *stk_a, t_stack *stk_b, int iscalled)
{
	(void)stk_b;
	if (stk_a->top && stk_a->bottom && stk_a->stack_cnt > 1)
	{
		ft_stack_rot(stk_a);
		if (!iscalled)
			ft_printf("ra\n");
		return (0);
	}
	return (1);
}

int	ft_stack_rb(t_stack *stk_a, t_stack *stk_b, int iscalled)
{
	(void)stk_a;
	if (stk_b->top && stk_b->bottom && stk_b->stack_cnt > 1)
	{
		ft_stack_rot(stk_b);
		if (!iscalled)
			ft_printf("ra\n");
		return (0);
	}
	return (1);
}

int	ft_stack_rr(t_stack *stk_a, t_stack *stk_b)
{
	if (stk_a->top && stk_a->bottom && stk_a->stack_cnt > 1
		&& stk_b->top && stk_b->bottom && stk_b->stack_cnt > 1)
	{
		ft_stack_ra(stk_a, stk_b, 1);
		ft_stack_rb(stk_a, stk_b, 1);
		ft_printf("rr\n");
		return (0);
	}
	return (1);
}
