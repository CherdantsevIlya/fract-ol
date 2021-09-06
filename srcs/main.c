/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:05:59 by pkari             #+#    #+#             */
/*   Updated: 2021/09/04 16:06:02 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_error(char *s)
{
	ft_putendl(s);
	exit(0);
}

void	help(void)
{
	ft_putendl(NULL);
	ft_putendl("\x1b[42m	RULES FOR USE	       \x1b[0m");
	ft_putendl("\x1b[32mMovements:	[W] [A] [S] [D]\x1b[0m");
	ft_putendl("\x1b[32m		[^] [<] [v] [>]");
	ft_putendl("\x1b[32mZoom:		mouse wheel\x1b[0m");
	ft_putendl("\x1b[32mIterations:	[+] [-]\x1b[0m");
	ft_putendl("\x1b[32mColor:		[C]\x1b[0m");
	ft_putendl("\x1b[32mExit:		[esc]\x1b[0m");
	ft_putendl("\x1b[42m			       \x1b[0m");
}

void	fractol(t_data *f)
{
	if (!ft_strcmp(f->name, "mandelbrot"))
		mandelbrot(f);
	else if (!ft_strcmp(f->name, "julia"))
		mlx_hook(f->win_ptr, 6, 0, mouse_move, f);
	else if (!ft_strcmp(f->name, "ship"))
		ship(f);
}

int	main(int argc, char **argv)
{
	t_data	*f;

	if (argc != 2)
		ft_error("\x1b[31mError: ./fractol [fractal name]\x1b[0m");
	if (ft_strcmp(argv[1], "mandelbrot")
		&& ft_strcmp(argv[1], "julia") && ft_strcmp(argv[1], "ship"))
		ft_error("\x1b[31mError: use [mandelbrot] or [julia] or [ship]\x1b[0m");
	f = init_data(argv[1]);
	f->img_ptr = init_img(f->mlx_ptr);
	fractol(f);
	mlx_hook(f->win_ptr, 2, 0, key_press, f);
	mlx_hook(f->win_ptr, 4, 0, mouse_press, f);
	help();
	mlx_loop(f->mlx_ptr);
	return (0);
}
