/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_opr2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:08:49 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/15 17:08:21 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting_decision(t_stack *stk_a, t_stack *stk_b, t_decs *decs_tab)
{
	if (decs_tab->depth && decs_tab->depth >= 1)
	{
		if (decs_tab->depth && decs_tab->depth > 1)
		{
			if (stk_a->stack_cnt - decs_tab->depth < decs_tab->depth)
				ft_stack_n_rra(stk_a, stk_b, stk_a->stack_cnt - decs_tab->depth);
			else
				ft_stack_n_ra(stk_a, stk_b, decs_tab->depth);
		}
		ft_stack_pa(stk_a, stk_b);
		// if (stk_a->top->content < stk_a->top->prev->content)
		// 	ft_stack_sa(stk_a, stk_b, 0);
	}
}
