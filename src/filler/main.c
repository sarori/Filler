#include "filler.h"

int	main(void)
{
	FILE *fptr = fopen("result.txt", "w");
	if (!fptr)
		return (0);

	t_set	*f;

	f = ft_memalloc(sizeof(t_set));
	if (!f->p1)
		player_data(f, fptr);
	
	store_data(f, fptr);
	// get_board(f, fptr);
	
	// while (1)
	// {
	// 	store_data(f);
		//place_piece(f)
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