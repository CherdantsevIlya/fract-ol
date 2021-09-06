/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:06:47 by pkari             #+#    #+#             */
/*   Updated: 2021/09/04 16:06:50 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_ship(t_data *f)
{
	double	swap;

	f->y = 0;
	while (f->y++ < HEIGHT)
	{
		f->x = 0;
		f->c_im = (f->y - HEIGHT / 2) / (0.25 * HEIGHT * f->zoom) + f->moveY;
		while (f->x++ < WIGHT)
		{
			f->c_re = (f->x - WIGHT / 2) / (0.25 * WIGHT * f->zoom) + f->moveX;
			f->i = 0;
			f->z_re = 0;
			f->z_im = 0;
			while (f->i++ < f->max_iteration && (pow(f->z_re, 2.0)
					+ pow(f->z_im, 2.0) <= 4))
			{
				swap = pow(f->z_re, 2.0) - pow(f->z_im, 2.0) + f->c_re;
				f->z_im = 2 * fabs(f->z_re * f->z_im) + f->c_im;
				f->z_re = swap;
			}
			if (pow(f->z_re, 2.0) + pow(f->z_im, 2.0) > 4)
				color(f);
		}
	}
}

void	ship(t_data *f)
{
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	draw_ship(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr->img, 0, 0);
}
