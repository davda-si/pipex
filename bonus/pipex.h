/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:27:38 by davda-si          #+#    #+#             */
/*   Updated: 2024/01/03 15:10:28 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libs/libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_pip
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		dup_fd[2];
	int		fd_in;
	int		old_fd;
	int		fd_out;
	int		nb_arg;
	char	*path;
	char	*cmd;
	char	**cpath;
	char	**cargs;
}			t_pip;

int		main(int argc, char **argv, char **envp);
void	ft_error(int flg, t_pip *ppx);
void	ft_path(t_pip *ppx, char **envp);
char	*get_path(char **envp);
void	fst_child(t_pip *ppx, char **av, char **envp);
void	mid_child(t_pip *ppx, char **av, char **envp);
void	snd_child(t_pip *ppx, char **av, char **envp);
void	ft_parent(t_pip ppx);
void	ft_freech(t_pip *ppx);
void	ft_freedad(t_pip *ppx, char **av);

#endif