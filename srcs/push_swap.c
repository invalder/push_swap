/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:25:31 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/13 18:52:30 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_stk_init_splt(char **s_arr, t_stack *stk_a);
static int	ft_stk_init_argv(int argc, char **argv, t_stack *stk_a);
static void	ft_stk_creation_chk(t_stack *stk_a, t_stack *stk_b);

int	main(int argc, char **argv)
{
	int		isinputok;
	t_stack	*stack_a;
	t_stack	*stack_b;

	isinputok = 0;
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_stack_create();
	stack_b = ft_stack_create();
	ft_stk_creation_chk(stack_a, stack_b);
	if (argc < 2)
		ft_exit_req_args(stack_a, stack_b);
	else if (argc == 2)
		isinputok = ft_stk_init_splt(argv, stack_a);
	else
		isinputok = ft_stk_init_argv(argc, argv, stack_a);
	if (isinputok)
		ft_exit_stderr(stack_a, stack_b);
	ft_stack_print_all(stack_a, stack_b);
	// ft_stack_testing(stack_a, stack_b);
	ft_sorting_opr(stack_a, stack_b);
	ft_stacks_cleanup(stack_a, stack_b);
}

static int	ft_stk_init_splt(char **s_arr, t_stack *stk_a)
{
	char	**str_arr;
	char	**ptr_arr;
	int		arr_len;

	str_arr = ft_split(s_arr[1], ' ');
	arr_len = ft_arr_range(str_arr);
	ptr_arr = str_arr;
	if (ft_input_verifications(str_arr, 0) && !ft_check_inp_dup(str_arr))
	{
		while (*ptr_arr)
		{
			ft_stack_appendlast(stk_a, ft_atoi(*ptr_arr++));
		}
		ft_free_split(str_arr, arr_len);
		return (0);
	}
	return (1);
}

static int	ft_stk_init_argv(int argc, char **argv, t_stack *stk_a)
{
	int	len;

	len = 0;
	if (ft_input_verifications(argv, 1) && !ft_check_inp_dup(argv + 1))
	{
		while (++len < argc)
		{
			ft_stack_appendlast(stk_a, ft_atoi(argv[len]));
		}
		return (0);
	}
	return (1);
}

static void	ft_stk_creation_chk(t_stack *stk_a, t_stack *stk_b)
{
	if (!stk_a || !stk_b)
	{
		ft_stacks_cleanup(stk_a, stk_b);
		exit(1);
	}
}
