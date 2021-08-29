#include "../includes/fractol.h"

int getRGB(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

int color_zero(int i, int max, int n)
{
	int color[16];

	if (i < max && i > 0)
	{
		color[0] = getRGB(66, 30, 15);
		color[1] = getRGB(25, 7, 26);
		color[2] = getRGB(9, 1, 47);
		color[3] = getRGB(4, 4, 73);
		color[4] = getRGB(0, 7, 100);
		color[5] = getRGB(12, 44, 138);
		color[6] = getRGB(24, 82, 177);
		color[7] = getRGB(57, 125, 209);
		color[8] = getRGB(134, 181, 229);
		color[9] = getRGB(211, 236, 248);
		color[10] = getRGB(241, 233, 191);
		color[11] = getRGB(248, 201, 95);
		color[12] = getRGB(255, 170, 0);
		color[13] = getRGB(204, 128, 0);
		color[14] = getRGB(153, 87, 0);
		color[15] = getRGB(106, 52, 3);
		return (color[n]);
	}
	else
		return(getRGB(0, 0, 0));
}

int color_one(int i, int max, int n)
{
	int color[16];

	if (i < max && i > 0)
	{
		color[0] = getRGB(33, 66, 30);
		color[1] = getRGB(45, 87, 44);
		color[2] = getRGB(40, 114, 51);
		color[3] = getRGB(76,145,65);
		color[4] = getRGB(100, 170, 90);
		color[5] = getRGB(119, 199, 127);
		color[6] = getRGB(173,223, 173);
		color[7] = getRGB(230, 250, 230);
		color[8] = getRGB(237, 222, 250);
		color[9] = getRGB(213, 179, 242);
		color[10] = getRGB(190, 138, 235);
		color[11] = getRGB(166,95,227);
		color[12] = getRGB(140,50,219);
		color[13] = getRGB(115,34,186);
		color[14] = getRGB(88, 26, 143);
		color[15] = getRGB(61, 18, 99);
		return (color[n]);
	}
	else
		return(getRGB(0, 0, 0));
}

int color_two(int i, int max, int n)
{
	int color[16];

	if (i < max && i > 0)
	{
		color[0] = getRGB(66, 30, 15);
		color[1] = getRGB(25, 7, 26);
		color[2] = getRGB(9, 1, 47);
		color[3] = getRGB(4, 4, 73);
		color[4] = getRGB(0, 7, 100);
		color[5] = getRGB(12, 44, 138);
		color[6] = getRGB(24, 82, 177);
		color[7] = getRGB(57, 125, 209);
		color[8] = getRGB(134, 181, 229);
		color[9] = getRGB(211, 236, 248);
		color[10] = getRGB(241, 233, 191);
		color[11] = getRGB(248, 201, 95);
		color[12] = getRGB(255, 170, 0);
		color[13] = getRGB(204, 128, 0);
		color[14] = getRGB(153, 87, 0);
		color[15] = getRGB(106, 52, 3);
		return (color[n]);
	}
	else
		return(getRGB(0, 0, 0));
}

void 	color(t_data *f, int i, int x, int y)
{
	t_img *img;
	int pixel;
	int n;

	n = i % 16;
	pixel = y * img->size_l + x;
	f->color = f->color % 3;
	if (f->color == 0)
		img->data[pixel] = color_zero(i, f->max_iteration, n);
	else if (f->color == 1)
		img->data[pixel] = color_one(i, f->max_iteration, n);
	else if (f->color == 2)
		img->data[pixel] = color_two(i, f->max_iteration, n);
}