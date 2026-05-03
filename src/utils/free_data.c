/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:03:54 by nhoussie          #+#    #+#             */
/*   Updated: 2026/05/02 10:19:31 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	free_data(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->img.img != NULL)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->north.img != NULL)
		mlx_destroy_image(data->mlx, data->north.img);
	if (data->south.img != NULL)
		mlx_destroy_image(data->mlx, data->south.img);
	if (data->west.img != NULL)
		mlx_destroy_image(data->mlx, data->west.img);
	if (data->east.img != NULL)
		mlx_destroy_image(data->mlx, data->east.img);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->scene != NULL)
		free_scene(data->scene);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
