/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:25:31 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/01 17:40:00 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_arr_range(char **arr);
t_stack	*ft_create_stack(void);
void	ft_cleanup_stacks(t_stack *stack_a, t_stack *stack_b);
void	ft_clear_nodes(t_node *node);
void	ft_free_split(char **str_arr, int len);
int		ft_stack_push(t_stack *stk, int content);
t_node	*ft_stack_pop(t_stack *stk);
void	ft_print_stack(t_stack *stk);
int		ft_stack_appendlast(t_stack *stk, int content);

int	main(int argc, char **argv)
{
	char	**str_arr;
	char	**ptr_arr;
	int		arr_len;
	t_stack	*stack_a;
	t_stack	*stack_b;

	arr_len = 0;
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
	else if (argc == 2)
	{
		str_arr = ft_split(argv[1], ' ');
		arr_len = ft_arr_range(str_arr);
		ft_printf("arr_len: %d\n", arr_len);
		ptr_arr = str_arr;
		while (*ptr_arr)
		{
			// printf("v: %s\n", *ptr_arr);
			ft_stack_appendlast(stack_a, ft_atoi(*ptr_arr++));
		}
		ft_free_split(str_arr, arr_len);
	}
	else
	{
		while (++arr_len < argc)
		{
			// printf("v: %s\n", argv[arr_len]);
			ft_stack_appendlast(stack_a, ft_atoi(argv[arr_len]));
		}
	}
	ft_print_stack(stack_a);
	printf("stack cnt, a: %d, b: %d\n", stack_a->stack_cnt, stack_b->stack_cnt);
	ft_cleanup_stacks(stack_a, stack_b);
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

t_stack	*ft_create_stack(void)
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

void	ft_cleanup_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		stack_a->top = NULL;
		ft_clear_nodes(stack_a->bottom);
		stack_a->stack_cnt = 0;
		free(stack_a);
	}
	if (stack_b)
	{
		stack_b->top = NULL;
		ft_clear_nodes(stack_b->bottom);
		stack_b->stack_cnt = 0;
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

int	ft_stack_push(t_stack *stk, int content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node) * 1);
	if (!new_node)
		return (-1);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (stk->top && stk->bottom)
	{
		stk->top->next = new_node;
		new_node->prev = stk->top;
		stk->top = new_node;
		stk->stack_cnt++;
	}
	else
	{
		stk->top = new_node;
		stk->bottom = new_node;
		stk->stack_cnt++;
	}
	return (0);
}

int	ft_stack_appendlast(t_stack *stk, int content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node) * 1);
	if (!new_node)
		return (-1);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (stk->top && stk->bottom)
	{
		stk->bottom->prev = new_node;
		new_node->next = stk->bottom;
		stk->bottom = new_node;
		stk->stack_cnt++;
	}
	else
	{
		stk->top = new_node;
		stk->bottom = new_node;
		stk->stack_cnt++;
	}
	return (0);
}

t_node	*ft_stack_pop(t_stack *stk)
{
	t_node	*ret_node;

	if (stk->top && stk->bottom)
	{
		ret_node = stk->top;
		stk->top = stk->top->prev;
		return ret_node;
	}
	return NULL;
}

void	ft_print_stack(t_stack *stk)
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
