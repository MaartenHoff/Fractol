/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:16:16 by maahoff           #+#    #+#             */
/*   Updated: 2024/10/22 16:37:21 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	zj_check(double real, double im)
{
	double	z;

	z = (real * real) + (im * im);
	if (z <= 4)
		return (1);
	return (0);
}

void	ft_julia(double a, double b, t_fractol *fractol)
{
	double	real;
	double	im;
	double	t_real;
	double	t_im;
	int		n;

	real = a;
	im = b;
	fractol->n = 0;
	n = 0;
	while (++n < fractol->max_n && zj_check(real, im))
	{
		t_real = real;
		t_im = im;
		real = t_real * t_real + fractol->jreal -(t_im * t_im);
		im = 2 * (t_im * t_real) + fractol->jim;
	}
	fractol->n = n;
}
