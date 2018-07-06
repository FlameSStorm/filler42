/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotlyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:11:13 by dkotlyar          #+#    #+#             */
/*   Updated: 2018/07/06 11:16:50 by dkotlyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_fit(t_meta *meta, int x, int y)
{
	int i;
	int j;
	int is_on;

	i = -1;
	is_on = 0;
	while (++i < meta->piece.size_x)
	{
		j = -1;
		while (++j < meta->piece.size_y)
		{
			if (meta->piece.piece[i][j] == '*' &&
				(meta->map[x + i][y + j] == meta->player ||
				meta->map[x + i][y + j] == meta->player + 32))
				is_on++;
			if (meta->piece.piece[i][j] == '*' &&
				(meta->map[x + i][y + j] == meta->enemy ||
				meta->map[x + i][y + j] == meta->enemy + 32))
				return (0);
		}
	}
	return (is_on == 1 ? 1 : 0);
}

void	find_lowest_distance(t_option *option)
{
	int i;
	int min;
	int res[2];

	i = 0;
	min = option[0].distance;
	res[0] = option[0].x;
	res[1] = option[0].y;
	while (option[i].distance != -1)
	{
		if (option[i].distance < min)
		{
			min = option[i].distance;
			res[0] = option[i].x;
			res[1] = option[i].y;
		}
		i++;
	}
	ft_putnbr(res[0]);
	write(1, " ", 1);
	ft_putnbr(res[1]);
	write(1, "\n", 1);
}

int		find_size(intmax_t a)
{
	int i;

	i = 1;
	while (a / 10 > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

void	free_meta(t_meta *meta, char **tmp)
{
	int i;

	i = 0;
	while (i < meta->piece.size_x && meta->piece.piece[i])
		ft_strdel(&meta->piece.piece[i++]);
	free(meta->piece.piece);
	i = 0;
	while (i < meta->size_x && meta->map[i])
		free(meta->map[i++]);
	free(meta->map);
	ft_strdel(tmp);
}

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
