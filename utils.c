#include "../includes/fractol.h"

void	*ft_memalloc(size_t size)
{
	char    *tab;
	size_t  i;

	tab = (char *)malloc(sizeof(char) * (size + 1));
	if (tab == NULL)
		return (tab);
	i = 0;
	while (i < size)
		tab[i++] = 0;
	tab[i] = 0;
	return (tab);
}

void ft_error(char *s)
{
	ft_putstr(s);
	ft_putchar(1, "\n", 1);
	exit(0);
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}
