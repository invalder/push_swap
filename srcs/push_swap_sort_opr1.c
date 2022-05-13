/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_opr1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:40:35 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/14 02:51:57 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if stack sort perfectly

void	ft_sorting_opr(t_stack *stk_a, t_stack *stk_b)
{
	int		swap; //0: nothing, 1: sa, 2: sb, 3: ss

	swap = 0;
	ft_stack_stats_all(stk_a, stk_b);
	// ft_printf("sorted = %d\n", ft_stack_issorted(stk_a, stk_b));
	// ft_stack_n_pb(stk_a, stk_b, (stk_a->stack_cnt + 1) / 2);
	// ft_stack_stats_all(stk_a, stk_b);
	// ft_stack_print_all(stk_a, stk_b);
	if (ft_stack_issorted(stk_a, stk_b))
		ft_stack_n_pb(stk_a, stk_b, (stk_a->stack_cnt + 1) / 2);
	while (ft_stack_issorted(stk_a, stk_b))
	{
		// if (stk_b->top->content < stk_a->top->content)
		// {
		// 	ft_stack_pa(stk_a, stk_b);
		// 	ft_stack_ra(stk_a, stk_b, 0);
		// }
		// else
		// {
		// 	ft_stack_rb(stk_a, stk_b, 0);
		// }
		// check stack a asc
		if (int	ft_stack_issorted_single(stk_a, 0))
		{

		}
		// check stack b desc
		if (int	ft_stack_issorted_single(stk_b, 1))
		{
			if (stk_b->top->content < stk_b->top->prev->content)
				ft_stack_sb(stk_a, stk_b, 0);
		}
		sleep(2);
		ft_stack_stats_all(stk_a, stk_b);
		ft_stack_print_all(stk_a, stk_b);
	}
	ft_stack_print_all(stk_a, stk_b);
}

void	ft_stack_stats_all(t_stack *stk_a, t_stack *stk_b)
{
	if (stk_a->bottom && stk_a->top && stk_a->stack_cnt)
		ft_stack_stats(stk_a);
	if (stk_b->bottom && stk_b->top && stk_b->stack_cnt)
		ft_stack_stats(stk_b);
}

void	ft_stack_stats(t_stack *stk)
{
	ft_stack_find_min(stk);
	ft_stack_find_max(stk);
}

void	ft_stack_find_min(t_stack *stk)
{
	int		min_b;
	int		min_t;
	int		loop;
	t_node	*p_node_b;
	t_node	*p_node_t;

	loop = 0;
	min_b = stk->bottom->content;
	min_t = stk->top->content;
	p_node_b = stk->bottom;
	p_node_t = stk->top;
	while (loop < (stk->stack_cnt + 1) / 2)
	{
		if (p_node_b->content <= min_b)
			min_b = p_node_b->content;
		if (p_node_t->content <= min_t)
			min_t = p_node_t->content;
		p_node_b = p_node_b->next;
		p_node_t = p_node_t->prev;
		loop++;
	}
	if (min_b <= min_t)
		stk->min = min_b;
	else
		stk->min = min_t;
}

void	ft_stack_find_max(t_stack *stk)
{
	int		max_b;
	int		max_t;
	int		loop;
	t_node	*p_node_b;
	t_node	*p_node_t;

	loop = 0;
	max_b = stk->bottom->content;
	max_t = stk->top->content;
	p_node_b = stk->bottom;
	p_node_t = stk->top;
	while (loop < (stk->stack_cnt + 1) / 2)
	{
		if (p_node_b->content >= max_b)
			max_b = p_node_b->content;
		if (p_node_t->content >= max_t)
			max_t = p_node_t->content;
		p_node_b = p_node_b->next;
		p_node_t = p_node_t->prev;
		loop++;
	}
	if (max_b >= max_t)
		stk->max = max_b;
	else
		stk->max = max_t;
}
