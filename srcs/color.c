/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:06:08 by pkari             #+#    #+#             */
/*   Updated: 2021/09/04 16:06:11 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	color(t_data *f)
{
	int		pixel;
	double	t;

	t = (double)f->i / f->max_iteration;
	pixel = (f->y * f->img_ptr->size_l + 4 * f->x);
	f->color = f->color % 3;
	if (f->color == 0)
	{
		f->img_ptr->data[pixel + 0] = (int)(9 * (1 - t) * t * t * t * 255);
		f->img_ptr->data[pixel + 1] = (int)(15 * (1 - t) * (1 - t) * t * t
				* 255);
		f->img_ptr->data[pixel + 2] = (int)(8.5 * (1 - t) * (1 - t) * (1 - t)
				* t * 255);
	}
	else if (f->color == 1)
	{
		f->img_ptr->data[pixel] = (int)(6 * (1 - t) * (1 - t) * (1 - t)
				* t * 255);
		f->img_ptr->data[pixel + 1] = (int)(9 * (1 - t) * t * t * t * 255);
	}
	else if (f->color == 2)
		f->img_ptr->data[pixel + 2] = (int)(10 * (1 - t) * t * t * t * 255);
}
