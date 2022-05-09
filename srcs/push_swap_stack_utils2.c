/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:19:40 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/10 02:50:20 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_push(t_stack *stk, int content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node) * 1);
	if (!new_node)
		return (-1);
	new_node->content = content;
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

int	ft_stack_appendlast(t_stack *stk, int content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node) * 1);
	if (!new_node)
		return (-1);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (stk->top && stk->bottom)
	{
		stk->bottom->prev = new_node;
		new_node->next = stk->bottom;
		stk->bottom = new_node;
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

t_node	*ft_stack_pop(t_stack *stk)
{
	t_node	*ret_node;

	if (stk->top && stk->bottom && stk->stack_cnt > 0)
	{
		ret_node = stk->top;
		stk->top = stk->top->prev;
		stk->top->next = NULL;
		stk->stack_cnt--;
		return (ret_node);
	}
	return (NULL);
}

int	ft_stack_rot(t_stack *stk)
{
	if (stk->top && stk->bottom && stk->stack_cnt > 1)
	{
		stk->top->next = stk->bottom;
		stk->bottom->prev = stk->top;
		stk->top = stk->top->prev;
		stk->bottom = stk->bottom->prev;
		stk->top->next = NULL;
		stk->bottom->prev = NULL;
		return (0);
	}
	return (1);
}

int	ft_stack_rev_rot(t_stack *stk)
{
	if (stk->top && stk->bottom && stk->stack_cnt > 1)
	{
		stk->top->next = stk->bottom;
		stk->bottom->prev = stk->top;
		stk->top = stk->top->next;
		stk->bottom = stk->bottom->next;
		stk->top->next = NULL;
		stk->bottom->prev = NULL;
		return (0);
	}
	return (1);
}
