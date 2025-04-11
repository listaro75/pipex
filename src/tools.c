/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:03:11 by luda-cun          #+#    #+#             */
/*   Updated: 2025/03/31 14:49:19 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_fd2(int fd[2])
{
	if (fd[0] >= 0)
		close(fd[0]);
	if (fd[1] >= 0)
		close(fd[1]);
}

void	error_pid(int pid)
{
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_printf("%s\n", tab[i++]);
}

char	**change_tab(char **tab, char *cmd)
{
	free(tab[0]);
	tab[0] = ft_strdup(cmd);
	return (tab);
}
