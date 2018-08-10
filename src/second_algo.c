/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotlyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 15:56:43 by dkotlyar          #+#    #+#             */
/*   Updated: 2018/07/07 15:56:45 by dkotlyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	save_distance(t_position *pos, t_position *epos)
{
	int			i;
	int			j;
	int			k;
	int			min;
	t_option	option[100];

	k = 0;
	i = -1;
	min = 1000;
	while (pos[++i].x != -1)
	{
		j = -1;
		while (epos[++j].x != -1)
		{
			if ((ABS(pos[i].x - epos[j].x) + ABS(pos[i].y - epos[j].y)) < min)
			{
				min = ABS(pos[i].x - epos[j].x) + ABS(pos[i].y - epos[j].y);
				option[k].x = pos[i].x;
				option[k].y = pos[i].y;
				option[k++].distance = min;
			}
		}
	}
	option[k].distance = -1;
	find_lowest_distance(option);
}

void	save_enemy_positions(t_meta *meta, t_position *pos)
{
	int			i;
	int			j;
	int			k;
	t_position	epos[meta->size_x * meta->size_y];

	i = -1;
	k = 0;
	while (++i < meta->size_x)
	{
		j = -1;
		while (++j < meta->size_y)
		{
			if (meta->map[i][j] == meta->enemy ||
				meta->map[i][j] == meta->enemy + 32)
			{
				epos[k].x = i;
				epos[k++].y = j;
			}
		}
	}
	epos[k].x = -1;
	save_distance(pos, epos);
}

void	find_option(t_meta *meta)
{
	int			i;
	int			j;
	int			k;
	t_position	pos[meta->size_x * meta->size_y];

	i = -1;
	k = 0;
	while (++i < meta->size_x - meta->piece.size_x)
	{
		j = -1;
		while (++j < meta->size_y - meta->piece.size_y)
		{
			if (is_fit(meta, i, j))
			{
				pos[k].x = i;
				pos[k++].y = j;
			}
		}
	}
	pos[k].x = -1;
	save_enemy_positions(meta, pos);
}
