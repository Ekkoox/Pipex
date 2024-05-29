/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:14:27 by enschnei          #+#    #+#             */
/*   Updated: 2024/05/29 17:27:40 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_the_path_and_split(int ac, char **av, char **ev, t_pipe *pipe)
{
	(void) ac;
	(void) av;
	int i;
	int ligne_path;

	i = 0;
	ligne_path = 0;
	while(ev[i])
	{
		if(ft_strncmp(ev[i], "PATH=", 5) == 0);
		{
			ligne_path = ev[i];
			break ;
		}
		ev[i]++;
	}
	pipe->path = ft_split(ligne_path, ':');
	if (!pipe->path)
		return (NULL);
	return(pipe->path);
}


