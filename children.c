/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:08:26 by luda-cun          #+#    #+#             */
/*   Updated: 2025/03/25 14:38:10 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	children_processe2(int pipe1[2], int fd[2], char **cmd2, char **envp)
{
	if (dup2(pipe1[0], STDIN_FILENO) == -1)
	{
		perror("dup2 pipe read");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 output");
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	close(fd[1]);
	close(pipe1[0]);
	close(pipe1[1]);
	if (execve(cmd2[0], cmd2, envp) == -1)
	{
		perror(cmd2[0]);
		exit(EXIT_FAILURE);
	}
}

void	close_fd(int pipe1[2], int fd[2])
{
	if (fd[0] >= 0)  // On vérifie que fd[0] est bien valide avant de le fermer
		close(fd[0]);
	if (fd[1] >= 0)  // Même chose pour fd[1]
		close(fd[1]);
	close(pipe1[0]);
	close(pipe1[1]);
}

void	children_processe1(int pipe1[2], int fd[2], char **cmd1, char **envp)
{
	dup2(fd[0], STDIN_FILENO);
	if (dup2(pipe1[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 pipe write");
		exit(EXIT_FAILURE);
	}
	close_fd(pipe1, fd);
	if (execve(cmd1[0], cmd1, envp) == -1)
	{
		perror("execve cmd1");
		exit(EXIT_FAILURE);
	}
}

void	init_fd_pipe(int fd[2], int pipe1[2], char **av)
{
	fd[0] = open(av[1], O_RDONLY);
	if (fd[0] == -1)
		perror(av[1]);
	fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] == -1)
	{
		perror(av[4]);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipe1) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

void	create_children(char **cmd1, char **cmd2, char **envp, char **av)
{
	int	fd[2];
	int	pipe1[2];
	int	pid1;
	int	pid2;

	init_fd_pipe(fd, pipe1, av);
	if (fd[0] > 0)
	{
		pid1 = fork();
		if (pid1 < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid1 == 0)
			children_processe1(pipe1, fd, cmd1, envp);
	}
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid2 == 0)
		children_processe2(pipe1, fd, cmd2, envp);
	close_fd(pipe1, fd);
	// waitpid(pid1, NULL, 0);
	// waitpid(pid2, NULL, 0);
}
