/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:54:39 by enschnei          #+#    #+#             */
/*   Updated: 2024/06/13 15:29:53 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **ev)
{
	t_pipex pipex;
	
	
	if (ac != 5)
		exit(0);
	pipex.av = av;
	pipex.ev = ev;
	pipex.file_1 = av[1];
	pipex.file_2 = av[4];
	pipex.command_1 = ft_split(av[2], ' ');
	pipex.command_2 = ft_split(av[3], ' ');

	find_the_path_and_split(ac, av, ev, &pipe);
	army_of_fork(pipex.file_1);
	ft_free(pipex.command_1, ft_count_line_split(pipex.command_1));
	ft_free(pipex.command_2, ft_count_line_split(pipex.command_2));
    return (0);
}	
