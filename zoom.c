/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:36:55 by azusmano          #+#    #+#             */
/*   Updated: 2025/07/31 11:47:44 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom(t_fractol *f, double zoom_factor, int x, int y)
{
	double	mouse_r;
	double	mouse_i;
	double new_zoom;

	mouse_r = (x - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH) + f->offset_x;
	mouse_i = (y - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT) + f->offset_y;
	new_zoom = f->zoom * zoom_factor;
	f->offset_x = mouse_r - (x - WIDTH / 2.0) / (0.5 * new_zoom * WIDTH);
	f->offset_y = mouse_i - (y - HEIGHT / 2.0) / (0.5 * new_zoom * HEIGHT);
	f->zoom = new_zoom;
}
