/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:36:55 by azusmano          #+#    #+#             */
/*   Updated: 2025/07/31 17:00:32 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	julia_iterations(t_render *v)
{
	double	tmp;

	v->iteration = 0;
	while ((v->z.r * v->z.r + v->z.i * v->z.i <= 4.0)
		&& (v->iteration < v->f->max_iter))
	{
		tmp = v->z.r * v->z.r - v->z.i * v->z.i + v->c.r;
		v->z.i = 2 * v->z.r * v->z.i + v->c.i;
		v->z.r = tmp;
		v->iteration++;
	}
	return (v->iteration);
}

void	render_julia(t_fractol *f)
{
	t_render	v;
	t_point		p;

	write(1, "Rendering Julia\n", 15);
	p.y = 0;
	while (p.y < HEIGHT)
	{
		p.x = 0;
		while (p.x < WIDTH)
		{
			v.f = f;
			v.x = p.x;
			v.y = p.y;

			set_julia_params(&v);

			int iter = julia_iterations(&v);

			int color = get_color(iter, f->max_iter, f->color_mode);
			put_pixel(f, v.x, v.y, color);

			p.x++;
		}
		p.y++;
	}
}
