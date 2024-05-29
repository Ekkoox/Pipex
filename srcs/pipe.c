/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:02:58 by enschnei          #+#    #+#             */
/*   Updated: 2024/05/27 15:32:19 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void army_of_fork(t_pipe *file_1)
{
	int fd[2];	
	int id_fork;

	id_fork = fork();
	if (id_fork == -1)
	{
		ft_printf("Error with the fork");
		exit(EXIT_FAILURE);
	}
	error_exec();
	if (id_fork == 0)
	{
		close (fd[0]);
		write(fd[1], &file_1, sizeof(file_1));
		close (fd[1]);
	}
	else
	{
		close (fd[1]);
		read(fd[0], &file_1, sizeof(file_1));
		close (fd[0]);
	}
}

void create_the_pipe(t_pipe *pipe)
{
	// int pipefd[2];

	// if (pipefd == -1)
	// {
	// 	perror("Error pipe");
	// 	exit(EXIT_FAILURE);	
	// }
	// return ;
}
