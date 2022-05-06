/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input_sort_chk.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:14:56 by nnakarac          #+#    #+#             */
/*   Updated: 2022/05/06 19:53:55 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft_arr_range
// int	ft_arr_range(char **arr)
static void	ft_cnt_calc(int *samples, int *count, int len, int base);
static int	*ft_counting_sort(int *sample, int len, int base);
static void ft_print_samples(int *samples, int len);
static int	*ft_radix_sort(int *samples, int len);
static int	ft_find_max(int *samples, int len, int base);
static int	ft_mlc_chk(int *samples, int *new_sample, int *count);

int	*ft_radix_sort_main(char **arr)
{
	int	arr_len;
	int	*samples;
	int	idx;

	idx = 0;
	arr_len = ft_arr_range(arr);
	samples = (int *)malloc(sizeof(int) * arr_len);
	if (!samples)
		return (NULL);
	ft_bzero(samples, sizeof(int) * arr_len);
	while (idx < arr_len)
	{
		samples[idx] = ft_atoi(arr[idx]);
		idx++;
	}
	samples = ft_radix_sort(samples, arr_len);
	if (samples)
		return (samples);
	return (NULL);
}

static int	*ft_radix_sort(int *samples, int len)
{
	int	max;
	int	base;

	base = 1;
	max = ft_find_max(samples, len, 0);
	while (max / base > 0)
	{
		samples = ft_counting_sort(samples, len, base);
		if (!samples)
			return (NULL);
		base *= 10;
	}
	ft_print_samples(samples, len);
	ft_printf("base = %d, max = %d\n\n", base, max);
	return (samples);
}

static int	ft_find_max(int *samples, int len, int base)
{
	int	idx;
	int max;

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

static int	*ft_counting_sort(int *samples, int len, int base)
{
	int	*new_sample;
	int	*count;
	int	max;
	int	idx;

	idx = len -1;
	max = ft_find_max(samples, len, base);
	ft_printf("max = %d\n", max);
	new_sample = (int *)malloc(sizeof(int) * (len));
	count = (int *)malloc(sizeof(int) * (10));
	if (ft_mlc_chk(samples, new_sample, count))
		return (NULL);
	ft_bzero(count, sizeof(int) * (10));
	ft_cnt_calc(samples, count, len, base);
	while (idx >= 0)
	{
		new_sample[count[(samples[idx] / base) % 10] - 1] = samples[idx];
		count[(samples[idx] / base) % 10]--;
		idx--;
	}
	free(samples);
	free(count);
	return (new_sample);
}

static void	ft_cnt_calc(int *samples, int *count, int len, int base)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		count[(samples[idx] / base) % 10]++;
		idx++;
	}
	idx = 1;
	while (idx < 10)
	{
		count[idx] += count[idx - 1];
		idx++;
	}
}

static int	ft_mlc_chk(int *samples, int *new_sample, int *count)
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

static void	ft_print_samples(int *samples, int len)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		ft_printf("|\t%d\t|\n", samples[idx++]);
	}
}
