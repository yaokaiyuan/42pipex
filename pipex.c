/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:38:29 by ykai-yua          #+#    #+#             */
/*   Updated: 2024/08/06 01:00:39 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

static void	first_cmd(char **av, char **envp, int *fd)
{
	int	filein;

	filein = open(av[1], O_RDONLY);
	if (filein == -1)
		error(av[1]);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(filein);
	close(fd[1]);
	execute(av[2], envp);
}

static void	second_cmd(char **av, char **envp, int *fd)
{
	int	fileout;

	fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fileout == -1)
		error(av[4]);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fileout);
	close(fd[0]);
	execute(av[3], envp);
}

static pid_t	create_process(void (*func)(char **, char **, int *)
							, char **av, char **envp, int *fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error("fork");
	if (pid == 0)
		func(av, envp, fd);
	return (pid);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error("pipe");
		pid1 = create_process(first_cmd, av, envp, fd);
		pid2 = create_process(second_cmd, av, envp, fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
	{
		ft_putstr_fd("ERROR: Bad arguements\n", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}
