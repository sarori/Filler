#include "filler.h"

void	player_data(t_set *filler, int fd)
{
	FILE *fptr = fopen("result.txt", "w");
	
	if (!fptr)
		return ;
	// fprintf(fptr, "");
	
	t_set	*tmp;
	char	*line;
	char	*board;
	int		cnt;
	// char	**res;

	tmp = filler;
	line = NULL;
	board = NULL;
	cnt = 0;
	fprintf(fptr, "cnt : %d\n", cnt);
	
	// if (!tmp->is_first)
	// {
	// 	tmp->is_first +=1;
	// 	return ;
	// }
	printf("%d\n", tmp->board_size.y);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, " ."))
		{
			// line = ft_strtrimby(line, ' ');
			// board = ft_strdup(line + 4);
			tmp->board = (char **)malloc(sizeof(char *)*(tmp->board_size.y + 1));
			tmp->board[tmp->board_size.y] = NULL;
			tmp->board[cnt++] = ft_strdup(line + 4);
			printf("%s\n", board);
			// tmp->board = board;
			printf("%s\n", tmp->board[cnt]);
		}
			
			// res = ft_strsplit(line, ' ');
		// printf("%s\n", line);
		free(line);
	}
}
	void	store_data(t_set *filler, int fd)
	{
		FILE *fptr = fopen("result.txt", "w");
		if (!fptr)
			return ;
		// fprintf(fptr, "");
		// fprintf(fptr, "aaaaa\n");

		char	*line;
		char	**tmp;

		line = NULL;
		tmp = NULL;
		fd = 0;
		while (get_next_line_lst(0, &line) > 0)
		{
			fprintf(fptr, "abcdef");
			fprintf(fptr, "%s\n", line);
			if (ft_strstr(line, "Plateau"))
			{
				tmp = ft_strsplit(line, ' ');
				filler->board_size.x = ft_atoi(tmp[2]);
				filler->board_size.y = ft_atoi(tmp[1]);
				// free_dpchar(tmp);
			}
			else if (ft_strstr(line, "Piece"))
			{
				tmp = ft_strsplit(line, ' ');
				filler->token_size.x = ft_atoi(tmp[2]);
				filler->token_size.y = ft_atoi(tmp[1]);
				// free_dpchar(tmp);
			}
			free(line);
			
			
		}
		fprintf(fptr,"boardx:%d\n", filler->board_size.x);
		fprintf(fptr,"boardy:%d\n", filler->board_size.y);
		fprintf(fptr, "tokenx:%d\n", filler->token_size.x);
		fprintf(fptr, "tokeny:%d\n", filler->token_size.y);
		// fprintf(fptr, "abcdefaoisjdfoiwjeoifjowijeofijeijfdududud\n\n");
		//free하기

}

int	main(int ac, char *av[])
{
	// if (ac != 2)
	// 	return (0);
	ac = 1;
	t_set	*filler;

	// FILE *fptr = fopen("result.txt", "w");
	// if (!fptr)
	// 	return (0);
	// // fprintf(fptr, "");
	// fprintf(fptr, "ccc\n");

	int		fd = open(av[1], O_RDONLY);
	filler = ft_memalloc(sizeof(t_set));
	store_data(filler, fd);
	// if (!filler->p1)
	// 	player_data(filler, fd);
	// store_data(filler, fd);
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