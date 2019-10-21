/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:22:39 by sapark            #+#    #+#             */
/*   Updated: 2019/10/21 00:17:24 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_board(t_set *f, FILE *fptr)
{
	char	*line;
	char	**board;
	int		cnt;
    static int	call = 0;

	line = NULL;
	board = NULL;
	cnt = 0;
	if (call++ > 0)
		free_dpchar(f->board);
	while (get_next_line_lst(0, &line) > 0)
	{
		if (ft_strstr(line, " .") && cnt < f->board_size.y)
		{
			f->board = (char **)malloc(sizeof(char *)*(f->board_size.y + 1));
			f->board[f->board_size.y] = "\0";
			f->board[cnt++] = ft_strdup(line + 4);
		}
		free(line);
	}
	fprintf(fptr, "random\n");
}

void	player_data(t_set *f, FILE *fptr)
{	
	char	*line;
	char	**res;
	char	**blank;

	line = NULL;
	blank = NULL;
	while (get_next_line_lst(0, &line) > 0)
	{
		if (ft_strstr(line, "$$$ "))
			res = ft_strsplit(line, ' ');
		else if (ft_strstr(line, "Plateau") && !f->board_size.x)
		{
			blank = ft_strsplit(line, ' ');
			f->board_size.x = ft_atoi(blank[2]);
			f->board_size.y = ft_atoi(blank[1]);
			free_dpchar(blank);
		}
		free(line);
		if (res && blank)
			break ;
	}
	if (ft_strcmp(res[0], "$$$") || ft_strcmp(res[1], "exec") || ft_strcmp(res[3], ":"))
		return ;
	f->p1 = !ft_strcmp(res[2], "p1") ? "oO" : "xX";
	f->p2 = !ft_strcmp(res[2], "p2") ? "oO" : "xX";
	fprintf(fptr, "f->p1:%s\n", f->p1);
	fprintf(fptr, "f->p2:%s\n", f->p2);
	fprintf(fptr, "xsize:%d\n", f->board_size.x);
	fprintf(fptr, "ysize:%d\n", f->board_size.y);
	free_dpchar(res);
}

// while (get_next_line_lst(0, &line) > 0)
// 	{
// 		if (ft_strstr(line, " .") && cnt < tmp->board_size.y)
// 		{
// 			tmp->board = (char **)malloc(sizeof(char *)*(tmp->board_size.y + 1));
// 			tmp->board[tmp->board_size.y] = NULL;
// 			tmp->board[cnt++] = ft_strdup(line + 4);
// 		}
// 		free(line);
// 	}
// 	fprintf(fptr, "random\n");

void	piece_data(t_set *f, char *piece_line, FILE *fptr)
{
	char	*line;
	char	**res;
	int		cnt;
	static int	call = 0;
	
	line = NULL;
	res = NULL;
	cnt = 0;
	if (call++ > 0)
		free_dpchar(f->piece);
	res = ft_strsplit(piece_line, ' ');
	f->piece_size.x = ft_atoi(res[2]);
	f->piece_size.y = ft_atoi(res[1]);
	fprintf(fptr, "tmp->piecex :%d\n", f->piece_size.x);
	fprintf(fptr, "tmp->piecey :%d\n", f->piece_size.y);
	while (get_next_line_lst(0, &line) > 0)
	{
		fprintf(fptr, "first\n");
		// if (!ft_strstr(line, "Piece"))
		// {
			f->piece = (char **)malloc(sizeof(char *)*(f->piece_size.y + 1));
			f->piece[f->piece_size.y] = NULL;
			f->piece[cnt] = ft_strdup(line);
			fprintf(fptr, "piece[%d]%s\n", cnt, f->piece[cnt]);
			cnt++;
		// }
		free(line);
	}
	fprintf(fptr, "dd\n");
	free_dpchar(res);
}

void	store_data(t_set *f, FILE *fptr)
{
	char	*line;

	line = NULL;
	while (get_next_line_lst(0, &line) > 0)
	{
		if (ft_strstr(line, " ."))
		{
			fprintf(fptr, "c\n");
			get_board(f, fptr);
			fprintf(fptr, "d\n");
		}
		else if (ft_strstr(line, "Piece"))
		{
			fprintf(fptr, "a\n");
			piece_data(f, line, fptr);
			fprintf(fptr, "b\n");
			break ;
		}
			
			
		free(line);
	}
}
