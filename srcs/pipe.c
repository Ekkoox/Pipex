/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:02:58 by enschnei          #+#    #+#             */
/*   Updated: 2024/06/13 14:52:57 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void create_the_pipe(t_pipex *pipex)
{
	if (pipe(pipex->fd) == -1)
	{
		perror("Error pipe\n");
		exit(EXIT_FAILURE);	
	}
}

void army_of_fork(t_pipex *pipex)
{	
	int id_fork;

	create_the_pipe(pipex);
	id_fork = fork();
	if (id_fork == -1)
	{
		ft_printf("Error with the fork\n");
		exit(EXIT_FAILURE);
	}
	if (id_fork == 0)
		first_child(pipex);
	id_fork = fork();
	if (id_fork == -1)
	{
		ft_printf("Error with the fork\n");
		exit(EXIT_FAILURE);
	}
	if (id_fork == 0)
		second_child(pipex);
}

