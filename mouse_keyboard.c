/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:07:24 by maahoff           #+#    #+#             */
/*   Updated: 2024/10/23 16:02:18 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractol *fractol, double zoom_factor, int r)
{
	if (r)
	{
		fractol->zoom_level = 1;
		fractol->max_a = 2;
		fractol->max_b = 2;
		fractol->min_a = -2;
		fractol->min_b = -2;
	}
	else 
	{
		fractol->zoom_level *= zoom_factor;
		fractol->max_a -= (fractol->diff_a / 2) - \
		((fractol->diff_a / 2) * zoom_factor);
		fractol->max_b -= (fractol->diff_b / 2) - \
		((fractol->diff_b / 2) * zoom_factor);
		fractol->min_a += (fractol->diff_a / 2) - \
		((fractol->diff_a / 2) * zoom_factor);
		fractol->min_b += (fractol->diff_b / 2) - \
		((fractol->diff_b / 2) * zoom_factor);
	}
	fractol->diff_a = fractol->max_a - fractol->min_a;
	fractol->diff_b = fractol->max_b - fractol->min_b;
}

void	move(t_fractol *fractol, int dir)
{
	if (dir == UP)
	{
		fractol->max_b += 0.8 * fractol->zoom_level;
		fractol->min_b += 0.8 * fractol->zoom_level;
	}
	else if (dir == RIGHT)
	{
		fractol->max_a += 0.8 * fractol->zoom_level;
		fractol->min_a += 0.8 * fractol->zoom_level;
	}
	else if (dir == DOWN)
	{
		fractol->max_b -= 0.8 * fractol->zoom_level;
		fractol->min_b -= 0.8 * fractol->zoom_level;
	}
	else if (dir == LEFT)
	{
		fractol->max_a -= 0.8 * fractol->zoom_level;
		fractol->min_a -= 0.8 * fractol->zoom_level;
	}
	fractol->diff_a = fractol->max_a - fractol->min_a;
	fractol->diff_b = fractol->max_b - fractol->min_b;
}

int	key_hook(int key_code, t_fractol *fractol)
{
	if (key_code == ESC)
		close_window(fractol);
	else if (key_code == PLUS)
		zoom(fractol, 0.9, 0);
	else if (key_code == MINUS)
		zoom(fractol, 1.1, 0);
	else if (key_code == RESET)
		zoom(fractol, 0, 1);
	else if (key_code == UP)
		move(fractol, UP);
	else if (key_code == RIGHT)
		move(fractol, RIGHT);
	else if (key_code == DOWN)
		move(fractol, DOWN);
	else if (key_code == LEFT)
		move(fractol, LEFT);
	else if (key_code == COLOR)
		change_color(fractol);
	else if (key_code == ITERATE)
		fractol->max_n += 10;
	else
		fractol->color = 0;
	ft_fractol(fractol, fractol->name);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractol *fractol)
{
	x = y;
	if (mouse_code == SCROLL_UP)
		zoom(fractol, 0.9, 0);
	if (mouse_code == SCROLL_DOWN)
		zoom(fractol, 1.1, 0);
	ft_fractol(fractol, fractol->name);
	return (0);
}

int	close_window(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->window);
	free(fractol);
	exit(0);
}
