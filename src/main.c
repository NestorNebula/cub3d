/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:13:52 by nhoussie          #+#    #+#             */
/*   Updated: 2026/04/29 11:18:14 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "core.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_scene	*scene;

	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "usage: ./cub3D scene_file\n");
		return (0);
	}
	scene = read_scene(argv[1]);
	if (scene == NULL)
		return (1);
	if (init_data(&data, scene) == NULL)
		return (1);
	handle_hooks(&data);
	return (0);
}
