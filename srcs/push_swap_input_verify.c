/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input_verify.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:27:16 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/09 11:34:32 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Verifications step before initial to stack
- Verify all data is digits
- Verify no duplication inputs
*/

static int	ft_is_digit_str(char *p_str);

int	ft_input_verifications(char **p_arr, int isarg)
{
	int	idx;
	int	arr_len;

	idx = 0;
	if (isarg)
		idx++;
	arr_len = ft_arr_range(p_arr);
	while (idx < arr_len)
	{
		if (!ft_is_digit_str(p_arr[idx]))
			return (0);
		idx++;
	}
	return (1);
}

static int	ft_is_digit_str(char *p_str)
{
	int	idx;

	idx = 1;
	if (*p_str == '-' || ft_isdigit(*p_str))
	{
		while (*(p_str + idx))
		{
			if (ft_isdigit(*(p_str + idx)))
				idx++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
