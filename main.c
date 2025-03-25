/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:15:37 by luda-cun          #+#    #+#             */
/*   Updated: 2025/03/25 16:01:06 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execution(char *cmd1, char *cmd2, char **argv, char **envp)
{
	char	**cmdopt1;
	char	**cmdopt2;

	cmdopt1 = NULL;
	cmdopt2 = NULL;
	if (cmd1)
	{
		cmdopt1 = ft_split(argv[2], ' ');
		cmdopt1 = change_tab(cmdopt1, cmd1);
	}
	if (cmd2)
	{
		cmdopt2 = ft_split(argv[3], ' ');
		cmdopt2 = change_tab(cmdopt2, cmd2);
	}
	create_children(cmdopt1, cmdopt2, envp, argv);
	return (free_tab(cmdopt1), free_tab(cmdopt2));
}

char	**ft_cmdtouch(char *cmd, char *opt)
{
	char	**cmdtouch;

	cmdtouch = (char **)malloc(sizeof(char *) * 3);
	cmdtouch[0] = ft_strdup(cmd);
	cmdtouch[1] = ft_strdup(opt);
	cmdtouch[2] = 0;
	return (cmdtouch);
}

void	create_outfile(char **av, char **envp, char **paths, int fd)
{
	int		pid1;
	char	*cmdtouch;
	char	**outfile;

	cmdtouch = verif_ex(paths, "touch");
	outfile = ft_cmdtouch(cmdtouch, av[4]);
	if (fd >= 0)
		close(fd);
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("error fork");
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)
	{
		if (execve(outfile[0], outfile, envp) == -1)
		{
			perror("outfile no create");
		}
		exit(EXIT_SUCCESS);
	}
	return (free(cmdtouch), free_tab(outfile));
}

void	ft_error(char **envp, int ac)
{
	if (envp == NULL)
	{
		perror("No environnement\n");
		exit(EXIT_FAILURE);
	}
	if (ac != 5)
	{
		ft_printf("no argument");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	int		fd[2];
	char	*pathcmd1;
	char	*pathcmd2;

	ft_error(envp, argc);
	fd[0] = open(argv[1], O_RDWR);
	paths = the_paths(envp);
	fd[1] = open(argv[4], O_RDWR);
	if (fd[1] == -1)
		create_outfile(argv, envp, paths, fd[1]);
	pathcmd1 = verif_ex(paths, argv[2]);
	if (pathcmd1 == NULL)
		perror(argv[2]);
	pathcmd2 = verif_ex(paths, argv[3]);
	if (pathcmd2 == NULL)
		perror(argv[3]);
	execution(pathcmd1, pathcmd2, argv, envp);
	close_fd2(fd);
	return (free(pathcmd1), free(pathcmd2), free_tab(paths), 0);
}
