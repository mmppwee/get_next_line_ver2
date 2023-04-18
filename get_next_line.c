/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:58:17 by pwareepo          #+#    #+#             */
/*   Updated: 2023/04/18 21:10:45 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_readline(char *keep)
{
	char	*buf;
	int	i;
	int	n;
	buf = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (1)
	{
		i = read (fd, buf, BUFFER_SIZE);
		if (i < 0)
			return(free(buf), NULL);
		if (keep != NULL)
			keep = ft_strdup(buf);
		keep = ft_strjoin(keep, buf);
		n = ft_check(buf);
		if (n == 0)
			break;
	}
	return(free(buf), keep);
	// printf("%s", ft_readline("abcd\nppp"));
}

char	*ft_cutline

char	*get_next_line(int fd)
{
	static char	*keep;
	char	*line;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	keep = ft_readline(keep);
	line = ft_cutline();
	keep = ft_keepline();
	return(line);
}

#include <stdio.h>
int main()
{
	int fd;
	fd = open("41_with_nl", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}