/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:06:30 by pkari             #+#    #+#             */
/*   Updated: 2021/09/04 16:06:33 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_julia(t_data *f)
{
	double	swap;

	f->y = 0;
	while (f->y++ < HEIGHT)
	{
		f->x = 0;
		while (f->x++ < WIGHT)
		{
			f->i = 0;
			f->z_re = (f->x - WIGHT / 2) / (0.25 * WIGHT * f->zoom) + f->moveX;
			f->z_im = (f->y - HEIGHT / 2) / (0.25 * HEIGHT * f->zoom)
				+ f->moveY;
			while (f->i++ < f->max_iteration && (pow(f->z_re, 2.0)
					+ pow(f->z_im, 2.0) <= 4))
			{
				swap = pow(f->z_re, 2.0) - pow(f->z_im, 2.0) + f->c_re;
				f->z_im = 2 * f->z_re * f->z_im + f->c_im;
				f->z_re = swap;
			}
			if (pow(f->z_re, 2.0) + pow(f->z_im, 2.0) > 4)
				color(f);
		}
	}
}

void	julia(t_data *f)
{
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	draw_julia(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr->img, 0, 0);
}
