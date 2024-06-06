/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:14:27 by enschnei          #+#    #+#             */
/*   Updated: 2024/06/06 19:26:00 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_the_path_and_split(int ac, char **av, char **ev, t_pipe *pipe)
{
	int		i;
	char	*ligne_path;

	(void)ac;
	(void)av;
	i = 0;
	ligne_path = NULL;
	while (ev[i])
	{
		if (ft_strncmp(ev[i], "PATH=", 5) == 0)
		{
			ligne_path = ev[i];
			break ;
		}
		i++;
	}
	pipe->path = ft_split(ligne_path + 5, ':');
	if (!pipe->path)
		return (NULL);
	return (pipe->path);
}

// char *path_access(t_pipe *pipe)
// {
// 	int access_value;

// 	access_value = access(pipe->path, pipe->command_1);
// 	if (access_value)
// 		return(NULL);
// }