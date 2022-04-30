/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:25:31 by nnakarac          #+#    #+#             */
/*   Updated: 2022/04/30 16:56:13 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_arr_range(char **arr);
t_stack	*ft_create_stack();
void	ft_cleanup_stacks(t_stack *stack_a, t_stack *stack_b);
void	ft_clear_nodes(t_node *node);
void	ft_free_split(char **str_arr, int len);

int	main(int argc, char **argv)
{
	char	**str_arr;
	int		arr_len;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_create_stack();
	if (!stack_a)
		ft_cleanup_stacks(stack_a, stack_b);
	stack_b = ft_create_stack();
	if (!stack_b)
		ft_cleanup_stacks(stack_a, stack_b);
	if (argc < 2)
	{
		ft_printf("./push_swap args...\n");
		exit(1);
	}
	// Receive form file
	else if (argc == 2)
	{
		str_arr = ft_split(argv[1], ' ');
		arr_len = ft_arr_range(str_arr);
		ft_printf("arr_len: %d\n", arr_len);
		while (*str_arr)
		{
			// printf("str: %s\t", *str_arr++);
			// put to stack
		}
		ft_cleanup_stacks(stack_a, stack_b);
		ft_free_split(str_arr, arr_len);
	}
	else
	{
		exit(0);
	}
}

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

t_stack	*ft_create_stack()
{
	t_stack	*create_stack;

	create_stack = NULL;
	create_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!create_stack)
		return (NULL);
	create_stack->bottom = NULL;
	create_stack->top = NULL;
	return (create_stack);
}

void	ft_cleanup_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		stack_a->top = NULL;
		ft_clear_nodes(stack_a->bottom);
		free(stack_a);
	}
	if (stack_b)
	{
		stack_b->top = NULL;
		ft_clear_nodes(stack_b->bottom);
		free(stack_b);
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

void	ft_stack_push(t_stack *stk)
{
	if (stk->top && stk->bottom)
}
