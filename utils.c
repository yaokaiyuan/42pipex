/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:03:03 by ykai-yua          #+#    #+#             */
/*   Updated: 2024/08/08 20:12:39 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	error(const char *infile, int err)
{
	if (err == 1)
	{
		ft_putstr_fd(infile, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("command not found\n", 2);
		exit(127);
	}
	else
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(infile, 2);
		ft_putstr_fd(": ", 2);
		if (err == 2)
			ft_putstr_fd("No such file or directory", 2);
		else
			ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(EXIT_FAILURE);
	}
}

char	**get_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_memcmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

static char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	path = check_cmd(cmd);
	if (path)
		return (path);
	paths = return_paths(cmd, envp);
	i = 0;
	while (paths && paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
		{
			free_array(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_array(paths);
	return (NULL);
}

static int	check_cmd_exist(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	paths = get_paths(envp);
	i = 0;
	while (paths && paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, X_OK) == 0)
		{
			free_array(paths);
			free(path);
			return (0);
		}
		free(path);
		i++;
	}
	free_array(paths);
	return (1);
}

void	execute(char *cmd_str, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(cmd_str, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		if (check_cmd_exist(cmd[0], envp) == 1)
		{
			free_array(cmd);
			error(cmd_str, 1);
		}
		else
			error(cmd_str, 0);
	}
	if (execve(path, cmd, envp) == -1)
		error(cmd_str, 0);
	free_array(cmd);
	free(path);
}
