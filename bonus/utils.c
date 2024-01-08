/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:52:50 by davda-si          #+#    #+#             */
/*   Updated: 2024/01/03 16:00:46 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			res = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (res == NULL)
	{
		ft_putendl_fd("Path not found", 2);
		return (NULL);
	}
	return (res);
}

void	ft_path(t_pip *ppx, char **envp)
{
	ppx->path = get_path(envp);
	if (!ppx->path)
		exit(1);
	ppx->cpath = ft_split(ppx->path, ':');
}

void	ft_freech(t_pip *ppx)
{
	int	i;

	i = -1;
	while (ppx->cargs[++i])
		free(ppx->cargs[i]);
	i = -1;
	while (ppx->cpath[++i])
		free(ppx->cpath[i]);
	close(ppx->fd[0]);
	close(ppx->fd[1]);
	free(ppx->cpath);
	free(ppx->cargs);
	free(ppx->cmd);
}

void	ft_freedad(t_pip *ppx, char **av)
{
	int	i;

	i = (!(ft_strncmp("here_doc", av[1], -1))) + 2;
	while (i < ppx->nb_arg)
	{
		wait(NULL);
		i++;
	}
	i = -1;
	while (ppx->cpath[++i])
		free(ppx->cpath[i]);
	free(ppx->cpath);
}

void	ft_error(int flg, t_pip *ppx)
{
	int	i;

	if (flg == 1)
		ft_putendl_fd("Error with the input/output files", 2);
	if (flg == 0)
		ft_putendl_fd("Error with forking", 2);
	i = -1;
	if (!ppx)
		exit (1);
	while (ppx->cpath[++i])
		free(ppx->cpath[i]);
	free(ppx->cpath);
	exit(1);
}
