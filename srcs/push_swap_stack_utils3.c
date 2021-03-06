/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:08:44 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/10 01:48:33 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_push_node(t_stack *stk, t_node *new_node)
{
	if (!new_node)
		return (-1);
	new_node->next = NULL;
	new_node->prev = NULL;
	if (stk->top && stk->bottom)
	{
		stk->top->next = new_node;
		new_node->prev = stk->top;
		stk->top = new_node;
		stk->stack_cnt++;
	}
	else
	{
		stk->top = new_node;
		stk->bottom = new_node;
		stk->stack_cnt++;
	}
	return (0);
}
