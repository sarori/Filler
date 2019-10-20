#include "filler.h"

void	player_data(t_set *f)
{
	FILE *fptr = fopen("result.txt", "w");
	if (!fptr)
		return ;
	
	t_set	*tmp;
	char	*line;
	char	**res;

	tmp = f;
	line = NULL;
	
	// if (!tmp->is_first)
	// {
	// 	tmp->is_first +=1;
	// 	return ;
	// }
	while (get_next_line_lst(0, &line) > 0)
	{
		if (ft_strstr(line, "$$$ "))
			res = ft_strsplit(line, ' ');
		free(line);
	}
	if (ft_strcmp(res[0], "$$$") || ft_strcmp(res[1], "exec") || ft_strcmp(res[3], ":"))
		return ;
	f->p1 = !ft_strcmp(res[2], "p1") ? "oO" : "xX";
	f->p2 = !ft_strcmp(res[2], "p2") ? "oO" : "xX";
	free_dpchar(res);
}

// while (get_next_line_lst(0, &line) > 0)
// {
// 	if (ft_strstr(line, " ."))
// 	{
// 		// line = ft_strtrimby(line, ' ');
// 		// board = ft_strdup(line + 4);
// 		tmp->board = (char **)malloc(sizeof(char *)*(tmp->board_size.y + 1));
// 		tmp->board[tmp->board_size.y] = NULL;
// 		tmp->board[cnt++] = ft_strdup(line + 4);
// 		printf("%s\n", board);
// 		// tmp->board = board;
// 		printf("%s\n", tmp->board[cnt]);
// 	}
		
// 		// res = ft_strsplit(line, ' ');
// 	// printf("%s\n", line);
// 	free(line);
// }


	void	store_data(t_set *f)
	{
		FILE *fptr = fopen("result.txt", "w");
		if (!fptr)
			return ;

		char	*line;
		char	**tmp;

		line = NULL;
		tmp = NULL;
		while (get_next_line_lst(0, &line) > 0)
		{
			fprintf(fptr, "%s\n", line);
			if (ft_strstr(line, "Plateau"))
			{
				tmp = ft_strsplit(line, ' ');
				f->board_size.x = ft_atoi(tmp[2]);
				f->board_size.y = ft_atoi(tmp[1]);
				// free_dpchar(tmp);
			}
			else if (ft_strstr(line, "Piece"))
			{
				tmp = ft_strsplit(line, ' ');
				f->token_size.x = ft_atoi(tmp[2]);
				f->token_size.y = ft_atoi(tmp[1]);
				// free_dpchar(tmp);
			}
			free(line);
			
			
		}
		fprintf(fptr,"boardx:%d\n", f->board_size.x);
		fprintf(fptr,"boardy:%d\n", f->board_size.y);
		fprintf(fptr, "tokenx:%d\n", f->token_size.x);
		fprintf(fptr, "tokeny:%d\n", f->token_size.y);
		// fprintf(fptr, "abcdefaoisjdfoiwjeoifjowijeofijeijfdududud\n\n");
		//free하기

}

int	main(void)
{
	t_set	*f;

	// FILE *fptr = fopen("result.txt", "w");
	// if (!fptr)
	// 	return (0);
	// // fprintf(fptr, "");
	// fprintf(fptr, "ccc\n");

	f = ft_memalloc(sizeof(t_set));
	// if (!f->p1)
	player_data(f);
	// while (1)
	// {
	// 	store_data(filler);
	// }
	return (0);
}



	

	// char	*line = NULL;
    // char    *input;
	// int		fd = open(av[1], O_RDONLY);

	// while (get_next_line(fd, &line) > 0)
	// {
	// 	ft_printf("[read line] : %s\n", line);
    //     input = ft_strjoin(line, "\n");
    //     input = ft_strjoinfree(line, "\n", 1);
    //     // ft_printf("input:%s\n", input);
	// 	// free(line);
	// 	line = NULL;
	// }
    // ft_printf("input:ss%s\n", input);


// int	main(int ac, char **av)
// {			
// 	if (ac != 2)
// 		return (0);

// 	char	*line = NULL;
// 	int		fd = open(av[1], O_RDONLY);

// 	while (get_next_line(fd, &line) > 0)
// 	{
// 		printf("[read line] : %s\n", line);
// 		free(line);
// 		line = NULL;
// 	}
// 	return (0);
// }