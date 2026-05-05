/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 07:10:54 by nhoussie          #+#    #+#             */
/*   Updated: 2026/05/05 07:13:41 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>

int			str_count(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (i);
	while (*str != '\0')
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}
