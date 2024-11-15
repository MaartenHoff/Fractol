/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:49:32 by maahoff           #+#    #+#             */
/*   Updated: 2024/10/23 16:26:18 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_fractol
{
	int		max_n;
	void	*mlx;
	void	*window;
	void	*image;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	x;
	double	y;
	double	n;
	double	jreal;
	double	jim;
	double	max_a;
	double	max_b;
	double	diff_a;
	double	min_a;
	double	min_b;
	double	diff_b;
	char	*name;
	double	zoom_level;
	int		color;
}	t_fractol;

// Mouse- / Keycodes
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define PLUS 46
# define MINUS 44
# define RESET 114
# define COLOR 99
# define ITERATE 105

void	init(t_fractol *fractol, char **argv);

int		key_hook(int key_code, t_fractol *fractol);
int		mouse_hook(int mouse_code, int x, int y, t_fractol *fractol);
int		close_window(t_fractol *fractol);

int		ft_color(t_fractol *fractol);
void	change_color(t_fractol *fractol);
int		safe_space(char color, int num, t_fractol *fractol);

void	ft_fractol(t_fractol *fractol, char *name);
void	ft_mandelbrot(double a, double b, t_fractol *fractol);
void	ft_julia(double a, double b, t_fractol *fractol);
void	ft_tricorn(double a, double b, t_fractol *fractol);
void	ft_burning_ship(double a, double b, t_fractol *fractol);

int		ft_strcmp(const char *s1, const char *s2);
void	error_check(int argc, char **argv, t_fractol *fractol);

#endif
