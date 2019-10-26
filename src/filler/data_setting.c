/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:22:39 by sapark            #+#    #+#             */
/*   Updated: 2019/10/26 01:08:04 by sapark           ###   ########.fr       */
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


int		ft_c_cnt(char *str, char c)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (str[++i])
		if (str[i] == c)
			cnt++;
	return (cnt);
}

void	get_info_of(t_coor *size, char *line)
{
	
	char	**arr;
	char	*tmp;

	if (ft_c_cnt(line, ' ') != 2)
		return ;
	tmp = ft_strtrimby(line, ':');
	arr = ft_strsplit(tmp, ' ');
	free(tmp);
	size->y = ft_atoi(arr[1]);
	size->x = ft_atoi(arr[2]);
	free_dpchar(arr);
}

void	get_current_map(t_set *f, int lines, FILE *fptr)
{
	fprintf(fptr, "get_current_map\n");
	char	*tmp;
	int		line;
	static int	call = 0;
	
	line = -1;
	tmp = NULL;
	if (call++ > 0)
		free_dpchar(f->board);
	f->board = (char **)malloc(sizeof(char *) * lines);
	f->board[lines - 1] = NULL;
	while (++line < lines && get_next_line_lst(0, &tmp) > 0)
	{
		if (line != 0)
			f->board[line - 1] = ft_strdup(tmp + 4);
		free(tmp);
	}
}

void	get_current_piece(t_set *f, int lines, FILE *fptr)
{
	fprintf(fptr, "get_current_piece\n");
	char	*tmp;
	int		line;
	static int	call = 0;
	
	line = -1;
	tmp = NULL;
	if (call++ > 0)
		free_dpchar(f->piece);
	f->piece = (char **)malloc(sizeof(char *) * (lines + 1));
	f->piece[lines] = NULL;
	while (++line < lines && get_next_line_lst(0, &tmp) > 0)
	{
		f->piece[line] = ft_strdup(tmp);
		free(tmp);
		if (line == lines - 1)
			break ;
	}
}

