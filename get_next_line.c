/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:58:17 by pwareepo          #+#    #+#             */
/*   Updated: 2023/04/19 22:26:56 by pwareepo         ###   ########.fr       */
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
	// int		oldsize;
	// int	i;
	char	*line;
	char	*tmp;

	// i = 0;
	// oldsize = ft_strlen(*keep, 0);
	len = ft_strlen(*keep, 1);
	// while (s[i] != '\n' && s[i] != '\0')
	// 	i++;
	// len = i;
	line = malloc (sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	len_keep = ft_strlen(*keep, 0) - len;
	tmp = malloc (sizeof(char) * (len + 1));
	if (tmp == NULL)
	{
		// free(line);
		return (NULL);
	}
	line[0] = '\0';
	ft_strlcpy(line, *keep, len + 1);
	ft_strlcpy(*keep, *keep + len, len_keep + 1);
	// *keep = ft_realloc(*keep, oldsize, len_keep);
	// free(keep);
	*keep = tmp;
	// i = 0;
	// while (i <= len)
	// {
	// 	line[i] = s[i];
	// 	i++;
	// }
	// line[i] = '\0';
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
	i = 1;
	while (i > 0)
	{
		i = read (fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		tmp = ft_strjoin(*keep, buf);
		// free(&keep);
		*keep = tmp;
		if (ft_check(buf) == 0)
			break;
	}
	// free(buf);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char	*line;
	// char	*buf;
	// int	n;
	// int	i;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	// buf = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	// if (buf == NULL)
	// 	return (NULL);
	if (keep == NULL)
	{
		keep = malloc(1);
		if (keep == NULL)
			return (NULL);
	}
	read_fd(fd, &keep);
	// while (1)
	// {
	// 	i = read (fd, buf, BUFFER_SIZE);
	// 	if (i < 0)
	// 		return(free(buf), NULL);
	// 	if (i == 0)
	// 	{
	// 		if (ft_check(buf) == 1)
	// 		{
	// 			line = ft_returnline(buf);
	// 			return(free(buf), line);
	// 		}
	// 		free(buf);
	// 		free(keep);
	// 		return(NULL);
	// 	}
	// 	buf[i] = '\0';
	// 	keep = ft_strjoin(keep, buf);
	// 	// printf("keep: %s", keep);
	// 	n = ft_check(keep);
	// 	if (n == 0)
	// 		break;
	// }
	line = ft_returnline(&keep);
	// keep = ft_strchr(keep, '\n');
	// free(buf);
	// free(keep);
	// if (ft_check(line) == 1)
		// free(keep);
	return(line);
}

// int main()
// {
// 	int fd;
// 	char *line;

// 	line = "";
// 	fd = open("41_with_nl", O_RDONLY);
// 	while(line != NULL)
// 	{

// 	printf("%s", get_next_line(fd));
// 	//printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// free(line);
// 	}
// 	close(fd);
// 	return(0);
// }