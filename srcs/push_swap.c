/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:25:31 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/02 09:18:50 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_arr_range(char **arr);
t_stack	*ft_stack_create(void);
void	ft_stacks_cleanup(t_stack *stack_a, t_stack *stack_b);
void	ft_clear_nodes(t_node *node);
void	ft_free_split(char **str_arr, int len);
int		ft_stack_push(t_stack *stk, int content);
t_node	*ft_stack_pop(t_stack *stk);
void	ft_stack_print(t_stack *stk);
int		ft_stack_appendlast(t_stack *stk, int content);
void	ft_stack_print_all(t_stack *stk_a, t_stack *stk_b);

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
	stack_a = ft_stack_create();
	if (!stack_a)
		ft_stacks_cleanup(stack_a, stack_b);
	stack_b = ft_stack_create();
	if (!stack_b)
		ft_stacks_cleanup(stack_a, stack_b);
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
	// ft_stack_print(stack_a);
	// printf("stack cnt, a: %d, b: %d\n", stack_a->stack_cnt, stack_b->stack_cnt);
	ft_stack_print_all(stack_a, stack_b);
	ft_stacks_cleanup(stack_a, stack_b);
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
	t_node	*ptr_node_a;
	t_node	*ptr_node_b;

	stack_max = 0;
	ptr_node_a = stk_a->top;
	ptr_node_b = stk_b->top;
	if (stk_a->stack_cnt > stk_b->stack_cnt)
		stack_max = stk_a->stack_cnt;
	else
		stack_max = stk_b->stack_cnt;
	while (stack_max > 0)
	{
		if (stk_a)
		{
			if (stk_a->stack_cnt >= stack_max)
			{
				ft_printf("|\t%03d\t|\t\t", ptr_node_a->content);
				ptr_node_a = ptr_node_a->prev;
			}
			else
				ft_printf("|\t\t|\t\t");
		}
		if (stk_b)
		{
			if (stk_b->stack_cnt >= stack_max)
			{
				ft_printf("%03d|\n", ptr_node_b->content);
				ptr_node_b = ptr_node_b->prev;
			}
			else
				ft_printf("|\n");
		}
		stack_max--;
	}
	ft_printf("_________________________________\n");
}
