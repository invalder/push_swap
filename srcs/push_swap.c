/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:25:31 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/06 19:51:22 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_stk_init_splt(char **s_arr, t_stack *stk_a);
static void	ft_stk_init_argv(int argc, char **argv, t_stack *stk_a);

int	main(int argc, char **argv)
{
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
		ft_printf("./push_swap <args-1> .... <args-n>\n");
		exit(1);
	}
	else if (argc == 2)
	{
		ft_stk_init_splt(argv, stack_a);
	}
	else
	{
		ft_stk_init_argv(argc, argv, stack_a);
	}
	// ft_stack_print_all(stack_a, stack_b);
	ft_stacks_cleanup(stack_a, stack_b);
}

static void	ft_stk_init_splt(char **s_arr, t_stack *stk_a)
{
	char	**str_arr;
	char	**ptr_arr;
	int		arr_len;

	str_arr = ft_split(s_arr[1], ' ');
	arr_len = ft_arr_range(str_arr);
	ptr_arr = str_arr;
	free(ft_radix_sort_main(str_arr));
	while (*ptr_arr)
	{
		ft_stack_appendlast(stk_a, ft_atoi(*ptr_arr++));
	}
	ft_free_split(str_arr, arr_len);
}

static void	ft_stk_init_argv(int argc, char **argv, t_stack *stk_a)
{
	int	len;

	len = 0;
	free(ft_radix_sort_main(argv + 1));
	while (++len < argc)
	{
		ft_stack_appendlast(stk_a, ft_atoi(argv[len]));
	}
}
