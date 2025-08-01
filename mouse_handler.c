/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:36:55 by azusmano          #+#    #+#             */
/*   Updated: 2025/07/31 12:11:12 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void handle_scroll(double xdelta, double ydelta, void *param)
{
	
	(void)xdelta;
	(void)ydelta;
	
	t_fractol *f = (t_fractol *)param;

	if (ydelta > 0)
		zoom(f, ZOOM_FACTOR, WIDTH / 2, HEIGHT / 2);
	else if (ydelta < 0)
		zoom(f, 1.0 / ZOOM_FACTOR, WIDTH / 2, HEIGHT / 2);

	render_fractal(f);
}
