/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_cmd7.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:24:38 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/15 16:27:41 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_n_rr(t_stack *stk_a, t_stack *stk_b, int n)
{
	if (stk_a->top && stk_a->bottom && stk_a->stack_cnt > 1
		&& stk_b->top && stk_b->bottom && stk_b->stack_cnt > 1)
	{
		while (n > 0)
		{
			if (ft_stack_rr(stk_a, stk_b))
				ft_exit_stderr(stk_a, stk_b);
			n--;
		}
		return (0);
	}
	return (1);
}

int	ft_stack_n_rrr(t_stack *stk_a, t_stack *stk_b, int n)
{
	if (stk_a->top && stk_a->bottom && stk_a->stack_cnt > 1
		&& stk_b->top && stk_b->bottom && stk_b->stack_cnt > 1)
	{
		while (n > 0)
		{
			if (ft_stack_rrr(stk_a, stk_b))
				ft_exit_stderr(stk_a, stk_b);
			n--;
		}
		return (0);
	}
	return (1);
}
