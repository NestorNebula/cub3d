/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 10:00:56 by nhoussie          #+#    #+#             */
/*   Updated: 2026/05/02 10:25:25 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "raycasting.h"

int			shade_wall(int color, t_ray *ray);
int			shade_floor(int color, int y, t_data *data);
int			shade_ceiling(int color, int y, t_data *data);
double		get_time(void);

#endif // !UTILS_H
