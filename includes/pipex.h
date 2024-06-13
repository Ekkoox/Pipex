/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:56:47 by enschnei          #+#    #+#             */
/*   Updated: 2024/06/13 15:29:27 by enschnei         ###   ########.fr       */
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
	char	*file_1;
	char	*file_2;
	char	**av;
	char	**ev;
	char	**command_1;
	char	**command_2;
	char	**path;
	pid_t	pid;
}			t_pipex;

void 		first_child(t_pipex *pipe);
void 		second_child(t_pipex *pipe);
void		army_of_fork(t_pipex *file_1);
char		*get_the_command(t_pipex *pipex);
char		**find_the_path_and_split(int ac, char **av, char **ev,
				t_pipex *pipe);
// void		error_exec(void);

#endif