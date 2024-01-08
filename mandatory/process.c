/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:42:24 by davda-si          #+#    #+#             */
/*   Updated: 2024/01/02 18:50:38 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*try_cmd(char *cargs, char **cpath)
{
	char	*temp;
	char	*cmd;
	int		i;

	i = 0;
	cmd = NULL;
	while (cpath[i])
	{
		temp = ft_strjoin(cpath[i], "/");
		cmd = ft_strjoin(temp, cargs);
		free(temp);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	return (NULL);
}

void	fst_child(t_pip *ppx, char **av, char **envp)
{
	ppx->fd_in = open(av[1], O_RDONLY);
	ppx->dup_fd[0] = dup2(ppx->fd[1], STDOUT_FILENO);
	ppx->dup_fd[1] = dup2(ppx->fd_in, STDIN_FILENO);
	close(ppx->fd[0]);
	close(ppx->fd[1]);
	close(ppx->fd_in);
	if (ppx->dup_fd[0] < 0 || ppx->dup_fd[1] < 0)
		ft_error(1);
	ppx->cargs = ft_split(av[2], ' ');
	ppx->cmd = try_cmd(ppx->cargs[0], ppx->cpath);
	if (!ppx->cmd)
	{
		ft_freech(ppx);
		ft_putendl_fd("Error with the command", 2);
		exit (1);
	}
	execve(ppx->cmd, ppx->cargs, envp);
	ft_putendl_fd("Error executing command", 2);
	ft_freech(ppx);
	exit (1);
}

void	snd_child(t_pip *ppx, char **av, char **envp)
{
	ppx->fd_out = open(av[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	ppx->dup_fd[1] = dup2(ppx->fd[0], STDIN_FILENO);
	ppx->dup_fd[0] = dup2(ppx->fd_out, STDOUT_FILENO);
	close(ppx->fd[0]);
	close(ppx->fd[1]);
	close(ppx->fd_out);
	if (ppx->dup_fd[0] < 0 || ppx->dup_fd[1] < 0)
		ft_error(1);
	ppx->cargs = ft_split(av[3], ' ');
	ppx->cmd = try_cmd(ppx->cargs[0], ppx->cpath);
	if (!ppx->cmd)
	{
		ft_freech(ppx);
		ft_putendl_fd("Error with the command", 2);
		exit (1);
	}
	execve(ppx->cmd, ppx->cargs, envp);
	ft_putendl_fd("Error executing command", 2);
	ft_freech(ppx);
	exit (1);
}

/* void	ft_parent(t_pip ppx)
{
	waitpid(ppx.pid1, NULL, 0);
	waitpid(ppx.pid2, NULL, 0);
	ft_freedad(&ppx);
} */
