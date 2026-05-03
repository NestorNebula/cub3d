/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 23:31:09 by cmonmire          #+#    #+#             */
/*   Updated: 2026/05/02 10:18:09 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define M_UP 0x01
# define M_DOWN 0x02
# define M_LEFT 0x04
# define M_RIGHT 0x08
# define MOVE 0x0f
# define R_LEFT 0x10
# define R_RIGHT 0x20
# define ROTATE 0x30

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		moveflag;
}	t_player;

#endif
