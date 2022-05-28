/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:25:48 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/29 00:08:07 by nnakarac         ###   ########.fr       */
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
	int		min;
	int		max;
	int		nchunks;
	int		*min_chnks;
	int		*max_chnks;
}	t_stack;

typedef struct s_decision
{
	int		depth;
	int		depth_min;
	int		depth_isneg;
	int		height;
	int		height_min;
	int		height_isneg;
}	t_decs;

int		ft_arr_range(char **arr);
t_stack	*ft_stack_create(void);
t_node	*ft_stack_pop(t_stack *stk);
void	ft_stack_print(t_stack *stk);
void	ft_clear_nodes(t_node *node);
void	ft_free_split(char **str_arr, int len);
int		ft_stack_rot(t_stack *stk);
int		ft_stack_rev_rot(t_stack *stk);
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
void	ft_exit_req_args(t_stack *stk_a, t_stack *stk_b);
void	ft_exit_customize(char *errmsg);
void	ft_exit_stderr(t_stack *stk_a, t_stack *stk_b);

int		ft_stack_sa(t_stack *stk_a, t_stack *stk_b, int iscalled);
int		ft_stack_sb(t_stack *stk_a, t_stack *stk_b, int iscalled);
int		ft_stack_ss(t_stack *stk_a, t_stack *stk_b);
int		ft_stack_pa(t_stack *stk_a, t_stack *stk_b);
int		ft_stack_pb(t_stack *stk_a, t_stack *stk_b);
int		ft_stack_ra(t_stack *stk_a, t_stack *stk_b, int iscalled);
int		ft_stack_rb(t_stack *stk_a, t_stack *stk_b, int iscalled);
int		ft_stack_rr(t_stack *stk_a, t_stack *stk_b);
int		ft_stack_rra(t_stack *stk_a, t_stack *stk_b, int iscalled);
int		ft_stack_rrb(t_stack *stk_a, t_stack *stk_b, int iscalled);
int		ft_stack_rrr(t_stack *stk_a, t_stack *stk_b);

void	ft_stack_testing(t_stack *stk_a, t_stack *stk_b);

void	ft_sorting_opr(t_stack *stk_a, t_stack *stk_b, long *samples);
void	ft_stack_stats_all(t_stack *stk_a, t_stack *stk_b);
void	ft_stack_stats(t_stack *stk);
void	ft_stack_find_min(t_stack *stk);
void	ft_stack_find_max(t_stack *stk);

int		ft_stack_issorted(t_stack *stk_a, t_stack *stk_b);
int		ft_stack_issorted_single(t_stack *stk, int dir);
int		ft_stack_n_pa(t_stack *stk_a, t_stack *stk_b, int n);
int		ft_stack_n_pb(t_stack *stk_a, t_stack *stk_b, int n);
int		ft_stack_n_ra(t_stack *stk_a, t_stack *stk_b, int n);
int		ft_stack_n_rb(t_stack *stk_a, t_stack *stk_b, int n);
int		ft_stack_n_rra(t_stack *stk_a, t_stack *stk_b, int n);
int		ft_stack_n_rrb(t_stack *stk_a, t_stack *stk_b, int n);
int		ft_stack_n_rr(t_stack *stk_a, t_stack *stk_b, int n);
int		ft_stack_n_rrr(t_stack *stk_a, t_stack *stk_b, int n);

void	ft_stack_find_min_diff(t_stack *stk, int key, t_decs *decs_tab);
int		ft_update_decs(t_decs *decs_tab, int key, int node);
int		ft_update_decs_up(t_decs *decs_tab, int key, int node);
void	ft_reset_decs(t_decs *decs_tab);
void	ft_print_decs(t_decs *decs_tab);

void	ft_sorting_decision(t_stack *stk_a, t_stack *stk_b, t_decs *decs_tab);

void	ft_3_rand_nums(t_stack *stk_a, t_stack *stk_b);
void	ft_5_rand_nums(t_stack *stk_a, t_stack *stk_b);
void	ft_rand_nums(t_stack *stk_a, t_stack *stk_b);
void	ft_5_rand_decision(t_stack *stk_a, t_stack *stk_b, t_decs *decs_tab);

void	ft_chunk_calculator(t_stack *stk_a, t_stack *stk_b, long *samples);
void	ft_chunks_alloc(t_stack *stk_a, t_stack *stk_b, long *samples);
void	ft_chunks_validate(t_stack *stk_a, t_stack *stk_b, long *samples);
void	ft_chunks_cleanup(t_stack *stk_a, t_stack *stk_b, long *samples);
void	ft_chunks_assign(t_stack *stk_a, t_stack *stk_b, long *samples);

void	ft_100_plus_sorting(t_stack *stk_a, t_stack *stk_b);
int		ft_is_chunk_pushed(t_stack *stk_a, t_stack *stk_b, int chk);
void	ft_find_hold_position_down(t_stack *stk_a, t_decs *decs_tab, int chk);
void	ft_find_hold_position_up(t_stack *stk_a, t_decs *decs_tab, int chk);
void	ft_find_hold_positions(t_stack *stk_a, t_decs *decs_tab, int chk);
void	ft_chunks_push(t_stack *stk_a, t_stack *stk_b, t_decs *decs, int chk);

void	ft_find_positions(t_stack *stk_a, t_decs *decs_tab, int val);
void	ft_find_position_down(t_stack *stk_a, t_decs *decs_tab, int val);
void	ft_find_position_up(t_stack *stk_a, t_decs *decs_tab, int val);
void	ft_chunks_pull(t_stack *stk_a, t_stack *stk_b, t_decs *decs, int val);

#endif
