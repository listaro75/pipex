/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:08:26 by luda-cun          #+#    #+#             */
/*   Updated: 2025/04/15 12:37:55 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_fd(int pipe1[2], int fd[2])
{
	if (fd[0] >= 0)
		close(fd[0]);
	if (fd[1] >= 0)
		close(fd[1]);
	if (pipe1[0] >= 0)
		close(pipe1[0]);
	if (pipe1[1] >= 0)
		close(pipe1[1]);
}

void	children_processe2(int pipe1[2], int fd[2], char **cmd2, char **envp)
{
	if (dup2(pipe1[0], STDIN_FILENO) == -1)
	{
		perror("dup2 pipe read");
		close_fd(fd, pipe1);
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 output");
		close_fd(fd, pipe1);
		exit(EXIT_FAILURE);
	}
	close_fd(fd, pipe1);
	if (cmd2 && execve(cmd2[0], cmd2, envp) == -1)
	{
		perror(cmd2[0]);
		exit(EXIT_FAILURE);
	}
}

void	children_processe1(int pipe1[2], int fd[2], char **cmd1, char **envp)
{
	dup2(fd[0], STDIN_FILENO);
	if (dup2(pipe1[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 pipe write");
		close_fd(pipe1, fd);
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
	fd[1] = open(av[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd[1] == -1)
		perror(av[4]);
	if (pipe(pipe1) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

int	create_children(char **cmd1, char **cmd2, char **envp, char **av)
{
	int	fd[2];
	int	pipe1[2];
	int	pid1;
	int	pid2;
	int	i;

	i = 0;
	pid1 = -1;
	init_fd_pipe(fd, pipe1, av);
	if (fd[0] > 0 && cmd1)
	{
		pid1 = fork();
		error_pid(pid1);
		i++;
		if (pid1 == 0)
			children_processe1(pipe1, fd, cmd1, envp);
	}
	pid2 = fork();
	error_pid(pid2);
	i++;
	if (pid2 == 0 && fd[1] >= 0)
		children_processe2(pipe1, fd, cmd2, envp);
	close_fd(pipe1, fd);
	return (i);
}
