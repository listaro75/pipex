/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:16:04 by luda-cun          #+#    #+#             */
/*   Updated: 2025/03/20 12:32:26 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "gnl/get_next_line.h"
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
void	create_children(char **cmd1, char **cmd2, char **envp, char **av);

#endif