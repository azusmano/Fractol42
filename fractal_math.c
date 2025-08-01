/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:36:55 by azusmano          #+#    #+#             */
/*   Updated: 2025/07/31 16:59:12 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int calculate_mandelbrot(t_render *v)
{
	double tmp;

	set_mandelbrot_params(v);
	v->iteration = 0;
	while ((v->z.r * v->z.r + v->z.i * v->z.i <= 4.0)
		&& (v->iteration < v->f->max_iter))
	{
		tmp = v->z.r * v->z.r - v->z.i * v->z.i + v->c.r;
		v->z.i = 2.0 * v->z.r * v->z.i + v->c.i;
		v->z.r = tmp;
		v->iteration++;
	}
	v->color = get_color(v->iteration, v->f->max_iter, v->f->color_mode);
	put_pixel(v->f, v->x, v->y, v->color);
	return (v->iteration);
}

int calculate_julia(t_render *v)
{
	double tmp;

	set_julia_params(v);
	v->iteration = 0;
	while ((v->z.r * v->z.r + v->z.i * v->z.i <= 4.0)
		&& (v->iteration < v->f->max_iter))
	{
		tmp = v->z.r * v->z.r - v->z.i * v->z.i + v->c.r;
		v->z.i = 2.0 * v->z.r * v->z.i + v->c.i;
		v->z.r = tmp;
		v->iteration++;
	}
	v->color = get_color(v->iteration, v->f->max_iter, v->f->color_mode);
	put_pixel(v->f, v->x, v->y, v->color);
	return (v->iteration);
}

void set_mandelbrot_params(t_render *v)
{
	v->c.r = (v->x - WIDTH / 2.0)
		/ (0.5 * v->f->zoom * WIDTH) + v->f->offset_x;
	v->c.i = (v->y - HEIGHT / 2.0)
		/ (0.5 * v->f->zoom * HEIGHT) + v->f->offset_y;
	v->z.r = 0.0;
	v->z.i = 0.0;
}

void set_julia_params(t_render *v)
{
	v->z.r = (v->x - WIDTH / 2.0)
		/ (0.5 * v->f->zoom * WIDTH) + v->f->offset_x;
	v->z.i = (v->y - HEIGHT / 2.0)
		/ (0.5 * v->f->zoom * HEIGHT) + v->f->offset_y;
	v->c.r = v->f->julia_c.r;
	v->c.i = v->f->julia_c.i;
}
