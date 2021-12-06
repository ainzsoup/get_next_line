/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:07:52 by sgamraou          #+#    #+#             */
/*   Updated: 2021/12/06 22:21:20 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nl_found(char *s)
{
	int	i;

	i = 0;
	while (s[i])
 	{
		if (s[i] == '\n')
			return 1;
		i++;
	}
	return (0);
}

size_t ft_strlen(const char *s)
{
	size_t i = 0;
	while (s[i])
		i++;
	return (i);
}


char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*new;
	int		i;
	int		j;


	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	len = ft_strlen((const char *)s1) + ft_strlen((const char *)s2) + 1;
	i = 0;
	j = 0;
	new = (char *)malloc(sizeof(char) * (len));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free (s1);
	return (new);
}

//char	*ft_strdup(const char *src)
//{
//	char	*s;
//	int		i;
//	char	*copy;
//	int		len;
//
//	i = 0;
//	s = (char *)src;
//	len = ft_strlen(s);
//	copy = (char *)malloc(sizeof(char) * (len + 1));
//	if (!copy)
//		return (NULL);
//	while (s[i])
//	{
//		copy[i] = s[i];
//		i++;
//	}
//	copy[i] = '\0';
//	return (copy);
//}

// char	*ft_substr(const char *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*sub;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	if (start > ft_strlen(s))
// 		return (ft_strdup(""));
// 	if (len > ft_strlen(s) - start)
// 		sub = (char *)malloc(ft_strlen(s) - start + 1);
// 	else
// 		sub = (char *)malloc(len + 1);
// 	if (!sub)
// 		return (NULL);
// 	while (i < len && start <= (unsigned int)ft_strlen((const char *)s))
// 		sub[i++] = s[start++];
// 	sub[i] = '\0';
// 	return (sub);
// }