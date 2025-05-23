/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:16:04 by luda-cun          #+#    #+#             */
/*   Updated: 2025/03/31 14:53:03 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/inc/ft_printf.h"
# include "libft/inc/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

char	*ft_delegal(char *str);
int		ft_chrpath(char *str);
char	**the_paths(char **envp);
char	*verif_ex(char **paths, char *cmd);
void	free_tab(char **tab);
void	print_tab(char **tab);
void	free_tab(char **tab);
char	**change_tab(char **tab, char *cmd);
int		create_children(char **cmd1, char **cmd2, char **envp, char **av);
void	error_pid(int pid);
void	close_fd2(int fd[2]);

#endif