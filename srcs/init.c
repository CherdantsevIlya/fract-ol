/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:06:24 by pkari             #+#    #+#             */
/*   Updated: 2021/09/04 16:06:26 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_img	*init_img(void *mlx)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (img == NULL)
		ft_error("\x1b[31mError: malloc failed\x1b[0m");
	img->img = mlx_new_image(mlx, WIGHT, HEIGHT);
	if (img->img == NULL)
		ft_error("\x1b[31mError: img failed\x1b[0m");
	img->data = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_l),
			&(img->end));
	img->bpp /= 8;
	return (img);
}

t_data	*init_data(char *s)
{
	t_data	*f;

	f = (t_data *)malloc(sizeof(t_data));
	if (f == NULL)
		ft_error("\x1b[31mError: malloc failed\x1b[0m");
	f->name = s;
	f->max_iteration = 50;
	f->zoom = 1;
	f->moveX = 0;
	f->moveY = 0;
	f->color = 0;
	f->mlx_ptr = mlx_init();
	if (f->mlx_ptr == NULL)
		ft_error("\x1b[31mError: mlx failed\x1b[0m");
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIGHT, HEIGHT, f->name);
	if (f->win_ptr == NULL)
		ft_error("\x1b[31mError: win failed\x1b[0m");
	return (f);
}
