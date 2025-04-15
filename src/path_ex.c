/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_ex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:22:11 by luda-cun          #+#    #+#             */
/*   Updated: 2025/04/15 12:14:04 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_chrpath(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 'P')
		i++;
	if (str[i] == 'A')
		i++;
	if (str[i] == 'T')
		i++;
	if (str[i] == 'H' && str[i + 1] == '=')
	{
		return (0);
	}
	return (1);
}

char	*ft_delegal(char *str)
{
	int		i;
	int		j;
	char	*new_path;

	i = 0;
	j = 0;
	while (str && str[i])
	{
		if (str[i] == '=')
		{
			i++;
			break ;
		}
		i++;
	}
	new_path = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!new_path)
		return (NULL);
	while (str[i])
		new_path[j++] = str[i++];
	new_path[j] = 0;
	return (free(str), new_path);
}

char	**the_paths(char **envp)
{
	int		i;
	int		verif;
	char	*path;
	char	**paths;

	i = 0;
	verif = 0;
	while (envp[i])
	{
		if (ft_chrpath(envp[i]) == 0)
		{
			verif++;
			path = ft_strdup(envp[i]);
			if (!path)
				exit(EXIT_FAILURE);
		}
		i++;
	}
	if (verif == 0)
		exit(EXIT_FAILURE);
	path = ft_delegal(path);
	paths = ft_split(path, ':');
	if (!paths)
		return (NULL);
	return (free(path), paths);
}

char	*verif_ex(char **paths, char *cmd)
{
	char	*slashcmd;
	char	**splitcmd;
	char	*path;
	int		i;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	splitcmd = ft_split(cmd, ' ');
	if (splitcmd == NULL || splitcmd[0] == NULL)
		return (free(splitcmd), NULL);
	slashcmd = ft_strjoin("/", splitcmd[0]);
	if (!slashcmd)
		return (free(splitcmd), ft_putstr_fd("Error malloc\n", 2), NULL);
	while (paths[i] != NULL)
	{
		path = ft_strjoin(paths[i], slashcmd);
		if (access(path, X_OK) == 0)
			return (free(slashcmd), free_tab(splitcmd), path);
		free(path);
		i++;
	}
	return (free_tab(splitcmd), free(slashcmd), NULL);
}
