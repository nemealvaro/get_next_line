/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneme <aneme@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:35:58 by aneme             #+#    #+#             */
/*   Updated: 2024/12/01 15:20:27 by aneme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

char	*ft_get_line(char *s)
{
	int		i;
	char	*newline;

	i = 0;
	if (!s || !*s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	newline = ft_substr(s, 0, i);
	return (newline);
}

char	*ft_cleanstr(char *s)

{
	int i;
	char *newstr;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (ft_free(&s));
	newstr = ft_substr(s, i, ft_strlen(s) - i);
	free(s);
	return (newstr);
}

char	*ft_readbuffer(int fd, char *s)
{
	char	*buffer;
	int		bytes;

	bytes = 1;
	while (!ft_strchr(s, '\n') && bytes > 0)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (ft_free(&s));
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 1)
		{
			free(buffer);
			if (bytes < 0)
				return (ft_free(&s));
			return (s);
		}
		buffer[bytes] = '\0';
		s = ft_strjoin(s, buffer);
		free(buffer);
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_readbuffer(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	if (!line)
		return (ft_free(&str));
	str = ft_cleanstr(str);
	return (line);
}

int main(int argc, char **argv)
{
    int     fd;
    char    *line;
	size_t	count;

    if (argc != 2)
    {
        printf("Uso: %s <nombre_archivo>\n", argv[0]);
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error al abrir el archivo");
        return (1);
    }
	count = 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%li%s\n", count, line);
        free(line);
		count++;
    }
    if (close(fd) < 0)
    {
        perror("Error al cerrar el archivo");
        return (1);
    }
    return (0);
}
