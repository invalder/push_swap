/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_cmd4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:47:31 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/15 11:02:36 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_issorted(t_stack *stk_a, t_stack *stk_b)
{
	t_node	*p_node;
	int		tmp;

	if (!stk_b->top && !stk_b->bottom && stk_b->stack_cnt == 0)
	{
		tmp = stk_a->top->content;
		p_node = stk_a->top->prev;
		while (p_node)
		{
			if (tmp > p_node->content)
				return (1);
			tmp = p_node->content;
			p_node = p_node->prev;
		}
		return (0);
	}
	return (1);
}

// 0 asc, 1 desc
int	ft_stack_issorted_single(t_stack *stk, int dir)
{
	t_node	*p_node;
	int		tmp;

	if (stk->top && stk->bottom && stk->stack_cnt >= 1)
	{
		if (stk->stack_cnt > 1)
		{
			tmp = stk->top->content;
			p_node = stk->top->prev;
			while (p_node)
			{
				if (dir)
					if (tmp < p_node->content)
						return (1);
				if (!dir)
					if (tmp > p_node->content)
						return (1);
				tmp = p_node->content;
				p_node = p_node->prev;
			}
		}
		return (0);
	}
	return (-1);
}

int	ft_stack_n_pa(t_stack *stk_a, t_stack *stk_b, int n)
{
	if (stk_b->stack_cnt >= n)
	{
		while (n > 0)
		{
			if (ft_stack_pa(stk_a, stk_b))
				ft_exit_stderr(stk_a, stk_b);
			n--;
		}
		return (0);
	}
	return (1);
}

int	ft_stack_n_pb(t_stack *stk_a, t_stack *stk_b, int n)
{
	if (stk_a->stack_cnt >= n)
	{
		while (n > 0)
		{
			if (ft_stack_pb(stk_a, stk_b))
				ft_exit_stderr(stk_a, stk_b);
			n--;
		}
		return (0);
	}
	return (1);
}
