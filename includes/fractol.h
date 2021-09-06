/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:19:27 by pkari             #+#    #+#             */
/*   Updated: 2021/09/04 16:19:29 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIGHT 720
# define HEIGHT 720

typedef struct s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			size_l;
	int			end;
}				t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img_ptr;
	char		*name;
	int			max_iteration;
	int			i;
	int			x;
	int			y;
	double		moveX;
	double		moveY;
	double		zoom;
	double		c_re;
	double		c_im;
	double		z_re;
	double		z_im;
	int			color;
}				t_data;

void	fractol(t_data *f);
void	ft_error(char *s);
t_data	*init_data(char *s);
t_img	*init_img(void *mlx);
void	mandelbrot(t_data *f);
void	draw_mandelbrot(t_data *f);
void	julia(t_data *f);
void	draw_julia(t_data *f);
void	ship(t_data *f);
void	draw_ship(t_data *f);
void	color(t_data *f);
int		key_press(int keycode, t_data *f);
int		mouse_press(int button, int x, int y, t_data *f);
int		mouse_move(int x, int y, t_data *f);
void	help(void);

#endif
