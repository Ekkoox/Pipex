/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:27:49 by enschnei          #+#    #+#             */
/*   Updated: 2024/06/06 19:27:41 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void first_child(t_pipe *pipe)
{
	int fd;

	fd = open(pipe->file_1, O_RDONLY);
	if (fd == -1)
		return ;
	if (dup2(fd, 0) == -1)
		return ;
	if (dup2(pipe->fd, 1) == -1);
		return 
	exit(0);
}

void second_child(t_pipe *pipe)
{
	int fd;

	fd = open(pipe->file_2, O_WRONLY);
	if (fd == -1)
		return ;
	if (dup2(fd, 1) == -1)
		return ;
	if (dup2(pipe->fd, 0) == -1);
		return ;
	exit(0);
}
// trouver la commande dans le path
//close the pipe
//close the file
