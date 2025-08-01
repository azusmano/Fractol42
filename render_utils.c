/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:00:54 by azusmano          #+#    #+#             */
/*   Updated: 2025/07/31 16:53:50 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	initialize_vars(t_render *vars, t_fractol *f)
{
	vars->x = 0;
	vars->y = 0;
	vars->f = f;
}

void	set_fractal_params(t_render *v)
{
	if (v->f->fractal_type == MANDELBROT)
		set_mandelbrot_params(v);
	else if (v->f->fractal_type == JULIA)
		set_julia_params(v);
}

void	calculate_and_draw_pixel(t_render *v)
{
	int	iteration;

	if (v->f->fractal_type == MANDELBROT)
		iteration = calculate_mandelbrot(v);
	else if (v->f->fractal_type == JULIA)
		iteration = calculate_julia(v);
	else
		iteration = 0;

	int color = get_color(iteration, v->f->max_iter, v->f->color_mode);
	put_pixel(v->f, v->x, v->y, color);
}
