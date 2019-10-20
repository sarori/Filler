/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 02:41:13 by sapark            #+#    #+#             */
/*   Updated: 2019/10/19 23:28:33 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"

//
#include <stdio.h>
//

typedef struct		s_cor
{
    int				x;
	int				y;
}					t_cor;

typedef struct		s_set
{
	char			*line;
	char			**board;
	char			*p1;
	char			*p2;
	int				is_first;
	int				size;
	int				point;
	char			**token;
	t_cor			board_size;
	t_cor			token_size;
	t_cor			bestspot;
}					t_set;

void	player_data(t_set *f);
void	store_data(t_set *f);

#endif
