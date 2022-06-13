/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_tester.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 01:17:27 by nnakarac          #+#    #+#             */
/*   Updated: 2022/06/13 18:12:51 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_opr_chk(char *buff, t_stack *stk_a, t_stack *stk_b, int len);
static int	ft_opr_chk2(char *buff, t_stack *stk_a, t_stack *stk_b, int len);
static int	ft_opr_chk3(char *buff, t_stack *stk_a, t_stack *stk_b, int len);
static void	ft_final_check(t_stack *stk_a, t_stack *stk_b);

void	ft_stack_testing(t_stack *stk_a, t_stack *stk_b)
{
	char	*buff;
	char	*ptr;
	int		loop;

	loop = 1;
	while (loop == 1)
	{
		buff = (char *)malloc(sizeof(char) * 512);
		ft_bzero(buff, sizeof(char) * 512);
		ptr = buff;
		while (read(0, ptr, 1) > 0)
			if (*ptr++ == '\n')
				break ;
		if (!*buff)
			loop = 0;
		if (ft_opr_chk(buff, stk_a, stk_b, ft_strlen(buff)) == -1)
		{
			free(buff);
			ft_exit_stderr(stk_a, stk_b);
		}
		ft_bzero(buff, sizeof(char) * 512);
		free(buff);
	}
	ft_final_check(stk_a, stk_b);
}

static int	ft_opr_chk(char *buff, t_stack *stk_a, t_stack *stk_b, int len)
{
	if (!ft_strncmp(buff, "sa\n", len) && len > 0)
		return (ft_stack_sa(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "sb\n", len) && len > 0)
		return (ft_stack_sb(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "ss\n", len) && len > 0)
		return (ft_stack_ss(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "pa\n", len) && len > 0)
		return (ft_stack_pa(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "pb\n", len) && len > 0)
		return (ft_stack_pb(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "ra\n", len) && len > 0)
		return (ft_stack_ra(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "rb\n", len) && len > 0)
		return (ft_stack_rb(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "rr\n", len) && len > 0)
		return (ft_stack_rr(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "rra\n", len) && len > 0)
		return (ft_stack_rra(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "rrb\n", len) && len > 0)
		return (ft_stack_rrb(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "rrr\n", len) && len > 0)
		return (ft_stack_rrr(stk_a, stk_b, 1));
	else
		return (ft_opr_chk2(buff, stk_a, stk_b, len));
}

static int	ft_opr_chk2(char *buff, t_stack *stk_a, t_stack *stk_b, int len)
{
	if (!ft_strncmp(buff, "sa", len) && len > 0)
		return (ft_stack_sa(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "sb", len) && len > 0)
		return (ft_stack_sb(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "ss", len) && len > 0)
		return (ft_stack_ss(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "pa", len) && len > 0)
		return (ft_stack_pa(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "pb", len) && len > 0)
		return (ft_stack_pb(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "ra", len) && len > 0)
		return (ft_stack_ra(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "rb", len) && len > 0)
		return (ft_stack_rb(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "rr", len) && len > 0)
		return (ft_stack_rr(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "rra", len) && len > 0)
		return (ft_stack_rra(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "rrb", len) && len > 0)
		return (ft_stack_rrb(stk_a, stk_b, 1));
	else if (!ft_strncmp(buff, "rrr", len) && len > 0)
		return (ft_stack_rrr(stk_a, stk_b, 1));
	else
		return (ft_opr_chk3(buff, stk_a, stk_b, len));
}

static int	ft_opr_chk3(char *buff, t_stack *stk_a, t_stack *stk_b, int len)
{
	(void)stk_a;
	(void)stk_b;
	if (!ft_strncmp(buff, "", len) || len == 0)
		return (0);
	else
		return (-1);
}

static void	ft_final_check(t_stack *stk_a, t_stack *stk_b)
{
	if (!ft_stack_issorted(stk_a, stk_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 2);
}
