/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:25:48 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/01 17:31:01 by nnakarac         ###   ########.fr       */
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

#endif
