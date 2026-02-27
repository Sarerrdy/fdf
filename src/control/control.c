/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:47:45 by eina              #+#    #+#             */
/*   Updated: 2026/02/27 16:23:51 by eina             ###   ########.fr       */
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
		fdf->zoom += 1;
	if (key == KEY_MINUS)
		fdf->zoom -= 1;
}

void	handle_zscale(int key, t_fdf *fdf)
{
	if (key == 't')
		fdf->z_scale += 0.1;
	if (key == 'g')
		fdf->z_scale -= 0.1;
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
