/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:18:37 by ykai-yua          #+#    #+#             */
/*   Updated: 2024/08/08 20:13:04 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"

void	free_array(char **array);
void	error(const char *infile, int err);
char	**get_paths(char **envp);
char	**return_paths(char *cmd, char **envp);
char	*check_cmd(char *cmd);
void	execute(char *cmd_str, char **envp);

#endif