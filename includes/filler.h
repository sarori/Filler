/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 02:41:13 by sapark            #+#    #+#             */
/*   Updated: 2019/10/26 20:04:01 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"

typedef struct		s_coor
{
    int				x;
	int				y;
}					t_coor;

typedef struct		s_set
{
	char			**board;
	char			**piece;
	int				**heatmap;
	char			*p1;
	char			*p2;
	int				point;
	t_coor			board_size;
	t_coor			piece_size;
	t_coor			spot;
}					t_set;

/*
**----------------------data_setting----------------------
*/
void				player_data(t_set *f);
void				piece_data(t_set *f, char *piece_line);
void				store_data(t_set *f);
void				board_data(t_set *f, char *board_line);
/*
**---------------------heatmap_setting---------------------
*/

void    			set_heatmap(t_set *f);
void				init_heatmap(t_set *f);
void				free_dpint(t_set *f);
void    			draw_heatmap(t_set *f, int start, int x, int y);
/*
**----------------------------play-------------------------
*/
void    			play(t_set *f);
void    			find_spot(t_set *f);
int					validation(t_set *f, int y, int x);
int					count_point(t_set *f, int y, int x);
#endif
