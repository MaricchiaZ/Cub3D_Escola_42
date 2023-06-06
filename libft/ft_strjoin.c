/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:47:51 by gissao-m          #+#    #+#             */
/*   Updated: 2023/05/21 19:38:15 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		count_s1;
	int		count_s2;
	char	*join;
	size_t	lenght;

	count_s1 = -1;
	count_s2 = -1;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	lenght = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *)malloc(lenght);
	if (join == 0)
		return (NULL);
	while (s1[++count_s1] != '\0')
		join[count_s1] = s1[count_s1];
	while (s2[++count_s2] != '\0')
		join[count_s1 + count_s2] = s2[count_s2];
	join[count_s1 + count_s2] = '\0';
	free(s1);
	return (join);
}
