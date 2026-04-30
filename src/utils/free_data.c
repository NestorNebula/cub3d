/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:03:54 by nhoussie          #+#    #+#             */
/*   Updated: 2026/04/30 13:09:21 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		free_data(t_data *data)
{
	if (data == NULL)
		return ;
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_image(data->mlx, data->north.img);
	mlx_destroy_image(data->mlx, data->south.img);
	mlx_destroy_image(data->mlx, data->west.img);
	mlx_destroy_image(data->mlx, data->east.img);
	mlx_destroy_window(data->mlx, data->win);
	free_scene(data->scene);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
