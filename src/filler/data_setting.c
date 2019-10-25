/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:22:39 by sapark            #+#    #+#             */
/*   Updated: 2019/10/25 12:45:55 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	player_data(t_set *f, FILE *fptr)
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
	fprintf(fptr, "f->p1:%s\n", f->p1);
	fprintf(fptr, "f->p2:%s\n", f->p2);
	free_dpchar(res);
}

void	piece_data(t_set *f, char *piece_line, FILE *fptr)
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
	fprintf(fptr, "tmp->piecex :%d\n", f->piece_size.x);
	fprintf(fptr, "tmp->piecey :%d\n", f->piece_size.y);
	while (cnt < f->piece_size.y && get_next_line_lst(0, &line) > 0)
	{
		f->piece[cnt] = ft_strdup(line);
		fprintf(fptr, "piece[%d]%s\n", cnt, f->piece[cnt]);
		cnt++;
		free(line);
	}
	free_dpchar(res);
}

void	board_data(t_set *f, char *board_line, FILE *fptr)
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
		fprintf(fptr, "%s\n", f->board[cnt]);
		cnt++;
		free(line);
	}
	free_dpchar(res);
}

void	store_data(t_set *f, FILE *fptr)
{
	char	*line;

	line = NULL;
	while (get_next_line_lst(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau "))
			board_data(f, line, fptr);
		else if (ft_strstr(line, "Piece "))
		{
			piece_data(f, line, fptr);
			break ;
		}
		free(line);
	}
}

