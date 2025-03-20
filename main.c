/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:15:37 by luda-cun          #+#    #+#             */
/*   Updated: 2025/03/20 16:31:24 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execution(char *cmd1, char *cmd2, char **argv, char **envp)
{
	char	**cmdopt1;
	char	**cmdopt2;

	cmdopt1 = ft_split(argv[2], ' ');
	cmdopt2 = ft_split(argv[3], ' ');
	cmdopt1 = change_tab(cmdopt1, cmd1);
	cmdopt2 = change_tab(cmdopt2, cmd2);
	ft_printf("cmd 1 = %s %s\n", cmdopt1[0], cmdopt1[1]);
	ft_printf("cmd 2 = %s %s\n", cmdopt2[0], cmdopt2[1]);
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
	return  (cmdtouch);
}

void	create_outfile(char **av, char **envp, char **paths)
{
	int		pid1;
	char	*cmdtouch;
	char	**outfile;

	cmdtouch = verif_ex(paths, "touch");
	outfile = ft_cmdtouch(cmdtouch, av[4]);
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)
	{
		if (execve(outfile[0], outfile, envp) == -1)
		{
			perror("non");
		}
		exit(EXIT_SUCCESS);
	}
	return (free(cmdtouch), free_tab(outfile));
}



int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	int		fd[2];
	char	*pathcmd1;
	char	*pathcmd2;
	// verification des arguments et de l'environement
	if (envp == NULL)
		return (perror("No environnement\n"), 1);
	if (argc != 5)
		perror("error\n");
	//recuperation du chemin pour les execution 
	fd[0] = open(argv[1], O_RDWR);
	paths = the_paths(envp);
	//verifier si notre outfile existe si il n'existe pas je le cree
	fd[1] = open(argv[4], O_RDWR);
	if (fd[1] == -1)
		create_outfile(argv, envp, paths);
	//recupere les chemin des cmd
	pathcmd1 = verif_ex(paths, argv[2]);
	if (pathcmd1 == NULL)
		return (free_tab(paths), perror("cmd2 NULL"), 1);
	pathcmd2 = verif_ex(paths, argv[3]);
	if (pathcmd2 == NULL)
		return (free(pathcmd1), free_tab(paths), perror("cmd2 NULL"), 1);
	execution(pathcmd1, pathcmd2, argv, envp);
	return (close(fd[0]), close(fd[1]),free(pathcmd1), free(pathcmd2), free_tab(paths), 0);
}
