/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneme <aneme@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:36:03 by aneme             #+#    #+#             */
/*   Updated: 2024/12/01 15:01:25 by aneme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_free(char **s);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *dst, char *src);
char	*ft_substr(char *s, int start, int size);
char	*ft_strchr(char *s, int c);

#endif
