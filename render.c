/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:36:55 by azusmano          #+#    #+#             */
/*   Updated: 2025/07/31 14:14:48 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	iterate_image(t_render *v)
{
	while (v->y < HEIGHT)
	{
		v->x = 0;
		while (v->x < WIDTH)
		{
			calculate_and_draw_pixel(v);
			v->x++;
		}
		v->y++;
	}
}

void	render_fractal(t_fractol *f)
{
	t_render	v;

	initialize_vars(&v, f);
	iterate_image(&v);
}
