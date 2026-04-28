/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_with_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 09:01:46 by cmonmire          #+#    #+#             */
/*   Updated: 2026/04/14 11:08:57 by cmonmire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_texture	*get_texture(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (&data->west);
		else
			return (&data->east);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (&data->north);
		else
			return (&data->south);
	}
}

int	get_texture_color(t_texture *tex, int x, int y)
{
	char	*pixel;

	pixel = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)pixel);
}
