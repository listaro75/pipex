/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:15:37 by luda-cun          #+#    #+#             */
/*   Updated: 2025/04/15 12:39:58 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	execution(char *cmd1, char *cmd2, char **argv, char **envp)
{
	char	**cmdopt1;
	char	**cmdopt2;
	int		i;
	int		status;

	i = 0;
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
	i = create_children(cmdopt1, cmdopt2, envp, argv);
	while (i)
	{
		wait(&status);
		i--;
	}
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

void	ft_error(char **envp, int ac)
{
	if (!envp || !envp[0])
	{
		ft_putstr_fd("No environnement\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ac != 5)
	{
		ft_printf("No argument");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	char	*pathcmd1;
	char	*pathcmd2;

	ft_error(envp, argc);
	paths = the_paths(envp);
	pathcmd1 = verif_ex(paths, argv[2]);
	if (pathcmd1 == NULL)
	{
		ft_putstr_fd("zsh: command not found: ", 2);
		ft_putstr_fd(argv[2], 2);
		ft_putstr_fd("\n", 2);
	}
	pathcmd2 = verif_ex(paths, argv[3]);
	if (pathcmd2 == NULL)
	{
		ft_putstr_fd("zsh: command not found: ", 2);
		ft_putstr_fd(argv[3], 2);
		ft_putstr_fd("\n", 2);
	}
	execution(pathcmd1, pathcmd2, argv, envp);
	return (free(pathcmd1), free(pathcmd2), free_tab(paths), 0);
}
