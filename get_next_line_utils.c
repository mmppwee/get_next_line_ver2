/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:24:48 by pwareepo          #+#    #+#             */
/*   Updated: 2023/06/03 22:06:15 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (c == 0)
	{
		while (str[i] != '\0')
			i++;
	}
	else
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n')
			i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	c;
	size_t	i;

	c = ft_strlen(src, 0);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		new_len;
	char	*new;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1, 0);
	new_len = s1_len + ft_strlen(s2, 0) + 1;
	new = malloc (sizeof(char) * new_len);
	if (new == NULL)
		return (NULL);
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	ft_strlcpy(new, s1, s1_len + 1);
	ft_strlcpy(new + s1_len, s2, new_len);
	return (new);
}

void	free_then_null(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

// #include <stdio.h>
// int main()
// // {
// // 	char *s;
// // 	s = ft_strchr("function", 'c');
// // 	printf("%s", s);
// // 	free(s);
// // }
// {
// 	char *s;
// 	s = ft_strjoin("aaaa", "ssss");
// 	printf("%s", s);
// 	free(s);
// }
