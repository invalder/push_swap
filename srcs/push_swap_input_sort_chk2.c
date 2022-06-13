/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input_sort_chk2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:10:31 by nnakarac          #+#    #+#             */
/*   Updated: 2022/06/13 16:00:26 by nnakarac         ###   ########.fr       */
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
	long	tmp;
	int		arr_len;
	long	*samples;

	idx = 1;
	arr_len = ft_arr_range(arr);
	samples = ft_quick_sort_main(arr);
	tmp = samples[0];
	while (idx < arr_len)
	{
		if (tmp == samples[idx] || (long)samples[idx] < (long)INT_MIN
			|| (long)samples[idx] > (long)INT_MAX || tmp < (long)INT_MIN
			|| tmp > (long)INT_MAX)
		{
			free(samples);
			return (1);
		}
		tmp = samples[idx++];
	}
	free(samples);
	if (tmp < (long)INT_MIN || tmp > (long)INT_MAX)
		return (1);
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
