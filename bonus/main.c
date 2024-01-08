/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:40:09 by davda-si          #+#    #+#             */
/*   Updated: 2024/01/03 16:00:32 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_heredoc(char **av)
{
	int		fd[2];
	char	*res;

	pipe(fd);
	while (1)
	{
		res = get_next_line(0);
		if (!res)
			return (-1);
		if (ft_strncmp(av[2], res, ft_strlen(av[2])) == 0 && 
			(ft_strlen(av[2]) == ft_strlen(res) - 1))
			break ;
		ft_putstr_fd(res, fd[1]);
		free(res);
	}
	free(res);
	close(fd[1]);
	return (fd[0]);
}

static void	which_child(t_pip *ppx, int ac, char **av, char **envp)
{
	ppx->pid1 = fork();
	if (ppx->pid1 < 0)
		ft_error(0, ppx);
	if (ppx->pid1 == 0)
	{
		close(ppx->fd[0]);
		if (ppx->nb_arg == !(ft_strncmp("here_doc", av[1], -1)) + 2)
			fst_child(ppx, av, envp);
		else if (ppx->nb_arg == ac - 2)
			snd_child(ppx, av, envp);
		else
			mid_child(ppx, av, envp);
	}
	else
	{
		if (ppx->nb_arg == !(ft_strncmp("here_doc", av[1], -1)) + 2)
			close(ppx->fd_in);
		else if (ppx->nb_arg == ac - 2)
			close(ppx->fd_out);
		close(ppx->fd[1]);
		ppx->dup_fd[1] = dup2(ppx->fd[0], STDIN_FILENO);
		close(ppx->fd[0]);
	}
}

static void	ft_pipe(t_pip ppx, int ac, char **av, char **envp)
{
	if (pipe(ppx.fd) == 0)
		which_child(&ppx, ac, av, envp);
	else
	{
		ft_putendl_fd("Error with the pipe process", 2);
		ft_freedad(&ppx, av);
		exit (1);
	}
}

static void	ft_normal_open(t_pip *ppx, int ac, char **av)
{
	ppx->fd_in = open(av[1], O_RDONLY);
	ppx->fd_out = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (ppx->fd_in < 0 || ppx->fd_out < 0)
		ft_error(1, NULL);
}

int	main(int ac, char **av, char **envp)
{
	t_pip	ppx;

	ppx.nb_arg = !(ft_strncmp("here_doc", av[1], -1));
	if (ac < 5)
	{
		ft_putendl_fd("Error with the ammount of arguments", 2);
		exit(1);
	}
	else if ((ft_strncmp("here_doc", av[1], -1) != 0))
		ft_normal_open(&ppx, ac, av);
	else
	{
		ppx.fd_in = ft_heredoc(av);
		if (ppx.fd_in == -1)
			exit (1);
		ppx.fd_out = open(av[ac - 1], O_CREAT | O_APPEND | O_WRONLY, 0644);
	}
	ft_path(&ppx, envp);
	ppx.nb_arg += 1;
	while (++ppx.nb_arg < ac - 1)
		ft_pipe(ppx, ac, av, envp);
	ft_freedad(&ppx, av);
	return (0);
}
