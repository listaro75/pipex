/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:48:15 by luda-cun          #+#    #+#             */
/*   Updated: 2025/01/23 13:51:41 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*ft_remain(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	j = 0;
	while (stash[i] != '\n')
		i++;
	while (stash[i++])
		j++;
	new_stash = (char *)malloc(sizeof(char) * (j + 1));
	if (!new_stash)
		return (NULL);
	i = 0;
	j = 0;
	while (stash[i] != '\n')
		i++;
	while (stash[i++])
	{
		new_stash[j] = stash[i];
		j++;
	}
	return (free(stash), new_stash);
}

char	*ft_line_ret(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	while (j < i + 1)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = 0;
	return (line);
}

char	*ft_new_stach(char *stash, char *buf)
{
	char	*save;

	save = ft_strjoin(stash, buf);
	if (!stash || !buf)
		return (NULL);
	free(stash);
	return (save);
}

char	*ft_line(int fd, char *stash)
{
	char	*buf;
	int		verif;

	if (!stash)
		stash = ft_calloc(1, 1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	verif = 1;
	while (verif > 0)
	{
		verif = read(fd, buf, BUFFER_SIZE);
		if (verif == 0)
			return (free(buf), stash);
		if (verif < 0)
			return (free(buf), free(stash), NULL);
		buf[verif] = 0;
		stash = ft_new_stach(stash, buf);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (stash);
	}
	stash = ft_line(fd, stash);
	if (_verif_stash(stash) == 1)
		return (free(stash), stash = NULL, NULL);
	if (!stash)
		return (NULL);
	line = ft_line_ret(stash);
	if (!ft_strchr(stash, '\n'))
	{
		free(stash);
		stash = NULL;
		return (line);
	}
	stash = ft_remain(stash);
	return (line);
}
