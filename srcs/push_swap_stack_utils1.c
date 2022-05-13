/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:32:01 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/13 16:19:29 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_arr_range(char **arr)
{
	int	len;

	len = 0;
	while (*arr)
	{
		len++;
		arr++;
	}
	return (len);
}

t_stack	*ft_stack_create(void)
{
	t_stack	*create_stack;

	create_stack = NULL;
	create_stack = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!create_stack)
		return (NULL);
	create_stack->bottom = NULL;
	create_stack->top = NULL;
	create_stack->stack_cnt = 0;
	return (create_stack);
}

void	ft_stacks_cleanup(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		stack_a->top = NULL;
		ft_clear_nodes(stack_a->bottom);
		stack_a->stack_cnt = 0;
		free(stack_a);
		stack_a = NULL;
	}
	if (stack_b)
	{
		stack_b->top = NULL;
		ft_clear_nodes(stack_b->bottom);
		stack_b->stack_cnt = 0;
		free(stack_b);
		stack_b = NULL;
	}
}

void	ft_clear_nodes(t_node *node)
{
	t_node	*p_node;
	t_node	*tmp_node;

	p_node = node;
	while (p_node)
	{
		tmp_node = p_node->next;
		p_node->content = 0;
		p_node->prev = NULL;
		p_node->next = NULL;
		if (p_node)
			free(p_node);
		p_node = tmp_node;
	}
}

void	ft_free_split(char **str_arr, int len)
{
	int	cnt;

	cnt = 0;
	while (cnt <= len)
	{
		free(str_arr[cnt++]);
	}
	free(str_arr);
}
