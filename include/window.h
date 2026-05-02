/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 10:02:42 by nhoussie          #+#    #+#             */
/*   Updated: 2026/05/02 10:25:45 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "data.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		handle_hooks(t_data *data);
void		draw(t_data *data);
void		move(int moveflag, t_data *data);
void		rotate(int moveflag, t_data *data);

#endif // !WINDOW_H
