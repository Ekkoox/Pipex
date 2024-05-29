/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:30:41 by enschnei          #+#    #+#             */
/*   Updated: 2024/05/23 17:31:21 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void error_exec()
{
	int fd[2];

	if (pipe(fd) == -1)
	{
		ft_printf("Error while opening the pipe\n");
		exit(EXIT_FAILURE);	
	}
}
