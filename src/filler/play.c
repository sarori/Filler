/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 23:50:00 by sapark            #+#    #+#             */
/*   Updated: 2019/10/26 20:00:51 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    play(t_set *f)
{
	set_heatmap(f);
    f->spot.x = -1;
    f->spot.y = -1;
    f->point = 777;
    find_spot(f);
	if (f->spot.x < 0 && f->spot.y < 0)
	{
		f->spot.x = 0;
		f->spot.y = 0;
	}
	ft_printf("%d %d\n", f->spot.y, f->spot.x);
}

int    validation(t_set *f, int y, int x)
{
	int	x_cnt;
	int	y_cnt;
	int	cnt;

	y_cnt = 0;
	cnt = 0;
	if (f->piece_size.y + y >= f->board_size.y + 1 || f->piece_size.x + x >= f->board_size.x + 1)
		return (0);
	while (f->piece_size.y > y_cnt)
	{
		x_cnt = 0;
		while (f->piece_size.x > x_cnt)
		{
			if (y_cnt + y < f->board_size.y && x_cnt + x < f->board_size.x && f->piece[y_cnt][x_cnt] == '*')
			{
				if (ft_strchr(f->p1, f->board[y + y_cnt][x + x_cnt]))
					cnt++;
				if (ft_strchr(f->p2, f->board[y + y_cnt][x + x_cnt]))
					return (0);
			}
			x_cnt++;
		}
		y_cnt++;
	}
	return (cnt == 1 ? 1 : 0);
}

int		count_point(t_set *f, int y, int x)
{
	int	x_cnt;
	int	y_cnt;
	int	min;

	y_cnt = 0;
	min = 777;
	while (f->piece_size.y > y_cnt)
	{
		x_cnt = 0;
		while (f->piece_size.x > x_cnt)
		{
			if (f->heatmap[y + y_cnt][x + x_cnt] <= min)
				min = f->heatmap[y + y_cnt][x + x_cnt];
			x_cnt++;
		}
		y_cnt++;
	}
	return (min);
}

void    find_spot(t_set *f)
{
    int	x;
    int	y;
    int	point;

    y = 0;
	point = 0;
    while (f->board_size.y > y)
    {
        x = 0;
        while (f->board_size.x > x)
        {
            if ( f->board_size.x > x && f->board_size.y > y 
			&& !ft_strchr(f->p2, f->board[y][x]) && validation(f, y, x) != 0
			&& (point = count_point(f, y, x)) <= f->point)
			{
				f->point = point;
				f->spot.x = x;
				f->spot.y = y;
			}
            x++;
        }
		y++;
    }
}