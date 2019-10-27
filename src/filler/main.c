/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:52:32 by sapark            #+#    #+#             */
/*   Updated: 2019/10/25 20:27:43 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	t_set	*f;

	f = ft_memalloc(sizeof(t_set));
	if (!f->p1)
		player_data(f);
	while (1)
	{
		store_data(f);
		play(f);
	}
	free_dpchar(f->board);
	free_dpchar(f->piece);
	free_dpint(f);
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