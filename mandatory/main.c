/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:40:09 by davda-si          #+#    #+#             */
/*   Updated: 2024/01/02 18:52:15 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_pipe(t_pip ppx, char **av, char **envp)
{
	if (pipe(ppx.fd) == 0)
	{
		ppx.pid1 = fork();
		if (ppx.pid1 < 0)
			ft_error(0);
		else if (ppx.pid1 == 0)
			fst_child(&ppx, av, envp);
		close(ppx.fd[1]);
		wait(NULL);
		ppx.pid2 = fork();
		if (ppx.pid2 < 0)
			ft_error(0);
		else if (ppx.pid2 == 0)
			snd_child(&ppx, av, envp);
		close(ppx.fd[0]);
		waitpid(ppx.pid1, NULL, 0);
		waitpid(ppx.pid2, NULL, 0);
	}
	else
	{
		ft_putendl_fd("Error with the pipe process", 2);
		ft_freedad(&ppx);
		exit (1);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pip	ppx;

	if (ac == 5)
	{
		ft_path(&ppx, envp);
		ft_pipe(ppx, av, envp);
		ft_freedad(&ppx);
	}
	else
		ft_putendl_fd("Error with the ammount of arguments", 2);
	return (0);
}

/* init_pipe()
	check_args()
	pars_cmd()
	pars_args()c
	find path()
	pipe(2 child process)
	close fd()
	parent process(closes everything and frees what is needed)
	 */