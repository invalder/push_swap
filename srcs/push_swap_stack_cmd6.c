/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_cmd6.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:50:06 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/15 16:34:11 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_n_ra(t_stack *stk_a, t_stack *stk_b, int n)
{
	(void)stk_b;
	if (stk_a->top && stk_a->bottom && stk_a->stack_cnt > 1)
	{
		while (n > 0)
		{
			if (ft_stack_ra(stk_a, stk_b, 0))
				ft_exit_stderr(stk_a, stk_b);
			n--;
		}
		return (0);
	}
	return (1);
}

int	ft_stack_n_rb(t_stack *stk_a, t_stack *stk_b, int n)
{
	(void)stk_a;
	if (stk_b->top && stk_b->bottom && stk_b->stack_cnt > 1)
	{
		while (n > 0)
		{
			if (ft_stack_rb(stk_a, stk_b, 0))
				ft_exit_stderr(stk_a, stk_b);
			n--;
		}
		return (0);
	}
	return (1);
}

int	ft_stack_n_rra(t_stack *stk_a, t_stack *stk_b, int n)
{
	(void)stk_b;
	if (stk_a->top && stk_a->bottom && stk_a->stack_cnt > 1)
	{
		while (n > 0)
		{
			if (ft_stack_rra(stk_a, stk_b, 0))
				ft_exit_stderr(stk_a, stk_b);
			n--;
		}
		return (0);
	}
	return (1);
}

int	ft_stack_n_rrb(t_stack *stk_a, t_stack *stk_b, int n)
{
	(void)stk_a;
	if (stk_b->top && stk_b->bottom && stk_b->stack_cnt > 1)
	{
		while (n > 0)
		{
			if (ft_stack_rrb(stk_a, stk_b, 0))
				ft_exit_stderr(stk_a, stk_b);
			n--;
		}
		return (0);
	}
	return (1);
}
