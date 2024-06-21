/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:54:39 by enschnei          #+#    #+#             */
/*   Updated: 2024/06/21 16:44:01 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **ev)
{
	t_pipex	pipex;

	if (ac != 5)
		exit(EXIT_FAILURE);
	ft_bzero(&pipex, sizeof(t_pipex));
	pipex.ev = ev;
	pipex.file_1 = av[1];
	pipex.file_2 = av[4];
	pipex.command_1 = ft_split(av[2], ' ');
	pipex.command_2 = ft_split(av[3], ' ');
	find_the_path(ac, av, ev, &pipex);
	split_the_path(&pipex);
	army_of_fork(&pipex);
	wait(NULL);
	wait(NULL);
	free_all(&pipex);
	return (0);
}
