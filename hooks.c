#include "../includes/fractol.h"

int key_press(int keycode, t_data *f)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 126 || keycode == 13)
		f->moveY -= 0.5;
	else if (keycode == 125 || keycode == 1)
		f->moveX += 0.5;
	else if (keycode == 124 || keycode == 2)
		f->moveY += 0.5;
	else if (keycode == 123 || keycode == 0)
		f->moveY -= 0.5;
	else if (keycode == 69 || keycode == 24)
		f->zoom *= 0.8;
	else if (keycode == 78 || keycode == 27)
		f->zoom *= 1.25;
	else if (keycode == 8)
		f->color += 1;
	if (ft_strcmp(f->name, "mandelbrot") == 0)
		mandelbrot(f, 0, 0, 0);
	else if (ft_strcmp(f->name, "julia") == 0)
		julia(f, 0, 0, 0);
	else if (ft_strcmp(f->name, "--_[._.]_--") == 0)
		xz(f, 0, 0, 0);
	return (0);
}

int mouse_press(int button, int x, int y, t_data *f)
{
	if (button == 4)
		f->zoom *= 0.8;
	else if (button == 5)
		f->zoom *= 1.25;
	if (ft_strcmp(f->name, "mandelbrot") == 0)
		mandelbrot(f, 0, 0, 0);
	else if (ft_strcmp(f->name, "julia") == 0)
		julia(f, 0, 0, 0);
	else if (ft_strcmp(f->name, "--_[._.]_--") == 0)
		xz(f, 0, 0, 0);
	return (0);
}

int mouse_move(int x, int y, t_data *f)
{
	if (ft_strcmp(f->name, "julia") == 0)
		f->k = init_complex(4 * ((double)x / WIDTH - 0.5), 4 * ((double)
		(HEIGHT - y) / HEIGHT - 0.5));
	julia(f, 0, 0, 0);
	return (0);
}

