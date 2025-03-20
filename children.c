/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:08:26 by luda-cun          #+#    #+#             */
/*   Updated: 2025/03/20 13:47:36 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



void	create_children(char **cmd1, char **cmd2, char **envp, char **av)
{
	int	pid1;
	int	fd[2];
	int	pipe1[2];
	int	pipe2[2];

	(void)cmd2;
	pipe(pipe1);
	pipe(pipe2);
	fd[0] = open(av[1], O_RDWR);
	fd[1] = open(av[4], O_RDWR);
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
		{
			perror("dup2");
		}
		if (execve(cmd1[0], cmd1, envp) == -1)
		{
			perror("non");
		}
		exit(EXIT_SUCCESS);
	}
}
