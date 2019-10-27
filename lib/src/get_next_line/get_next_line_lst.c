/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 21:17:32 by sapark            #+#    #+#             */
/*   Updated: 2019/10/26 19:18:43 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strjoin_len(char *s1, char *s2, int len)
{
	//libft에 넣기
	char	*str;
	char	*res;
	int		n;

	n = (int)ft_strlen(s1) + ++len;
	str = ft_strnew(n);
	res = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2 && --len > 0)
		*str++ = *s2++;
	*str = '\0';
	return (str - (str - res));
}

static char	*ft_freejoin_n(char *tmp, char *buf, int read_cnt)
{
	//libft에 넣기
	char	*line;

	line = tmp;
	tmp = ft_strjoin_len(tmp, buf, read_cnt);
	free(line);
	return (tmp);
}

static t_list	*lst_setting(t_list **head, int fd)
{
	t_list	*tmp;
	
	tmp = (*head);
	if (tmp)
	{
		while (tmp)
		{
			if (fd == (int)tmp->content_size)
				return (tmp);
			tmp = tmp->next;
		}
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(head, tmp);
	return (tmp);
}

int		get_next_line_lst(int fd, char **line)
{
	static t_list	*list = NULL;
	t_list			*head;
	int				read_cnt;
	char			buf[BUFF_SIZE + 1];
	char			*content;

	if (read(fd, buf, 0) == -1 || fd < 0 || !line)
		return (-1);
	head = list;
	list = lst_setting(&head, fd);
	while (!ft_strchr(list->content, '\n') && (read_cnt = read(fd, buf, BUFF_SIZE)))
		list->content = ft_freejoin_n(list->content, buf, read_cnt);
	read_cnt = 0;
	while (((char *)list->content)[read_cnt] && ((char *)list->content)[read_cnt] != '\n')
		++read_cnt;
	*line = ft_strndup(list->content, read_cnt);
	if (((char *)list->content)[read_cnt] ==  '\n')
		read_cnt++;
	content = list->content;
	list->content = ft_strdup(list->content + read_cnt);
	free(content);
	list = head;
	return (read_cnt ? 1 : 0);
}