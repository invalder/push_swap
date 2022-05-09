/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input_sort_chk2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:10:31 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/09 11:38:04 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_samples(long *samples, int len)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		ft_printf("|\t%d\t|\n", samples[idx++]);
	}
}

int	ft_check_inp_dup(char **arr)
{
	int		idx;
	int		tmp;
	int		arr_len;
	long	*samples;

	idx = 1;
	arr_len = ft_arr_range(arr);
	samples = ft_radix_sort_main(arr);
	tmp = samples[0];
	while (idx < arr_len)
	{
		if (tmp == samples[idx] || samples[idx] > INT_MAX
			|| samples[idx] < INT_MIN)
		{
			free(samples);
			return (1);
		}
		tmp = samples[idx++];
	}
	free(samples);
	return (0);
}

int	ft_mlc_chk(long *samples, long *new_sample, long *count)
{
	if (!new_sample || !count)
	{
		free(samples);
		if (count)
			free(count);
		if (new_sample)
			free(new_sample);
		return (1);
	}
	return (0);
}
