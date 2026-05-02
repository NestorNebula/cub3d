/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 08:17:34 by nhoussie          #+#    #+#             */
/*   Updated: 2026/05/02 09:39:50 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static int	shade(int color, double factor);

int			shade_wall(int color, t_ray *ray)
{
	double	factor;
	
	factor = 1 / (1 + ray->perp_wall_dist * 0.1);
	if (ray->side == 1)
		factor *= 0.7;
	return (shade(color, factor));
}

int			shade_floor(int color, int y, t_data *data)
{
	double	factor;

	factor = 1 / (1 + (1.0 - (double) y / data->screen_height) * 0.8);
	return (shade(color, factor));
}

int			shade_ceiling(int color, int y, t_data *data)
{
	double	factor;

	factor = 1 / (1 + ((double) y / data->screen_height) * 0.8);
	return (shade(color, factor));
}

static int	shade(int color, double factor)
{
	int		r;
	int		g;
	int		b;

	if (factor < 0.4)
		factor = 0.4;
	r = (color >> 16 & 0xff) * factor;
	g = (color >> 8 & 0xff) * factor;
	b = (color & 0xff) * factor;

	return ((r << 16) + (g << 8) + b);
}
