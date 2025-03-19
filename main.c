/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:15:37 by luda-cun          #+#    #+#             */
/*   Updated: 2025/03/19 15:44:11 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


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


void	create_children(char **cmd1, char **cmd2, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int	status;

	// Premier enfant
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)
	{ // Code de l'enfant 1
		if (execve(cmd1[0], cmd1, envp) == -1)
		{
			perror("non");
		}
		exit(EXIT_SUCCESS);
	}
	// Deuxième enfant
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid2 == 0)
	{ // Code de l'enfant 2
		wait(NULL);
		if (execve(cmd2[0], cmd2, envp) == -1)
		{
			perror("faille");
		}
		exit(EXIT_SUCCESS);
	}
	// Le parent attend la fin des enfants
	wait(&status);
	wait(&status);
}

char	**change_tab(char **tab, char *cmd)
{
	free(tab[0]);
	tab[0] = ft_strdup(cmd);
	return (tab);
}

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
	create_children(cmdopt1, cmdopt2, envp);
	return (free_tab(cmdopt1), free_tab(cmdopt2));
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	char	*pathcmd1;
	char	*pathcmd2;


	if (envp == NULL)
		return (perror("No environnement\n"), 1);
	if (argc != 5)
		ft_printf("error\n");
	paths = the_paths(envp);
	pathcmd1 = verif_ex(paths, argv[2]);
	if (pathcmd1 == NULL)
		return (free_tab(paths), perror("cmd2 NULL"), 1);
	pathcmd2 = verif_ex(paths, argv[3]);
	if (pathcmd2 == NULL)
		return (free(pathcmd1), free_tab(paths), perror("cmd2 NULL"), 1);
	execution(pathcmd1, pathcmd2, argv, envp);
	ft_printf("*    fin   *\n");
	return (free(pathcmd1), free(pathcmd2), free_tab(paths), 0);
}
