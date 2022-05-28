/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_opr4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:37:40 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/29 03:06:28 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_100_plus_sorting(t_stack *stk_a, t_stack *stk_b)
{
	int		chk;
	t_decs	decs_tab;

	chk = 0;
	while (ft_stack_issorted(stk_a, stk_b))
	{
		while (chk < stk_a->nchunks)
		{
			while (ft_is_chunk_pushed(stk_a, stk_b, chk))
			{
				ft_find_hold_positions(stk_a, &decs_tab, chk);
				ft_chunks_push(stk_a, stk_b, &decs_tab, chk);
			}
			chk++;
		}
		chk = stk_a->max;
		while (chk >= stk_a->min)
		{
			ft_find_positions(stk_b, &decs_tab, chk);
			ft_chunks_pull(stk_a, stk_b, &decs_tab, chk);
			chk--;
		}
	}
}

int	ft_is_chunk_pushed(t_stack *stk_a, t_stack *stk_b, int chk)
{
	t_node	*down;
	t_node	*up;

	(void)stk_b;
	down = stk_a->top;
	up = stk_a->bottom;
	while (down || up)
	{
		if ((down->content >= stk_a->min_chnks[chk] \
				&& down->content <= stk_a->max_chnks[chk])
			|| (up->content >= stk_a->min_chnks[chk] \
				&& up->content <= stk_a->max_chnks[chk]))
			return (1);
		down = down->prev;
		up = up->next;
	}
	return (0);
}

void	ft_find_hold_position_down(t_stack *stk_a, t_decs *decs_tab, int chk)
{
	t_node	*down;

	down = stk_a->top;
	while (down)
	{
		decs_tab->depth++;
		if (down->content >= stk_a->min_chnks[chk]
			&& down->content <= stk_a->max_chnks[chk])
		{
			decs_tab->depth_min = down->content;
			break ;
		}
		down = down->prev;
	}
}

void	ft_find_hold_position_up(t_stack *stk_a, t_decs *decs_tab, int chk)
{
	t_node	*up;

	up = stk_a->bottom;
	while (up)
	{
		decs_tab->height++;
		if (up->content >= stk_a->min_chnks[chk]
			&& up->content <= stk_a->max_chnks[chk])
		{
			decs_tab->height_min = up->content;
			break ;
		}
		up = up->next;
	}
}

void	ft_find_hold_positions(t_stack *stk_a, t_decs *decs_tab, int chk)
{
	ft_reset_decs(decs_tab);
	ft_find_hold_position_down(stk_a, decs_tab, chk);
	ft_find_hold_position_up(stk_a, decs_tab, chk);
}
