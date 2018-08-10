/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotlyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:22:36 by dkotlyar          #+#    #+#             */
/*   Updated: 2018/07/11 17:03:42 by dkotlyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	save_last_enemy_position(t_meta *meta, t_position *en)
{
	int				i;
	int				j;

	i = -1;
	while (++i < meta->size_x)
	{
		j = -1;
		while (++j < meta->size_y)
		{
			if (meta->map[i][j] == meta->enemy + 32)
			{
				en->x = i;
				en->y = j;
			}
		}
	}
}

void		find_option(t_meta *meta)
{
	t_position	en;
	int			i;
	int			j;
	int			k;
	t_option	opt[meta->size_x * meta->size_y];

	save_last_enemy_position(meta, &en);
	k = 0;
	i = -1;
	while (++i < meta->size_x - meta->piece.size_x)
	{
		j = -1;
		while (++j < meta->size_y - meta->piece.size_y)
		{
			if (is_fit(meta, i, j))
			{
				opt[k].distance = ABS(i - en.x) + ABS(j - en.y);
				opt[k].x = i;
				opt[k++].y = j;
			}
		}
	}
	opt[k].distance = -1;
	find_lowest_distance(opt);
}
