/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:00:54 by azusmano          #+#    #+#             */
/*   Updated: 2025/07/30 12:12:57 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_julia(t_fractol *f, double re, double im)
{
	f->fractal_type = JULIA;
	f->julia_c.r = re;
	f->julia_c.i = im;
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->max_iter = 100;
	f->color_mode = 0;
}

void	init_mandelbrot(t_fractol *f, const char *type)
{
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->max_iter = 100;
	f->color_mode = 0;
	if (ft_strcmp(type, "mandelbrot") == 0)
		f->fractal_type = MANDELBROT;
	else if (ft_strcmp(type, "julia") == 0)
		f->fractal_type = JULIA;
}
