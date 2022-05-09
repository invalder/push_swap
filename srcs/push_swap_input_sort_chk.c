/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input_sort_chk.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:14:56 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/09 14:01:10 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_cnt_calc(long *samples, long *count, int len, long base);
static long	*ft_counting_sort(long *samples, int len, long base);
static long	*ft_radix_sort(long *samples, int len);
static long	ft_find_max(long *samples, int len, long base);

long	*ft_radix_sort_main(char **arr)
{
	int		arr_len;
	long	*samples;
	int		idx;

	idx = 0;
	arr_len = ft_arr_range(arr);
	samples = (long *)malloc(sizeof(long) * arr_len);
	if (!samples)
		return (NULL);
	ft_bzero(samples, sizeof(long) * arr_len);
	while (idx < arr_len)
	{
		samples[idx] = ft_atol(arr[idx]);
		idx++;
	}
	samples = ft_radix_sort(samples, arr_len);
	if (samples)
		return (samples);
	return (NULL);
}

static long	*ft_radix_sort(long *samples, int len)
{
	long	max;
	long	base;

	base = 1;
	max = ft_find_max(samples, len, 0);
	while (max / base > 0)
	{
		samples = ft_counting_sort(samples, len, base);
		if (!samples)
			return (NULL);
		base *= 10;
	}
	return (samples);
}

static long	ft_find_max(long *samples, int len, long base)
{
	int		idx;
	long	max;

	idx = 0;
	max = 0;
	if (!base)
	{
		while (idx < len)
		{
			if (samples[idx] > max)
				max = samples[idx];
			idx++;
		}
	}
	else
	{
		max = (samples[0] / base) % 10;
		while (++idx < len)
		{
			if ((samples[idx] / base) % 10 > max)
				max = samples[idx];
		}
	}
	return (max);
}

static long	*ft_counting_sort(long *samples, int len, long base)
{
	long	*new_sample;
	long	*count;
	long	max;
	int		idx;

	idx = len -1;
	max = ft_find_max(samples, len, base);
	new_sample = (long *)malloc(sizeof(long) * (len));
	count = (long *)malloc(sizeof(long) * (19));
	if (ft_mlc_chk(samples, new_sample, count))
		return (NULL);
	ft_bzero(count, sizeof(long) * (19));
	ft_cnt_calc(samples, count, len, base);
	while (idx >= 0)
	{
		new_sample[count[((samples[idx] / base) % 10) + 9] - 1] = samples[idx];
		count[((samples[idx] / base) % 10) + 9]--;
		idx--;
	}
	free(samples);
	free(count);
	return (new_sample);
}

static void	ft_cnt_calc(long *samples, long *count, int len, long base)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		count[((samples[idx] / base) % 10) + 9]++;
		idx++;
	}
	idx = 1;
	while (idx < 19)
	{
		count[idx] += count[idx - 1];
		idx++;
	}
}
