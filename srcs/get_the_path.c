/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:14:27 by enschnei          #+#    #+#             */
/*   Updated: 2024/06/21 16:54:28 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_the_path(int ac, char **av, char **ev, t_pipex *pipex)
{
	int	i;

	(void)ac;
	(void)av;
	i = 0;
	pipex->ligne_path = NULL;
	while (ev[i])
	{
		if (ft_strncmp(ev[i], "PATH=", 5) == 0)
		{
			pipex->ligne_path = ev[i];
			break ;
		}
		i++;
	}
	return (pipex->ligne_path);
}

char	**split_the_path(t_pipex *pipex)
{
	if (!pipex->ligne_path)
		return (NULL);
	pipex->path = ft_split(pipex->ligne_path + 5, ':');
	if (!pipex->path)
	{
		ft_free(pipex->command_1, ft_count_line_split(pipex->command_1));
		ft_free(pipex->command_2, ft_count_line_split(pipex->command_2));
		exit(EXIT_FAILURE);
	}
	return (pipex->path);
}

char	*search_the_path(t_pipex *pipex, char *command)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	tmp = ft_strjoin("/", command);
	if (!tmp)
		return (NULL);
	while (pipex->path[i])
	{
		path = ft_strjoin(pipex->path[i], tmp);
		if (!path)
			return (free(tmp), NULL);
		if (access(path, F_OK | X_OK) == 0)
			return (free(tmp), path);
		free(path);
		i++;
	}
	free(tmp);
	return (NULL);
}

char	*get_the_command_1(t_pipex *pipex)
{
	int		i;
	char	*path;

	i = 0;
	if (!pipex->command_1[0] || !pipex->command_2[0])
	{
		free_all (pipex);
		return (NULL);
	}
	if (!ft_strchr(pipex->command_1[0], '/') && pipex->command_1[0][0] != '.')
	{
		path = search_the_path(pipex, pipex->command_1[0]);
		return (path);
	}
	if (access(pipex->command_1[0], F_OK | X_OK) == 0)
		return (pipex->command_1[0]);
	return (NULL);
}

char	*get_the_command_2(t_pipex *pipex)
{
	int		i;
	char	*path;

	i = 0;
	if (!pipex->command_1[0] || !pipex->command_2[0])
	{
		ft_putstr_fd("Command not found\n", 2);
		free_all(pipex);
		return (NULL);
	}
	if (!ft_strchr(pipex->command_2[0], '/') && pipex->command_2[0][0] != '.')
	{
		path = search_the_path(pipex, pipex->command_2[0]);
		return (path);
	}
	if (access(pipex->command_2[0], F_OK | X_OK) == 0)
		return (pipex->command_2[0]);
	return (NULL);
}
