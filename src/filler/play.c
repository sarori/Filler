/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 23:50:00 by sapark            #+#    #+#             */
/*   Updated: 2019/10/24 22:58:26 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    play(t_set *f, FILE *fptr)
{
    fprintf(fptr, "play\n");
    f->spot.x = -1;
    f->spot.y = -1;
    f->point = 4096;
    set_heatmap(f, fptr);
    find_spot(f, fptr);
	if (f->spot.x == -1 && f->spot.y == -1)
	{
		f->spot.x = 0;
		f->spot.y = 0;
	}
	fprintf("%d %d\n", f->spot.y, f->spot.x);

    
}

int    validation(t_set *f, int y, int x, FILE *fptr)
{
	int	x_cnt;
	int	y_cnt;
	int	cnt;

	x_cnt = 0;
	y_cnt = 0;
	cnt = 0;
	if (f->piece_size.y - 1 + y >= f->board_size.y || f->piece_size.x - 1 + x >= f->board_size.x)
		return (-1);
	while (f->piece_size.y > y_cnt)
	{
		while (f->piece_size.x > x_cnt)
		{
			x_cnt = 0;
			if (f->piece_size.y + y < f->board_size.y && f->piece_size.x + x < f->board_size.x)
			{
				if (f->piece[y_cnt][x_cnt] == '*' && ft_strchr(f->p1, f->board[y + y_cnt][x + x_cnt]))
					cnt++;
				if (f->piece[y_cnt][x_cnt] == '*' && ft_strchr(f->p2, f->board[y + y_cnt][x + x_cnt]))
					return (0);
			}
			x_cnt++;
		}
		y_cnt++;
	}
	return (cnt == 1 ? 1 : 0);
}

// int     strchr_cnt(t_set *f, int y, int x, char c, FILE *fptr)
// {
//     //한개만 겹쳐지는지 확인하는 부분 다시!
//     int p_x;
//     int p_y;
//     int cnt;

//     p_y = 0;
//     cnt = 0;
//     while (f->piece_size.y > p_y)
//     {
//         p_x = 0;
//         while (f->piece_size.x > p_x)
//         {
//             if (f->heatmap[y][x] == 0 && f->piece[p_y][p_x] == '*')
//                 cnt++;
//             p_y++;
            
//         }

//     }
//     return (cnt;)
// }
int		count_point(t_set *f, int y, int x, FILE *fptr)
{
	int	x_cnt;
	int	y_cnt;
	int	min;

	x_cnt = 0;
	y_cnt = 0;
	min = 777;
	while (f->piece_size.y > y_cnt)
	{
		x_cnt = 0;
		while (f->piece_size.x > x_cnt)
		{
			if (f->heatmap[y + y_cnt][x + x_cnt] <= min)
				min = f->heat_map[y + y_cnt][x + x_cnt];
			x_cnt++;
		}
		y_cnt++;
	}
	return (min);
}

void    find_spot(t_set *f, FILE *fptr)
{
    int	x;
    int	y;
    int	point;

    x = 0;
    y = 0;
	point = 0;

    while (f->board_size.y > y)
    {
        x = 0;
        while (f->board_size.x > x)
        {
			x = 0;
            if (ft_strchr(f->p2, f->board[y][x]) = 0 && validation(f, y, x, fptr) == 1)
			{
				f->point = count_point(f, y, x, fptr);
				f->spot.x = x;;
				f->spot.y = y;
			}
            x++;
        }
    }
}