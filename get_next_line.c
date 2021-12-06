/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:29:31 by sgamraou          #+#    #+#             */
/*   Updated: 2021/12/06 23:14:01 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_left(char *buffer)
{
	int		i;
	char	*left;
	int		j;

	j = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	left = malloc(ft_strlen(buffer) - i + 1);
	if (!left)
		return (NULL);
	i++;
	while (buffer[i])
		left[j++] = buffer[i++];
	left[j] = '\0';
	free(buffer);
	return (left);
}

char	*get_line(char *hold)
{
	int		i;
	char	*str;

	i = 0;
	i = 0;
	while (hold[i] && hold[i] != '\n')
		i++;
	if (hold[i] == '\n')
		str = (char *)malloc(i + 2);
	else
		str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (hold[i] && hold[i] != '\n')
	{
		str[i] = hold[i];
		i++;
	}
	if (hold[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*read_n_repeat(char *tmp_hold, char *perm_hold, int fd)
{
	int	b_read;

	b_read = 1;
	while (!nl_found(tmp_hold) && b_read != 0)
	{
		b_read = read(fd, tmp_hold, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(tmp_hold);
			return (NULL);
		}
		tmp_hold[b_read] = '\0';
		perm_hold = ft_strjoin(perm_hold, tmp_hold);
	}
	free(tmp_hold);
	return (perm_hold);
}

char	*get_next_line(int fd)
{
	static char	*perm_hold;
	char		*tmp_hold;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp_hold = malloc((BUFFER_SIZE + 1));
	if (!tmp_hold)
		return (NULL);
	tmp_hold[0] = '\0';
	perm_hold = read_n_repeat(tmp_hold, perm_hold, fd);
	if (!perm_hold)
		return (NULL);
	if (perm_hold[0] == '\0')
	{
		free(perm_hold);
		perm_hold = NULL;
		return (NULL);
	}
	line = get_line(perm_hold);
	perm_hold = get_left(perm_hold);
	return (line);
}

// int main()
// {
// 	int fd = open("file.txt", O_RDONLY);
// 	// for (int i = 0; i < 20; i++)
// 	// 	printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
