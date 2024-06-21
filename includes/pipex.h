/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:56:47 by enschnei          #+#    #+#             */
/*   Updated: 2024/06/17 14:29:31 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		fd[2];
	char	*ligne_path;
	char	*file_1;
	char	*file_2;
	char	**ev;
	char	**command_1;
	char	**command_2;
	char	**path;
	pid_t	pid;
}			t_pipex;

int			free_all(t_pipex *pipex);
void		first_child(t_pipex *pipe);
void		second_child(t_pipex *pipe);
void		army_of_fork(t_pipex *file_1);
char		*get_the_command_1(t_pipex *pipex);
char		*get_the_command_2(t_pipex *pipex);
char		*find_the_path(int ac, char **av, char **ev, t_pipex *pipex);
char		**split_the_path(t_pipex *pipe);

#endif