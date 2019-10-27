/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_setting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:54:47 by sapark            #+#    #+#             */
/*   Updated: 2019/10/26 19:30:29 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_heatmap(t_set *f)
{
	int         x_cnt;
    int         y_cnt;

	y_cnt = 0;
	while (f->board_size.y > y_cnt)
	{
		x_cnt = 0;
		while (f->board_size.x > x_cnt)
		{
			f->heatmap[y_cnt][x_cnt] = 777;
			x_cnt++;
		}
		y_cnt++;
	}
}

void	free_dpint(t_set *f)
{
	int         x_cnt;
    int         y_cnt;

	x_cnt = 0;
	y_cnt = 0;
	while (f->board_size.y > y_cnt)
		free(f->heatmap[y_cnt++]);
	free(f->heatmap);
}


void    set_heatmap(t_set *f)
{
    int         x_cnt;
    int         y_cnt;
    int         start;
    static int	count = 0;

    y_cnt = 0;
    start = 0;
    if (count++ > 0)
        free_dpint(f);
    f->heatmap = (int **)malloc(sizeof(int *) * (f->board_size.y));
	while (f->board_size.y > y_cnt)
		f->heatmap[y_cnt++] = (int *)malloc(sizeof(int) * f->board_size.x);
	init_heatmap(f);
	y_cnt= 0;


	while (f->board_size.y > y_cnt)
	{
		x_cnt = 0;
		while (f->board_size.x > x_cnt)
		{
			if (ft_strchr(f->p2, f->board[y_cnt][x_cnt]))
				draw_heatmap(f, start, x_cnt, y_cnt);
			x_cnt++;
		}
		y_cnt++;
	}
}

void    draw_heatmap(t_set *f, int start, int x, int y)
{
    int **res;

   
    if (x < 0 || f->board_size.x < x || y < 0 || f->board_size.y < y || ft_strchr(f->p1, f->board[y][x]))
        return ;
	res = f->heatmap;
    if (res[y][x] >= start)
        res[y][x] = start++;
    if (x - 1 >= 0 && (res[y][x - 1] > start || res[y][x - 1] == 0) && !ft_strchr(f->p2, f->board[y][x - 1]))
        draw_heatmap(f, start, x - 1, y);
	if (x + 1 < f->board_size.x && (res[y][x + 1] > start || res[y][x + 1] == 0) && !ft_strchr(f->p2, f->board[y][x + 1]))
        draw_heatmap(f, start, x + 1, y);
    if (y - 1 >= 0 && (res[y - 1][x] > start || res[y - 1][x] == 0) && !ft_strchr(f->p2, f->board[y - 1][x]))
        draw_heatmap(f, start, x, y - 1);
    
    if (y + 1 < f->board_size.y && (res[y + 1][x] > start || res[y + 1][x] == 0) && !ft_strchr(f->p2, f->board[y + 1][x]))
        draw_heatmap(f, start, x, y + 1);
}
