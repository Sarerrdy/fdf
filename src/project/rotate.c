/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:10:31 by eina              #+#    #+#             */
/*   Updated: 2026/03/05 05:25:14 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_point *p, float angle)
{
	float	y;
	float	z;

	y = p->y;
	z = p->z;
	p->y = y * cos(angle) - z * sin(angle);
	p->z = y * sin(angle) + z * cos(angle);
}

void	rotate_y(t_point *p, float angle)
{
	float	x;
	float	z;

	x = p->x;
	z = p->z;
	p->x = x * cos(angle) + z * sin(angle);
	p->z = -x * sin(angle) + z * cos(angle);
}

void	rotate_z(t_point *p, float angle)
{
	float	x;
	float	y;

	x = p->x;
	y = p->y;
	p->x = x * cos(angle) - y * sin(angle);
	p->y = x * sin(angle) + y * cos(angle);
}
