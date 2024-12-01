/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneme <aneme@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:35:47 by aneme             #+#    #+#             */
/*   Updated: 2024/12/01 15:01:26 by aneme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *dst, char *src)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!dst)
	{
		dst = malloc(1);
		if (!dst)
			return (NULL);
		dst[0] = '\0';
	}
	if (!src)
		return (NULL);
	i = -1;
	j = -1;
	result = malloc((ft_strlen(dst) + ft_strlen(src) + 1) * sizeof(char));
	if (!result)
		return (ft_free(&dst));
	while (dst[++i])
		result[i] = dst[i];
	while (src[++j])
		result[i++] = src[j];
	result[i] = '\0';
	free(dst);
	return (result);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char *s, int start, int size)
{
	int		i;
	int		slen;
	char	*newstr;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if ((slen - start) < size)
		size = slen - start;
	if (start >= (int)ft_strlen(s))
		return ("");
	i = 0;
	newstr = malloc((size + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s[start + i] && i < size)
	{
		newstr[i] = s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
