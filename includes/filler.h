/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 02:41:13 by sapark            #+#    #+#             */
/*   Updated: 2019/10/25 12:40:28 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"

//
#include <stdio.h>
//

typedef struct		s_coor
{
    int				x;
	int				y;
}					t_coor;

typedef struct		s_set
{
	char			*line;
	char			**board;
	char			**piece;
	int				**heatmap;
	char			*p1;
	char			*p2;
	// int				size;
	int				point;

	t_coor			board_size;
	t_coor			piece_size;
	t_coor			spot;
}					t_set;

// void	player_data(t_set *f, FILE *fptr);
// void	store_data(t_set *f, FILE *fptr);
// void	get_board(t_set *f, FILE *fptr);
/*
**----------------------data_setting----------------------
*/
void				player_data(t_set *f, FILE *fptr);
void				piece_data(t_set *f, char *piece_line, FILE *fptr);
void				store_data(t_set *f, FILE *fptr);
void				board_data(t_set *f, char *board_line, FILE *fptr);
/*
**---------------------heatmap_setting---------------------
*/

void    			set_heatmap(t_set *f, FILE *fptr);
void				init_heatmap(t_set *f, FILE *fptr);
void				free_dpint(t_set *f);
void    			draw_heatmap(t_set *f, int start, int x, int y, FILE *fptr);
/*
**----------------------------play-------------------------
*/
void    			play(t_set *f, FILE *fptr);
void    			find_spot(t_set *f, FILE *fptr);
int					validation(t_set *f, int y, int x, FILE *fptr);
int					count_point(t_set *f, int y, int x, FILE *fptr);
#endif
