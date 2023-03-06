/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:07:04 by agil-ord          #+#    #+#             */
/*   Updated: 2022/10/19 11:54:11 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_save(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i])
		line[i++] = '\n';
	return (line);
}

char	*ft_read_file(int fd, char *buf)
{
	char	*buffer;
	int		flag_read;

	if (!buf)
		buf = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	flag_read = 1;
	while (flag_read > 0)
	{
		if (ft_strchr(buffer, '\n'))
			break ;
		flag_read = read(fd, buffer, BUFFER_SIZE);
		if (flag_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[flag_read] = 0;
		buf = ft_free(buf, buffer);
	}
	free(buffer);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_save(buffer);
	return (line);
}
/*
char	*get_next_line(int fd)
{
	static char	**buffer;
	char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	temp = ft_strjoin(temp, *buffer);

	return (temp);
}

static void	ft_read_file(int fd, char **buffer)
{
	int		flag_read;
	char	*temp;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	flag_read = 1;
	while (flag_read > 0 && !ft_strchr(*buffer, '\n'))
	{
		flag_read = read(fd, *temp, BUFFER_SIZE);
		if (flag_read == -1)
		{
			ft_free(buffer);
			return (NULL);
		}
		ft_strjoin(*buffer, temp);
		//gestionar liberacion de memoria de temp
		//funcion que me vaya juntando los trozos(join) aqui la funcion guardar
	}
}*/
