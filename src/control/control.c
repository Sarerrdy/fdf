/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:47:45 by eina              #+#    #+#             */
/*   Updated: 2026/03/09 22:14:20 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	handle_move(int key, t_fdf *fdf)
{
	if (key == KEY_UP)
		fdf->offset_y -= 10;
	if (key == KEY_DOWN)
		fdf->offset_y += 10;
	if (key == KEY_LEFT)
		fdf->offset_x -= 10;
	if (key == KEY_RIGHT)
		fdf->offset_x += 10;
}

void	handle_zoom(int key, t_fdf *fdf)
{
	if (key == KEY_PLUS)
		fdf->zoom += 1.0f;
	if (key == KEY_MINUS)
		fdf->zoom -= 1.0f;
	if (fdf->zoom < 0.1f)
		fdf->zoom = 0.1f;
}

void	handle_zscale(int key, t_fdf *fdf)
{
	if (key == 't')
		fdf->z_scale += 0.05f;
	if (key == 'g')
		fdf->z_scale -= 0.05f;
	if (fdf->z_scale < 0.0f)
		fdf->z_scale = 0.0f;
}

void	handle_rotation(int key, t_fdf *fdf)
{
	if (key == 'w')
		fdf->rot_x += 0.05;
	if (key == 's')
		fdf->rot_x -= 0.05;
	if (key == 'a')
		fdf->rot_z -= 0.05;
	if (key == 'd')
		fdf->rot_z += 0.05;
	if (key == 'q')
		fdf->rot_y -= 0.05;
	if (key == 'e')
		fdf->rot_y += 0.05;
}

void	handle_reset(int key, t_fdf *fdf)
{
	if (key == 'r')
		init_defaults(fdf);
}
