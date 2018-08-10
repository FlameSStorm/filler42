/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotlyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:21:15 by dkotlyar          #+#    #+#             */
/*   Updated: 2018/07/11 16:22:17 by dkotlyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	find_option(t_meta *meta)
{
	int			i;
	int			j;
	int			k;
	t_option	option[meta->size_x * meta->size_y];

	i = 0;
	k = 0;
	while (i < meta->size_x - meta->piece.size_x)
	{
		j = 0;
		while (j < meta->size_y - meta->piece.size_y)
		{
			if (is_fit(meta, i, j))
			{
				option[k].distance = ABS(i - meta->enemy_x) +
					ABS(j - meta->enemy_y);
				option[k].x = i;
				option[k++].y = j;
			}
			j++;
		}
		option[k].distance = -1;
		i++;
	}
	find_lowest_distance(option);
}
