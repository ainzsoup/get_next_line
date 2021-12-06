/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:29:31 by sgamraou          #+#    #+#             */
/*   Updated: 2021/12/06 22:19:21 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_left(char *buffer)
{
	int i;
	char *left;
	int j;

	j = 0;
	i = 0;
	
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return(NULL);
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
	int	i;
	char *str;

	i = 0;
	i = 0;
	while ( hold[i] && hold[i] != '\n')
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

char	*get_next_line(int fd)
{
	static char	*perm_hold;
	char		*tmp_hold;
	char		*line;
	int			byte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	byte = 1;
	tmp_hold = malloc((BUFFER_SIZE + 1));
	if (!tmp_hold) 
		return (NULL);
	tmp_hold[0] = '\0';
	while (!nl_found(tmp_hold) && byte != 0)
	{
		byte =  read(fd, tmp_hold, BUFFER_SIZE);
		if (byte == -1)
		{
			free(tmp_hold);
			return (NULL);
		}
		tmp_hold[byte] = '\0';
		perm_hold = ft_strjoin(perm_hold, tmp_hold);
	}
	free(tmp_hold);
	if (!perm_hold)
		return (NULL);
	if (perm_hold[0] == '\0')
	{
		free(perm_hold);
		perm_hold = NULL;// preventing double free
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

// 	return 0;
// }

// char	*get_next_line(int fd)
// {		
// 	char	*hold = calloc(BUFFER_SIZE + 1);
// 	char	*hv2 = calloc(BUFFER_SIZE + 1);
// 	int i;
// 	int i;

// 	hold[BUFFER_SIZE] = '\0';
// 	read(fd, hold, BUFFER_SIZE);
// 	if (nl_true(hold))
// 		return (get_line(hold));
// 	else
// 	{
// 		while (1)
// 		{
// 			char *hv2 = calloc(BUFFER_SIZE + 1);
// 			read(fd, hv2, BUFFER_SIZE);
			
// 		}
// 	}
// 	return ("NULL");
// }
