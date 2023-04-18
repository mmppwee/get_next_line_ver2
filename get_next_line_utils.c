/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:24:48 by pwareepo          #+#    #+#             */
/*   Updated: 2023/04/12 18:30:57 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen (const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return(ft_strdup ((char *)&s[i + 1]));
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		len;
	int		i;

	len = ft_strlen(s1);
	s = (char *) malloc (len + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int	i;
	int	j;
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	// free (new);
	return (new);
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
