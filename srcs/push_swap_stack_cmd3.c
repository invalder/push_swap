/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_cmd3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:32:03 by nnakarac          #+#    #+#             */
/*   Updated: 2022/06/06 10:19:24 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_rra(t_stack *stk_a, t_stack *stk_b, int iscalled)
{
	(void)stk_b;
	if (stk_a->top && stk_a->bottom && stk_a->stack_cnt > 1)
	{
		ft_stack_rev_rot(stk_a);
		if (!iscalled)
			ft_printf("rra\n");
		return (0);
	}
	return (1);
}

int	ft_stack_rrb(t_stack *stk_a, t_stack *stk_b, int iscalled)
{
	(void)stk_a;
	if (stk_b->top && stk_b->bottom && stk_b->stack_cnt > 1)
	{
		ft_stack_rev_rot(stk_b);
		if (!iscalled)
			ft_printf("rrb\n");
		return (0);
	}
	return (1);
}

int	ft_stack_rrr(t_stack *stk_a, t_stack *stk_b, int iscalled)
{
	if (stk_a->top && stk_a->bottom && stk_a->stack_cnt > 1
		&& stk_b->top && stk_b->bottom && stk_b->stack_cnt > 1)
	{
		ft_stack_rra(stk_a, stk_b, 1);
		ft_stack_rrb(stk_a, stk_b, 1);
		if (!iscalled)
			ft_printf("rrr\n");
		return (0);
	}
	return (1);
}
