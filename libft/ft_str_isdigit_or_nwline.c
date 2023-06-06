/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit_or_nwline.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:55:27 by maclara-          #+#    #+#             */
/*   Updated: 2023/05/14 10:35:21 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_isdigit_or_nwline(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '\n')
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}
