/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:56:47 by enschnei          #+#    #+#             */
/*   Updated: 2024/05/29 18:03:29 by enschnei         ###   ########.fr       */
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

typedef struct s_pipe
{
	int		fd[2];
	char	*file_1;
	char	*file_2;
	char	**command_1;
	char	**command_2;
	char	**path;
	pid_t	pid;
}			t_pipe;

void		army_of_fork(t_pipe *file_1);
char		**find_the_path_and_split(int ac, char **av, char **ev,
				t_pipe *pipe);
// void		error_exec(void);

#endif