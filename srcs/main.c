/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:54:39 by enschnei          #+#    #+#             */
/*   Updated: 2024/06/06 19:28:21 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **ev)
{
	t_pipe pipe;
	
	if (ac != 5)
		exit(0);
	pipe.file_1 = av[1];
	pipe.file_2 = av[4];
	pipe.command_1 = ft_split(av[2], ' ');
	pipe.command_2 = ft_split(av[3], ' ');

	find_the_path_and_split(ac, av, ev, &pipe);
	army_of_fork(pipe.file_1);
	ft_free(pipe.command_1, ft_count_line_split(pipe.command_1));
	ft_free(pipe.command_2, ft_count_line_split(pipe.command_2));
    return (0);
}	
