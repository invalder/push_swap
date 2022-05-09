/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:25:48 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/09 11:36:06 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define _GNU_SOURCE

# include "libft.h"
# include "ft_printf.h"

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*bottom;
	t_node	*top;
	int		stack_cnt;
}	t_stack;

int		ft_arr_range(char **arr);
t_stack	*ft_stack_create(void);
t_node	*ft_stack_pop(t_stack *stk);
void	ft_stack_print(t_stack *stk);
void	ft_clear_nodes(t_node *node);
void	ft_free_split(char **str_arr, int len);
int		ft_stack_rot(t_stack *stk);
int		ft_stack_push(t_stack *stk, int content);
int		ft_stack_push_node(t_stack *stk, t_node *new_node);
int		ft_stack_appendlast(t_stack *stk, int content);
void	ft_stack_print_all(t_stack *stk_a, t_stack *stk_b);
void	ft_stacks_cleanup(t_stack *stack_a, t_stack *stack_b);
long	*ft_radix_sort_main(char **arr);
void	ft_print_samples(long *samples, int len);
int		ft_check_inp_dup(char **arr);
int		ft_mlc_chk(long *samples, long *new_sample, long *count);
int		ft_input_verifications(char **p_arr, int isarg);
void	ft_exit_req_args(void);
void	ft_exit_customize(char *errmsg);
void	ft_exit_stderr(void);

#endif
