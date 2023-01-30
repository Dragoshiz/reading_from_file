/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:31:36 by dimbrea           #+#    #+#             */
/*   Updated: 2022/03/09 12:08:33 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_strchr(char *buffer, char c)
{
	if (!buffer)
		return (NULL);
	while (*buffer)
	{
		if (*buffer == c)
			return (buffer);
		buffer++;
	}
	if (c == '\0' && *buffer == '\0')
		return (buffer);
	return (NULL);
}

char	*ft_strjoin(char *save, char *buffer)
{
	char	*p;
	int		i;
	int		j;

	if (!save)
		save = ft_calloc(1, sizeof(char));
	if (!save || !buffer)
		return (NULL);
	p = ft_calloc((ft_strlen(save) + ft_strlen(buffer)) + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (save[i])
	{
		p[i] = save[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		p[i++] = buffer[j++];
	free(save);
	return (p);
}

void	*ft_memset(void *str, int c, size_t n)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)str;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (p);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, nmemb * size);
	return (p);
}
