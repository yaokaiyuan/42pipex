#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i])
			i++;
		write(fd, s, i);
	}
}

void	error(char *infile)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(infile, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

int main(void)
{
	// Force an error for demonstration purposes
	errno = EACCES;
	error("testfile.txt");
	return 0;
}