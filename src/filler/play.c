/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 23:50:00 by sapark            #+#    #+#             */
/*   Updated: 2019/10/24 17:11:42 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    play(t_set *f, FILE *fptr)
{
	fprintf(fptr, "play\n");
    set_heatmap(f, fptr);
    find_spot(f, fptr);
    
}

void    validation(t_set *f, int y, int x, FILE *fptr)
{

}

int     strchr_cnt(t_set *f, int y, int x, char c, FILE *fptr)
{
    //한개만 겹쳐지는지 확인하는 부분 다시!
    int p_x;
    int p_y;
    int cnt;

    p_y = 0;
    cnt = 0;
    while (f->piece_size.y > p_y)
    {
        p_x = 0;
        while (f->piece_size.x > p_x)
        {
            if (f->heatmap[y][x] == 0 && f->piece[p_y][p_x] == '*')
                cnt++;
            p_y++;
            
        }

    }
    return (cnt;)
}

void    find_spot(t_set *f, FILE *fptr)
{
    int x;
    int y;

    x = 0;
    y = 0;
    //0인 부분이 1개만 해당 되어야 한다.

    while (y < f->board_size.y)
    {
        // x = 0;
        while (x < f->board_size.x)
        {
            if (f->heatmap[y][x] == 0 &&  strchr_cnt(f, y, x, heatmap[y][x], fptr))
                validation(f, y, x, fptr);
            x++;
        }
    }
}