/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_cmd5.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:57:32 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/23 18:00:10 by nnakarac         ###   ########.fr       */
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
	p_node = stk->bottom;
	while (p_node)
	{
		if (!ft_update_decs_up(decs_tab, key, p_node->content))
			decs_tab->height++;
		p_node = p_node->next;
	}
}

int	ft_update_decs(t_decs *decs_tab, int key, int node)
{
	int	new_diff;
	int	isneg;

	new_diff = key - node;
	if (new_diff < 0)
	{
		new_diff *= -1;
		isneg = 1;
	}
	else
		isneg = 0;
	if (new_diff < decs_tab->depth_min || decs_tab->depth_min == 0)
	{
		decs_tab->depth_min = new_diff;
		decs_tab->depth_isneg = isneg;
		return (0);
	}
	return (1);
}

int	ft_update_decs_up(t_decs *decs_tab, int key, int node)
{
	int	new_diff;
	int	isneg;

	new_diff = key - node;
	if (new_diff < 0)
	{
		new_diff *= -1;
		isneg = 1;
	}
	else
		isneg = 0;
	if (new_diff < decs_tab->height_min || decs_tab->height_min == 0)
	{
		decs_tab->height_min = new_diff;
		decs_tab->height_isneg = isneg;
		return (0);
	}
	return (1);
}

void	ft_reset_decs(t_decs *decs_tab)
{
	decs_tab->depth = 0;
	decs_tab->depth_isneg = 0;
	decs_tab->depth_min = 0;
	decs_tab->height = 0;
	decs_tab->height_isneg = 0;
	decs_tab->height_min = 0;
}

void	ft_print_decs(t_decs *decs_tab)
{
	ft_printf("depth: %d\n", decs_tab->depth);
	ft_printf("depth_min: %d\n", decs_tab->depth_min);
	ft_printf("depth_isneg: %d\n", decs_tab->depth_isneg);
	ft_printf("height: %d\n", decs_tab->height);
	ft_printf("height_min: %d\n", decs_tab->height_min);
	ft_printf("height_isneg: %d\n", decs_tab->height_isneg);
}
