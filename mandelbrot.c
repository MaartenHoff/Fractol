/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:30:20 by maahoff           #+#    #+#             */
/*   Updated: 2024/10/22 16:37:21 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	z_check(double real, double im)
{
	double	z;

	z = (real * real) + (im * im);
	if (z <= 4)
		return (1);
	return (0);
}

void	ft_mandelbrot(double a, double b, t_fractol *fractol)
{
	double	real;
	double	im;
	double	t_real;
	double	t_im;

	real = a;
	im = b;
	t_real = 0;
	t_im = 0;
	fractol->n = 0;
	while (fractol->n < fractol->max_n && z_check(real, im))
	{
		t_real = real;
		t_im = im;
		real = t_real * t_real + a -(t_im * t_im);
		im = 2 * (t_im * t_real) + b;
		fractol->n++;
	}
}
