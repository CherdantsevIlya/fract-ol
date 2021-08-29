#ifndef FRACTOL_H
#define FRACTOL_H

#include "../minilibx_opengl/mlx.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1280;
#define HEIGHT 720;

typedef struct		s_img
{
	void			*img_ptr;
	int  			*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef	struct	s_complex
{
	double 		re;
	double 		im;
}				t_complex;

typedef struct		s_color
{
	unsigned char 	r;
	unsigned char 	g;
	unsigned char 	b;
}					t_color;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	t_image			*img;
	char			*name;
	int				max_iteration;
	double 			newRe;
	double			newIm;
	double			oldRe;
	double 			oldIm;
	double 			pixRe;
	double 			pixIm;
	double 			moveX;
	double 			moveY;
	double 			zoom;
	//t_complex		min;
	//t_complex		max;
	//t_complex		factor;
	//t_complex		c;
	t_complex		k;
	//int				start_line;
	//int				finish_line;
	int				color;
}					t_data;

void	*ft_memalloc(size_t size);
void ft_error(char *s);
t_complex	init_complex(double re, double im);

#endif //FRACTOL_H
