/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:14:27 by enschnei          #+#    #+#             */
/*   Updated: 2024/06/13 15:28:00 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_the_path_and_split(int ac, char **av, char **ev, t_pipex *pipex)
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
	pipex->path = ft_split(ligne_path + 5, ':');
	if (!pipex->path)
		return (NULL);
	return (pipex->path);
}

char *get_the_command(t_pipex *pipex)
{
	int		i;
	char	*path;
	char	*tmp;

	i = 0;
	while (pipex->path[i])
	{
		if (pipex->path[ft_strlen(pipex->path[i]) - 1] != '/')
        {
            tmp = ft_strjoin(pipex->path[i], "/");
            if (!tmp)
                return (NULL);
            path = ft_strjoin(tmp, pipex->command_1[0]);
            free(tmp);
        } 
		path = ft_strjoin(pipex->path[i], pipex->command_1[0]);
		if (!path)
			return(NULL);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}
