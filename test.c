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