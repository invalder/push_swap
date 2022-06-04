/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input_sort_chk3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:34:02 by nnakarac          #+#    #+#             */
/*   Updated: 2022/06/03 19:22:09 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_quick_sort(long *samples, int lt, int rt);
static int	ft_quick_sort_partition(long *samples, int lt, int rt);
static void	ft_quick_sort_swap(long *first, long *last);

long	*ft_quick_sort_main(char **arr)
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
	ft_quick_sort(samples, 0, arr_len - 1);
	if (samples)
		return (samples);
	return (NULL);
}

static void	ft_quick_sort(long *samples, int lt, int rt)
{
	int	mid;

	mid = 0;
	if (lt < rt)
	{
		mid = ft_quick_sort_partition(samples, lt, rt);
		ft_quick_sort(samples, lt, mid - 1);
		ft_quick_sort(samples, mid + 1, rt);
	}
}

static int	ft_quick_sort_partition(long *samples, int lt, int rt)
{
	long	pivot;
	int		i;
	int		j;

	i = lt - 1;
	j = lt;
	pivot = *(samples + rt);
	while (j <= rt - 1)
	{
		if (*(samples + j) < pivot)
		{
			i++;
			ft_quick_sort_swap(samples + i, samples + j);
		}
		j++;
	}
	ft_quick_sort_swap(samples + i + 1, samples + rt);
	return (i + 1);
}

static void	ft_quick_sort_swap(long *first, long *last)
{
	long	temp;

	temp = *first;
	*first = *last;
	*last = temp;
}
