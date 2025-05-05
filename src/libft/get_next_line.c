/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:21:09 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/04 20:40:53 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_new_line(char *str)
{
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*left_over(char *str)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	new_str = (char *)malloc(ft_strlen(str + i) + 1);
	if (!new_str)
		return (NULL);
	i++;
	while (str[i] != '\0')
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

char	*return_line(char *str)
{
	char	*dest;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 2));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}

char	*read_and_append(int fd, char *buffer)
{
	char	*buf;
	char	*temp;
	int		byte_lead;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	byte_lead = 1;
	while (!find_new_line(buffer) && byte_lead > 0)
	{
		byte_lead = read(fd, buf, BUFFER_SIZE);
		if (byte_lead < 0)
		{
			free(buf);
			free(buffer);
			return (NULL);
		}
		buf[byte_lead] = '\0';
		temp = buffer;
		buffer = ft_strjoin(buffer, buf);
		free(temp);
		if (!buffer)
			break ;
	}
	return (free(buf), buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_and_append(fd, buffer);
	if (!buffer)
		return (NULL);
	if (!buffer[0])
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = return_line(buffer);
	buffer = left_over(buffer);
	return (line);
}
