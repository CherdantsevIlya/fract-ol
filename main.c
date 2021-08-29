#include "../includes/fractol.h"

t_img *init_img(void *mlx)
{
	t_img *img;

	if (!(img = (t_img *)ft_memalloc(sizeof(t_img))))
		ft_error("Error: malloc failed");
	if (!(img->img_ptr = mlx_new_image(mlx, WIDTH, HEIGHT)))
		ft_error("Error: img failed");
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l,
								  &img->endian);
	return (img);
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void 	mandelbrot(t_data *f, int x, int y, int i)
{
	f->moveX = -0.5;
	f->moveY = 0;
	f->zoom = 1;
	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			f->pixRe = (1.5 * (x - (WIDTH / 2)) / (0.5 * WIDTH * f->zoom) +
					f->moveX);
			f->pixIm = (((y - HEIGHT/2) / (0.5 * f->zoom * HEIGHT)) +
					f->moveY);
			i = 0;
			while ((i++ < f->max_iteration) && ((pow(f->newRe, 2.0) + pow
			(f->newIm, 2.0)) <= 4))
			{
				f->oldRe = f->newRe;
				f->oldIm = f->newIm;
				f->newRe = pow(f->oldRe, 2.0) - pow(f->oldIm, 2.0) + f->pixRe;
				f->newIm = 2 * f->oldRe * f->oldIm + f->pixIm;
			}
			if ((pow(f->newRe, 2.0) + pow(f->newIm, 2.0)) <= 4)
				color(f, i, x, y);
		}
	}
}

void		init_data(t_data *f, char **argv)
{
	f->name = argv[1];
	if (!(f->mlx = mlx_init()))
		ft_error("Error:	mlx failed");
	if (!(f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract'ol - "
	f->name)))
		fr_error("Error: win failed");
	f->max_iteration = 50;
	f->color = 0;
	f->newRe = 0;
	f->newIm = 0;
	f->oldRe = 0;
	f->oldIm = 0;
	//f->min = init_complex(-2.0, -2.0);
	//f->max.re = 2.0;
	//f->max.im = (f->min.im + (f->max.re - f->min.re) * HEIGHT / WIDTH);
}

void	fractol(t_data *f)
{
	if (ft_strcmp(f->name, "mandelbrot") == 0)
		mandelbrot();
	else if (ft_strcmp(f->name, "julia") == 0)
		julia();
	else if (ft_strcmp(f->name, "--_[._.]_--") == 0)
		xz();
}

int main(int argc, char **argv)
{
	t_data	*f;
	void	*mlx;

	if (!(f = (t_data *)ft_memalloc(sizeof(t_data))))
		ft_error("Error:	malloc failed");
	if (argc != 2 && (ft_strcmp(argv[1], "mandelbrot") != 0
					  || ft_strcmp(argv[1], "julia") != 0))
		ft_error("Error:	./fractol	mandelbrot | julia");
	init_data(f, argv);
	mlx = f->mlx;
	f->img = init_img(mlx);
	if (ft_strcmp(f->name, "mandelbrot") == 0)
		mandelbrot(f, 0, 0, 0);
	else if (ft_strcmp(f->name, "julia") == 0)
		julia();
	else if (ft_strcmp(f->name, "--_[._.]_--") == 0)
		xz();
	mlx_hook(f->win, 2, 0, key_press, f);
	mlx_hook(f->win, 4, 0, mouse_press, f);
	mlx_hook(f->win, 6, 0, mouse_move, f);
	mlx_loop(f->mlx);
	return (0);
}
