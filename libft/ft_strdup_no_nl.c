/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_no_nl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:03:15 by maclara-          #+#    #+#             */
/*   Updated: 2023/05/19 09:07:11 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_no_nl(const char *src)
{
	char	*dest;
	int		count_size;
	int		i;

	count_size = ft_strlen(src);
	count_size--;
	dest = (char *) malloc(sizeof(char) * (count_size + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < count_size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
