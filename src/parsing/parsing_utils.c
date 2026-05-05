/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 07:10:54 by nhoussie          #+#    #+#             */
/*   Updated: 2026/05/05 07:31:56 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include "libft.h"

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

int			check_extension(char *filename, char *extension)
{
	char	*ext;
	size_t	extension_len;

	if (filename == NULL || extension == NULL)
		return (0);
	extension_len = ft_strlen(extension);
	ext = ft_strrchr(filename, '.');
	if (ft_strlen(filename) < extension_len + 1 || ext == NULL
		|| ft_strncmp(ext, extension, extension_len + 1) != 0 || *(ext - 1) == '/')
		return (0);
	return (1);
}
