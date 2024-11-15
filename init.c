/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:26:24 by maahoff           #+#    #+#             */
/*   Updated: 2024/10/22 16:43:03 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_some_more(t_fractol *fractol)
{
	fractol->max_a = 2;
	fractol->max_b = 2;
	fractol->min_a = -2;
	fractol->min_b = -2;
	fractol->diff_a = fractol->max_a - fractol->min_a;
	fractol->diff_b = fractol->max_b - fractol->min_b;
	fractol->color = 0;
	fractol->zoom_level = 1;
	fractol->max_n = 10;
}

void	init(t_fractol *(fractol), char **argv)
{
	fractol->mlx = mlx_init();
	fractol->window = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "fract-ol");
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->addr = mlx_get_data_addr(fractol->image, &fractol->bits_per_pixel, \
			&fractol->line_length, &fractol->endian);
	init_some_more(fractol);
	if (!ft_strcmp(argv[1], "Mandelbrot"))
		fractol->name = "Mandelbrot";
	else if (!ft_strcmp(argv[1], "Julia"))
	{
		fractol->name = "Julia";
		fractol->jreal = strtod(argv[2], NULL);
		fractol->jim = strtod(argv[3], NULL);
	}
	else if (!ft_strcmp(argv[1], "Tricorn"))
		fractol->name = "Tricorn";
	else if (!ft_strcmp(argv[1], "Burning_Ship"))
		fractol->name = "Burning_Ship";
}
/*	fractol->max_a = -1.70;
	fractol->max_b = 0.08;
	fractol->min_a = -1.8;
	fractol->min_b = -0.02;*/
