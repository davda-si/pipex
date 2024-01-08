/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:42:52 by davda-si          #+#    #+#             */
/*   Updated: 2023/11/15 17:27:14 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line_bonus(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
	{
		while (buff[fd][i])
			buff[fd][i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (buff[fd][0] || read(fd, buff[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin_gnl2(line, buff[fd]);
		if (time_to_free(buff[fd]))
			break ;
	}
	return (line);
}

/* int main()
{
	int 	fd;
	int		fd_1;
	char	*line[FOPEN_MAX];
	
	fd = open("teste.txt", O_RDONLY);
	fd_1 = open("multiple_nl.txt", O_RDONLY);
	line[fd] = get_next_line(fd);
	line[fd_1] = get_next_line(fd_1);
	while (line[fd] != 0)
	{
		printf("%s", line[fd]);
		free(line[fd]);
		line[fd] = get_next_line(fd);
	}
	printf("-----------------------------------\n");
	while (line[fd_1] != 0)
	{
		printf("%s", line[fd_1]);
		free(line[fd_1]);
		line[fd_1] = get_next_line(fd_1);
	}
	close(fd);
	close(fd_1);
	free(line[fd]);
	free(line[fd_1]);
	return (0);
} */