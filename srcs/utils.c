/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:27:49 by enschnei          #+#    #+#             */
/*   Updated: 2024/07/03 14:52:56 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_pipex *pipex)
{
	int		fd;
	char	*path;

	fd = open(pipex->file_1, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Permission denied\n", 2);
		return ;
	}
	if (dup2(fd, 0) == -1)
		return ;
	if (dup2(pipex->fd[1], 1) == -1)
		return ;
	close(fd);
	close(pipex->fd[1]);
	close(pipex->fd[0]);
	path = get_the_command_1(pipex);
	if (!path)
	{
		ft_putstr_fd("No such file or directory2\n", 2);
		free_all(pipex);
		exit(EXIT_FAILURE);
	}
	if (execve(path, pipex->command_1, pipex->ev) == -1)
	{
		ft_putstr_fd("Epic fail compilation 2013 [HD]\n", 2);
		free_all(pipex);
	}
	exit(0);
}

void	second_child(t_pipex *pipex)
{
	int		fd;
	char	*path;

	fd = open(pipex->file_2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("Permission denied\n", 2);
		return ;
	}
	if (dup2(fd, 1) == -1)
		return ;
	if (dup2(pipex->fd[0], 0) == -1)
		return ;
	close(fd);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	path = get_the_command_2(pipex);
	if (!path)
	{
		ft_putstr_fd("No such file or directory3\n", 2);
		free_all(pipex);
		exit(EXIT_FAILURE);
	}
	if (execve(path, pipex->command_1, pipex->ev) == -1)
	{
		ft_putstr_fd("Epic fail compilation 2013 [HD]\n", 2);
		free_all(pipex);
	}
	exit(0);
}

int	free_all(t_pipex *pipex)
{
	if (pipex->path)
		ft_free(pipex->path, ft_count_line_split(pipex->path));
	ft_free(pipex->command_1, ft_count_line_split(pipex->command_1));
	ft_free(pipex->command_2, ft_count_line_split(pipex->command_2));
	exit(EXIT_SUCCESS);
}
