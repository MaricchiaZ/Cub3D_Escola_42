/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_equal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:30:29 by maclara-          #+#    #+#             */
/*   Updated: 2023/05/22 09:20:18 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_equal(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] && str2[i])
	{
		if (str[i] != str2[i])
			break ;
		i++;
	}
	if (!str[i] && !str2[i])
		return (1);
	return (0);
}
