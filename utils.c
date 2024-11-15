/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:18:38 by maahoff           #+#    #+#             */
/*   Updated: 2024/10/22 14:29:08 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_double(char *str)
{
	int	i;
	int	dot_check;
	int	digit_check;

	i = 0;
	dot_check = 0;
	digit_check = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit_check = 1;
		else if (str[i] == '.')
		{
			if (dot_check)
				return (0);
			dot_check = 1;
		}
		else
			return (0);
		i++;
	}
	return (digit_check);
}

void	error_check(int argc, char **argv, t_fractol *fractol)
{
	if (argc == 2 && (!ft_strcmp(argv[1], "Mandelbrot") || !ft_strcmp(argv[1], \
"Tricorn") || !ft_strcmp(argv[1], "Burning_Ship")))
		return ;
	else if (!ft_strcmp(argv[1], "Julia") && argc == 4 && \
	is_double(argv[2]) && is_double(argv[3]))
		return ;
	else
	{
		write(1, "options: Mandelbrot, Julia +(real im),\
Tricorn, Burning_Ship\n", 62);
		free(fractol);
		exit(0);
	}
}
