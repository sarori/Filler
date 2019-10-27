/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:52:32 by sapark            #+#    #+#             */
/*   Updated: 2019/10/26 20:05:34 by sapark           ###   ########.fr       */
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
	free_dpint(f);
	free_dpchar(f->board);
	free_dpchar(f->piece);
	return (0);
}
