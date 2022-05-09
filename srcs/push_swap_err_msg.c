/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_err_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:06:29 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/09 14:10:31 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define ARGREQ1 "./push_swap <args-1> .... <args-n>\n"
#define ARGREQ2 "./push_swap \"args-1 args-2 .... args-n\"\n"
#define ARGREQ3 "ARG=\"args-1 args-2 .... args-n\"; ./push_swap $ARG\n"

void	ft_exit_req_args(void)
{
	ft_printf("<<TRY THIS>>\nARG:\n%sor\n1 ARG:\n%sor\nSTDIN:\n%s<<TRY THIS>>\n", ARGREQ1, ARGREQ2, ARGREQ3);
	exit(1);
}

void	ft_exit_customize(char *errmsg)
{
	ft_printf("Error: %s\n", errmsg);
	exit(1);
}

void	ft_exit_stderr(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
