/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:59:45 by maahoff           #+#    #+#             */
/*   Updated: 2024/10/23 16:35:42 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	safe_space(char color, int num, t_fractol *fractol);
int	ft_color_lava(int red, int green, int blue, t_fractol *fractol);
int	ft_color_one(int red, int green, int blue, t_fractol *fractol);
int	ft_color_fire(int red, int green, int blue, t_fractol *fractol);

int	ft_color(t_fractol *fractol)
{
	int	red; 
	int	green; 
	int	blue;

	red = 0;
	green = 0;
	blue = 0;
	if (fractol->color == 0)
		return (ft_color_lava(red, green, blue, fractol));
	else if (fractol->color == 1)
		return (ft_color_one(red, green, blue, fractol));
	else
		return (ft_color_fire(red, green, blue, fractol));
}

int	ft_color_lava(int red, int green, int blue, t_fractol *fractol)
{
	if (fractol->n < fractol->max_n / 5.5)
	{
		green = (fractol->n * 255) / (fractol->max_n / 5.5);
		blue = (fractol->n * 255) / (fractol->max_n / 5.5);
	}
	else if (fractol->n <= (fractol->max_n / 3.125))
		red = safe_space('r', 1, fractol);
	else if (fractol->n <= (fractol->max_n / 2.38))
	{
		red = 255;
		green = safe_space('g', 1, fractol);
	}
	else if (fractol->n <= (fractol->max_n / 1.66))
	{
		red = 255;
		green = safe_space('g', 2, fractol);
	}
	else if (fractol->n < fractol->max_n)
	{
		red = 255 - (fractol->n - (fractol->max_n / 1.66)) * 255 \
		/ (fractol->max_n / 2.5);
		blue = (fractol->n - (fractol->max_n / 1.66)) * 255 / \
		(fractol->max_n / 2.5);
	}
	return ((red << 16) | (green << 8) | blue);
}

int	ft_color_one(int red, int green, int blue, t_fractol *fractol)
{
	if (fractol->n < fractol->max_n)
	{
		green = (fractol->n * 255) / fractol->max_n;
		blue = (fractol->n * 255) / fractol->max_n;
	}
	return ((red << 16) | (green << 8) | blue);
}

int	ft_color_fire(int red, int green, int blue, t_fractol *fractol)
{
	if (fractol->n < fractol->max_n / 8)
	{
		red = (fractol->n * 50) / (fractol->max_n / 8);
	}
	else if (fractol->n < fractol->max_n / 4)
		red = safe_space('r', 2, fractol);
	else if (fractol->n < fractol->max_n / 2)
	{
		red = 255;
		green = (fractol->n - (fractol->max_n / 4)) * \
		128 / (fractol->max_n / 4);
	}
	else if (fractol->n < (3 * fractol->max_n) / 4)
	{
		red = 255;
		green = 128 + (fractol->n - (fractol->max_n / 2)) \
		* 127 / (fractol->max_n / 4);
	}
	else if (fractol->n < fractol->max_n)
	{
		red = 255;
		green = 255;
		blue = safe_space('b', 1, fractol);
	}
	return ((red << 16) | (green << 8) | blue);
}

void	change_color(t_fractol *fractol)
{
	if (fractol->color < 2)
		fractol->color++;
	else
		fractol->color = 0;
}
