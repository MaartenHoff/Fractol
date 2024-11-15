/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:01:15 by maahoff           #+#    #+#             */
/*   Updated: 2024/10/23 16:15:06 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_window(t_fractol *fractol, double a, double b)
{
	char	*dst;
	int		color;

	fractol->x = (a - fractol->min_a) * (WIDTH / (fractol->diff_a));
	fractol->y = HEIGHT - ((b - fractol->min_b) * (HEIGHT / \
			(fractol->diff_b)));
	color = ft_color(fractol);
	dst = fractol->addr + ((int)fractol->y * \
	fractol->line_length + (int)fractol->x * \
		(fractol->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	ft_fractol(t_fractol *fractol, char *name)
{
	double	a;
	double	b;

	a = fractol->min_a;
	while (a <= fractol->max_a)
	{
		b = fractol->min_b;
		while (b <= fractol->max_b)
		{
			if (!(ft_strcmp(name, "Mandelbrot")))
				ft_mandelbrot(a, b, fractol);
			if (!(ft_strcmp(name, "Burning_Ship")))
				ft_burning_ship(a, b, fractol);
			else if (!ft_strcmp(name, "Julia"))
				ft_julia(a, b, fractol);
			else if (!(ft_strcmp(name, "Tricorn")))
				ft_tricorn(a, b, fractol);
			fill_window(fractol, a, b);
			b += fractol->diff_b / (HEIGHT * 2);
		}
		a += fractol->diff_a / (WIDTH * 2);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window, \
		fractol->image, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	if (!fractol)
		return (1);
	if (argc > 1)
		error_check(argc, argv, fractol);
	else
	{
		free (fractol);
		write(1, "options: Mandelbrot, Julia +(real im),\
Tricorn, Burning_Ship\n", 62);
		return (0);
	}
	init(fractol, argv);
	ft_fractol(fractol, fractol->name);
	mlx_mouse_hook(fractol->window, mouse_hook, fractol);
	mlx_key_hook(fractol->window, key_hook, fractol);
	mlx_hook(fractol->window, 17, 0, close_window, fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
