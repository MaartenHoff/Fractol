/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:22:46 by maahoff           #+#    #+#             */
/*   Updated: 2024/10/23 16:33:16 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	safe_space(char color, int num, t_fractol *fractol)
{
	if (color == 'r' && num == 1)
	{
		return ((fractol->n - (fractol->max_n / 5.5)) * 255 \
		/ (fractol->max_n / 7.14));
	}
	else if (color == 'g' && num == 1)
	{
		return ((fractol->n - (fractol->max_n / 3.125)) \
		* 255 / (fractol->max_n / 10));
	}
	else if (color == 'g' && num == 2)
	{
		return (255 - (fractol->n - (fractol->max_n / 2.38)) \
		* 255 / (fractol->max_n / 5.5));
	}
	else if (color == 'r' && num == 2)
	{
		return (50 + (fractol->n - (fractol->max_n / 8)) * 205 / \
		(fractol->max_n / 8));
	}
	else
	{
		return ((fractol->n - (3 * fractol->max_n) / 4) \
		* 255 / (fractol->max_n / 4));
	}
}