void	store_data(t_set *f, FILE *fptr)
{

	fprintf(fptr, "storedata\n");
	char	*line;

	line = NULL;
	while (get_next_line_lst(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
		{
			get_info_of(&(f->board_size), line);
			get_current_map(f, f->board_size.y, fptr);
		}
			
		else if (ft_strstr(line, "Piece"))
		{
			get_info_of(&(f->piece_size), line);
			free(line);
			get_current_piece(f, f->piece_size.y, fptr);
			break ;
		}
		free(line);
	}
}













// void	piece_data(t_set *f, char *piece_line, FILE *fptr)
// {
// 	fprintf(fptr, "piecedata\n");
// 	char		*line;
// 	char		**res;
// 	int			cnt;
// 	static int	count = 0;
	
// 	line = NULL;
// 	res = NULL;
// 	cnt = 0;
// 	if (count++ > 0)
// 		free_dpchar(f->piece);
// 	res = ft_strsplit(piece_line, ' ');
// 	f->piece_size.x = ft_atoi(res[2]);
// 	f->piece_size.y = ft_atoi(res[1]);
// 	f->piece = (char **)malloc(sizeof(char *)*(f->piece_size.y + 1));
// 	f->piece[f->piece_size.y] = NULL;
// 	fprintf(fptr, "tmp->piecex :%d\n", f->piece_size.x);
// 	fprintf(fptr, "tmp->piecey :%d\n", f->piece_size.y);
// 	while (cnt < f->piece_size.y && get_next_line_lst(0, &line) > 0)
// 	{
// 		f->piece[cnt] = ft_strdup(line);
// 		fprintf(fptr, "piece[%d]%s\n", cnt, f->piece[cnt]);
// 		cnt++;
// 		free(line);
// 	}
// 	free_dpchar(res);
// }

// void	board_data(t_set *f, char *board_line, FILE *fptr)
// {
// 	fprintf(fptr, "boarddata\n");
// 	char	*line;
// 	char	**res;
// 	int		cnt;
// 	static int	count = 0;

// 	line = NULL;
// 	res = NULL;
// 	cnt = 0;
// 	if (count++ > 0)
// 		free_dpchar(f->board);
// 	res = ft_strsplit(board_line, ' ');
// 	f->board_size.x = ft_atoi(res[2]);
// 	f->board_size.y = ft_atoi(res[1]);
// 	f->board = (char **)malloc(sizeof(char *)*(f->board_size.y + 1));
// 	f->board[f->board_size.y] = NULL;
// 	if (cnt == 0 && get_next_line_lst(0, &line) > 0)
// 		free(line);
// 	while (cnt < f->board_size.y && get_next_line_lst(0, &line) > 0)
// 	{
// 		f->board[cnt] = ft_strdup(line + 4);
// 		fprintf(fptr, "%s\n", f->board[cnt]);
// 		cnt++;
// 		free(line);
// 	}
// 	free_dpchar(res);
// }




// void	piece_data(t_set *f, char *piece_line, FILE *fptr)
// {
// 	fprintf(fptr, "piecedata\n");
// 	char		*line;
// 	char		**res;
// 	int			cnt;
// 	static int	count = 0;
	
// 	line = NULL;
// 	res = NULL;
// 	cnt = 0;
// 	if (count++ > 0)
// 		free_dpchar(f->piece);
// 	res = ft_strsplit(piece_line, ' ');
// 	f->piece_size.x = ft_atoi(res[2]);
// 	f->piece_size.y = ft_atoi(res[1]);
// 	f->piece = (char **)malloc(sizeof(char *)*(f->piece_size.y + 1));
// 	f->piece[f->piece_size.y] = NULL;
// 	fprintf(fptr, "tmp->piecex :%d\n", f->piece_size.x);
// 	fprintf(fptr, "tmp->piecey :%d\n", f->piece_size.y);
// 	while (cnt < f->piece_size.y && get_next_line_lst(0, &line) > 0)
// 	{
// 		f->piece[cnt] = ft_strdup(line);
// 		fprintf(fptr, "piece[%d]%s\n", cnt, f->piece[cnt]);
// 		cnt++;
// 		free(line);
// 	}
// 	free_dpchar(res);
// }

// void	board_data(t_set *f, char *board_line, FILE *fptr)
// {
// 	fprintf(fptr, "boarddata\n");
// 	char	*line;
// 	char	**res;
// 	int		cnt;
// 	static int	count = 0;

// 	line = NULL;
// 	res = NULL;
// 	cnt = 0;
// 	if (count++ > 0)
// 		free_dpchar(f->board);
// 	res = ft_strsplit(board_line, ' ');
// 	f->board_size.x = ft_atoi(res[2]);
// 	f->board_size.y = ft_atoi(res[1]);
// 	f->board = (char **)malloc(sizeof(char *)*(f->board_size.y + 1));
// 	f->board[f->board_size.y] = NULL;
// 	if (cnt == 0 && get_next_line_lst(0, &line) > 0)
// 		free(line);
// 	while (cnt < f->board_size.y && get_next_line_lst(0, &line) > 0)
// 	{
// 		f->board[cnt] = ft_strdup(line + 4);
// 		fprintf(fptr, "%s\n", f->board[cnt]);
// 		cnt++;
// 		free(line);
// 	}
// 	free_dpchar(res);
// }

// void	store_data(t_set *f, FILE *fptr)
// {
// 	fprintf(fptr, "storedata\n");
// 	char	*line;

// 	line = NULL;
// 	while (get_next_line_lst(0, &line) > 0)
// 	{
// 		if (ft_strstr(line, "Plateau "))
// 			board_data(f, line, fptr);
// 		else if (ft_strstr(line, "Piece "))
// 		{
// 			piece_data(f, line, fptr);
// 			break ;
// 		}
// 		free(line);
// 	}
// }

