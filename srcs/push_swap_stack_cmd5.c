/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_cmd5.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:57:32 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/15 13:56:51 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_find_min_diff(t_stack *stk, int key, t_decs *decs_tab)
{
	t_node	*p_node;

	p_node = stk->top;
	while (p_node)
	{
		if (!ft_update_decs(decs_tab, key, p_node->content))
			decs_tab->depth++;
		p_node = p_node->prev;
	}
}

int	ft_update_decs(t_decs *decs_tab, int key, int node)
{
	int	new_diff;
	int isneg;

	new_diff = key - node;
	if (new_diff < 0)
	{
		new_diff *= -1;
		isneg = 1;
	}
	else
		isneg = 0;
	if (new_diff < decs_tab->min_diff || decs_tab->min_diff == 0)
	{
		decs_tab->min_diff = new_diff;
		decs_tab->isneg = isneg;
		return (0);
	}
	return (1);
}

void	ft_reset_decs(t_decs *decs_tab)
{
	decs_tab->depth = 0;
	decs_tab->isneg = 0;
	decs_tab->min_diff = 0;
}

void	ft_print_decs(t_decs *decs_tab)
{
	ft_printf("depth: %d\n", decs_tab->depth);
	ft_printf("min_diff: %d\n", decs_tab->min_diff);
	ft_printf("isneg: %d\n", decs_tab->isneg);
}
