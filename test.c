#include "pipex.h"

// int main(int ac, char **av)
// {
// 	int fd;

// 	fd = open(av[ac - 1], O_RDWR);
// 	printf("BOnjour\n");
// }


int	main(int ac, char **av)
{
	int pipe1[2];
	int pipe2[2];
	char	*line;

	pipe(pipe1);
	pipe(pipe2);

	int fd1 = open(av[1], O_RDWR);
	pipe1[0] = fd1;
}
int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	char	*pathcmd1;
	char	*pathcmd2;
	int		fd[2];

	if (envp == NULL)
		return (perror("No environnement\n"), 1);
	if (argc != 5)
		perror("error\n");
	fd[0] = open(argv[1], O_RDWR);
	paths = the_paths(envp);
	fd[1] = open(argv[4], O_RDWR);
	if (fd[1] == -1)
		create_outfile(argv, envp, paths);
		
	pathcmd1 = verif_ex(paths, argv[2]);
	if (pathcmd1 == NULL)
		return (free_tab(paths), perror("cmd2 NULL"), 1);
	pathcmd2 = verif_ex(paths, argv[3]);
	if (pathcmd2 == NULL)
		return (free(pathcmd1), free_tab(paths), perror("cmd2 NULL"), 1);
	execution(pathcmd1, pathcmd2, argv, envp);
	ft_printf("*    fin   *\n");
	close(fd[0]);
	close(fd[1]);
	return (free(pathcmd1), free(pathcmd2), free_tab(paths), 0);
}