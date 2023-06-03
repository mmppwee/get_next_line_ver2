/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:58:17 by pwareepo          #+#    #+#             */
/*   Updated: 2023/06/03 21:44:51 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_check(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_returnline(char **keep)
{
	int		len;
	int		len_keep;
	char	*line;

	if (*keep == NULL)
		return (NULL);
	if (**keep == 0)
		return (NULL);
	len = ft_strlen(*keep, 1);
	line = malloc (sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	len_keep = ft_strlen(*keep, 0) - len;
	line[0] = '\0';
	ft_strlcpy(line, *keep, len + 1);
	ft_strlcpy(*keep, *keep + len, len_keep + 1);
	return (line);
}

void	read_fd(int fd, char **keep)
{
	char	*buf;
	char	*tmp;
	int		i;

	buf = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return ;
	buf[0] = '\0';
	i = 1;
	while (i > 0)
	{
		i = read (fd, buf, BUFFER_SIZE);
		if (i < 0)
		{
			free_then_null(keep);
			break ;
		}
		buf[i] = '\0';
		tmp = ft_strjoin(*keep, buf);
		free(*keep);
		*keep = tmp;
		if (ft_check(buf) == 0)
			return (free_then_null(&buf));
	}
	free_then_null(&buf);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	read_fd(fd, &keep);
	line = NULL;
	if (keep)
		line = ft_returnline(&keep);
	if (line == NULL && keep)
	{
		free(keep);
		keep = NULL;
	}
	return (line);
}

// int main(int ac, char **av)
// {
// 	int 	fd;
// 	char 	*line;

// 	fd = open(av[1], O_RDONLY);
// 	line = get_next_line(fd);
// 	// printf("Hello From Main\n");
// 	while(line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 		// printf("%s", get_next_line(fd));
// 		// printf("%s", get_next_line(fd));
// 		// printf("%s", get_next_line(fd));
// 		// free(line);
// 	}
// 	if (line != NULL)
// 		free(line);
// 	close(fd);
// 	return(0);
// }