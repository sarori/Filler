/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:22:39 by sapark            #+#    #+#             */
/*   Updated: 2019/10/26 19:28:32 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	player_data(t_set *f)
{	
	char	*line;
	char	**res;

	line = NULL;
	while (get_next_line_lst(0, &line) > 0)
	{
		if (ft_strstr(line, "$$$ "))
			res = ft_strsplit(line, ' ');
		free(line);
		if (res)
			break ;
	}
	if (ft_strcmp(res[0], "$$$") || ft_strcmp(res[1], "exec") || ft_strcmp(res[3], ":"))
		return ;
	f->p1 = !ft_strcmp(res[2], "p1") ? "oO" : "xX";
	f->p2 = !ft_strcmp(res[2], "p1") ? "xX" : "oO";
	free_dpchar(res);
}

void	piece_data(t_set *f, char *piece_line)
{
	char		*line;
	char		**res;
	int			cnt;
	static int	count = 0;
	
	line = NULL;
	res = NULL;
	cnt = 0;
	if (count++ > 0)
		free_dpchar(f->piece);
	res = ft_strsplit(piece_line, ' ');
	f->piece_size.x = ft_atoi(res[2]);
	f->piece_size.y = ft_atoi(res[1]);
	f->piece = (char **)malloc(sizeof(char *)*(f->piece_size.y + 1));
	f->piece[f->piece_size.y] = NULL;
	while (cnt < f->piece_size.y && get_next_line_lst(0, &line) > 0)
	{
		f->piece[cnt] = ft_strdup(line);
		cnt++;
		free(line);
	}
	free_dpchar(res);
}

void	board_data(t_set *f, char *board_line)
{
	char	*line;
	char	**res;
	int		cnt;
	static int	count = 0;

	line = NULL;
	res = NULL;
	cnt = 0;
	if (count++ > 0)
		free_dpchar(f->board);
	res = ft_strsplit(board_line, ' ');
	f->board_size.x = ft_atoi(res[2]);
	f->board_size.y = ft_atoi(res[1]);
	f->board = (char **)malloc(sizeof(char *)*(f->board_size.y + 1));
	f->board[f->board_size.y] = NULL;
	if (cnt == 0 && get_next_line_lst(0, &line) > 0)
		free(line);
	while (cnt < f->board_size.y && get_next_line_lst(0, &line) > 0)
	{
		f->board[cnt] = ft_strdup(line + 4);
		cnt++;
		free(line);
	}
	free_dpchar(res);
}

void	store_data(t_set *f)
{
	char	*line;

	line = NULL;
	while (get_next_line_lst(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau "))
			board_data(f, line);
		else if (ft_strstr(line, "Piece "))
		{
			piece_data(f, line);
			break ;
		}
		free(line);
	}
}

