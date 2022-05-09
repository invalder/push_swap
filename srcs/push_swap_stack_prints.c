/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_prints.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:25:05 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/07 00:59:17 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_stack_pnt_sub(int stk_max, t_stack *stk_a, t_stack *stk_b);
static t_node	*ft_stack_pnt_a(int stk_max, t_stack *stk_a, t_node *ptr_node);
static t_node	*ft_stack_pnt_b(int stk_max, t_stack *stk_b, t_node *ptr_node);

void	ft_stack_print(t_stack *stk)
{
	t_node	*ptr_node;

	if (stk->top && stk->bottom)
	{
		ptr_node = stk->top;
		while (ptr_node)
		{
			printf("stack: %d\n", ptr_node->content);
			ptr_node = ptr_node->prev;
		}
	}
}

void	ft_stack_print_all(t_stack *stk_a, t_stack *stk_b)
{
	int		stack_max;

	stack_max = 0;
	if (stk_a->stack_cnt > stk_b->stack_cnt)
		stack_max = stk_a->stack_cnt;
	else
		stack_max = stk_b->stack_cnt;
	ft_stack_pnt_sub(stack_max, stk_a, stk_b);
}

static void	ft_stack_pnt_sub(int stk_max, t_stack *stk_a, t_stack *stk_b)
{
	t_node	*ptr_node_a;
	t_node	*ptr_node_b;

	ptr_node_a = stk_a->top;
	ptr_node_b = stk_b->top;
	while (stk_max > 0)
	{
		ptr_node_a = ft_stack_pnt_a(stk_max, stk_a, ptr_node_a);
		ptr_node_b = ft_stack_pnt_b(stk_max, stk_b, ptr_node_b);
		stk_max--;
	}
	ft_printf("_________________________________\n");
}

static t_node	*ft_stack_pnt_a(int stk_max, t_stack *stk_a, t_node *ptr_node)
{
	if (stk_a)
	{
		if (stk_a->stack_cnt >= stk_max)
		{
			ft_printf("|\t%03d\t|", ptr_node->content);
			ptr_node = ptr_node->prev;
		}
		else
			ft_printf("|\t\t|\t");
	}
	return (ptr_node);
}

static t_node	*ft_stack_pnt_b(int stk_max, t_stack *stk_b, t_node *ptr_node)
{
	if (stk_b)
	{
		if (stk_b->stack_cnt >= stk_max)
		{
			ft_printf("\t%03d\t|\n", ptr_node->content);
			ptr_node = ptr_node->prev;
		}
		else
			ft_printf("\t\t|\n");
	}
	return (ptr_node);
}
