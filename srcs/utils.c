/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:27:49 by enschnei          #+#    #+#             */
/*   Updated: 2024/06/13 15:32:27 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void first_child(t_pipex *pipex)
{
	int fd;

	fd = open(pipex->file_1, O_RDONLY);
	if (fd == -1)
		return ;
	if (dup2(fd, 0) == -1)
		return ;
	if (dup2(pipex->fd[1], 1) == -1)
		return ;
	execve(get_the_command(pipex), pipex->av, pipex->ev);
	exit(0);
}

void second_child(t_pipex *pipex)
{
	int fd;

	fd = open(pipex->file_2, O_WRONLY);
	if (fd == -1)
		return ;
	if (dup2(fd, 1) == -1)
		return ;
	if (dup2(pipex->fd[0], 0) == -1)
		return ;
	execve(get_the_command(pipex), pipex->av, pipex->ev);
	exit(0);
}

//close the pipe
//close the file
// error exec, access
//tout bien free