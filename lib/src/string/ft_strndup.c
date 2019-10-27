/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 01:03:46 by sapark            #+#    #+#             */
/*   Updated: 2019/10/26 19:18:10 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*res;
	int		i;

	if (!(res = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && n > i)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
