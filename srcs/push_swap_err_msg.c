/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_err_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:06:29 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/13 15:46:20 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define ARGREQ1 "./push_swap <args-1> .... <args-n>\n"
#define ARGREQ2 "./push_swap \"args-1 args-2 .... args-n\"\n"
#define ARGREQ3 "ARG=\"args-1 args-2 .... args-n\"; ./push_swap $ARG\n"

void	ft_exit_req_args(t_stack *stk_a, t_stack *stk_b)
{
	ft_printf("<<TRY THIS>>\n");
	ft_printf("ARG:\n%s", ARGREQ1);
	ft_printf("or\n1 ARG:\n%s", ARGREQ2);
	ft_printf("or\nSTDIN:\n%s<<TRY THIS>>\n", ARGREQ3);
	ft_stacks_cleanup(stk_a, stk_b);
	exit(1);
}

void	ft_exit_customize(char *errmsg)
{
	ft_printf("Error: %s\n", errmsg);
	exit(1);
}

void	ft_exit_stderr(t_stack *stk_a, t_stack *stk_b)
{
	ft_putstr_fd("Error\n", 2);
	ft_stacks_cleanup(stk_a, stk_b);
	exit(1);
}
