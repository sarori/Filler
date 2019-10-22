/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 02:41:13 by sapark            #+#    #+#             */
/*   Updated: 2019/10/21 23:38:31 by sapark           ###   ########.fr       */
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
	char			*p1;
	char			*p2;
	int				size;
	int				point;
	char			**piece;
	t_coor			board_size;
	t_coor			piece_size;
	t_coor			bestspot;
}					t_set;

// void	player_data(t_set *f, FILE *fptr);
// void	store_data(t_set *f, FILE *fptr);
// void	get_board(t_set *f, FILE *fptr);

void	player_data(t_set *f, FILE *fptr);
void	piece_data(t_set *f, char *piece_line, FILE *fptr);
void	store_data(t_set *f, FILE *fptr);
void	board_data(t_set *f, char *board_line, FILE *fptr);

#endif
