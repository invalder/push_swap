/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_cmd1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 02:51:09 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/09 11:17:13 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_sa(t_stack *stk_a, t_stack *stk_b)
{
	t_node	*node_a;
	t_node	*node_b;

	(void)stk_b;
	if (stk_a->bottom && stk_a->top && stk_a->stack_cnt > 1)
	{
		node_a = ft_stack_pop(stk_a);
		node_b = ft_stack_pop(stk_a);
		ft_stack_push_node(stk_a, node_a);
		ft_stack_push_node(stk_a, node_b);
		return (0);
	}
	return (1);
}

int	ft_stack_sb(t_stack *stk_a, t_stack *stk_b)
{
	t_node	*node_a;
	t_node	*node_b;

	(void)stk_a;
	if (stk_b->bottom && stk_b->top && stk_b->stack_cnt > 1)
	{
		node_a = ft_stack_pop(stk_b);
		node_b = ft_stack_pop(stk_b);
		ft_stack_push_node(stk_b, node_a);
		ft_stack_push_node(stk_b, node_b);
		return (0);
	}
	return (1);
}
