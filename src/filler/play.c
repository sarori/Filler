/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 23:50:00 by sapark            #+#    #+#             */
/*   Updated: 2019/10/25 12:41:20 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    play(t_set *f, FILE *fptr)
{
    fprintf(fptr, "play\n");
	set_heatmap(f, fptr);
    f->spot.x = -1;
    f->spot.y = -1;
    f->point = 777;
    
    find_spot(f, fptr);
	if (f->spot.x < 0 && f->spot.y < 0)
	{
		f->spot.x = 0;
		f->spot.y = 0;
	}
	// fprintf(fptr, "%d %d\n", f->spot.y, f->spot.x);
	ft_printf("%d %d\n", f->spot.y, f->spot.x);
}

int    validation(t_set *f, int y, int x, FILE *fptr)
{
	// fprintf(fptr, "validation\n");
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
	fprintf(fptr, "cnt:%d\n", cnt);
	return (cnt == 1 ? 1 : 0);
}

int		count_point(t_set *f, int y, int x, FILE *fptr)
{
	fprintf(fptr, "count_point\n");
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

void    find_spot(t_set *f, FILE *fptr)
{
	fprintf(fptr, "find_spot\n");
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
            if (f->board_size.y > y 
			&& f->board_size.x > x 
			&& !ft_strchr(f->p2, f->board[y][x]) 
			&& validation(f, y, x, fptr)
			&& (point = count_point(f, y, x, fptr)) <= f->point)
			{
				fprintf(fptr, "a\n");
				f->point = point;
				f->spot.x = x;
				f->spot.y = y;
				fprintf(fptr, "spot.x:%d\n", f->spot.x);
				fprintf(fptr, "spot.y:%d\n", f->spot.y);
				fprintf(fptr, "point:%d\n", f->point);
			}
            x++;
        }
		y++;
    }
}