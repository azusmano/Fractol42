/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:00:54 by azusmano          #+#    #+#             */
/*   Updated: 2025/08/01 07:43:25 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "../includes/fractol.h"
#include <stdlib.h>

static void move_view(mlx_key_data_t keydata, t_fractol *f)
{
	if (keydata.action != MLX_PRESS)
		return;
	if (keydata.key == MLX_KEY_LEFT)
		f->offset_x -= 0.1 / f->zoom;
	else if (keydata.key == MLX_KEY_RIGHT)
		f->offset_x += 0.1 / f->zoom;
	else if (keydata.key == MLX_KEY_UP)
		f->offset_y -= 0.1 / f->zoom;
	else if (keydata.key == MLX_KEY_DOWN)
		f->offset_y += 0.1 / f->zoom;
}

static void handle_color_switch(mlx_key_data_t keydata, t_fractol *f)
{
	if (keydata.action == MLX_PRESS &&
		keydata.key >= MLX_KEY_1 && keydata.key <= MLX_KEY_9)
	{
		f->color_mode = keydata.key - MLX_KEY_1;
	}
}

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractol *f = (t_fractol *)param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		cleanup(f);
		exit(EXIT_SUCCESS);
	}

	move_view(keydata, f);
	handle_color_switch(keydata, f);
	handle_julia(keydata, f);
	handle_zoom(keydata, f);

	draw_fractal(f);
}

void mouse_hook(double xdelta, double ydelta, void *param)
{
	t_fractol *f = (t_fractol *)param;
	int32_t x, y;
	(void)xdelta;

	mlx_get_mouse_pos(f->mlx, &x, &y);

	if (ydelta > 0)
		zoom(f, ZOOM_FACTOR, (double)x, (double)y);
	else if (ydelta < 0)
		zoom(f, 1.0 / ZOOM_FACTOR, (double)x, (double)y);

	draw_fractal(f);
}

void setup_hooks(t_fractol *f)
{
	mlx_key_hook(f->mlx, key_hook, f);
	mlx_scroll_hook(f->mlx, mouse_hook, f);
	mlx_close_hook(f->mlx, close_window, f);
}

void close_window(void *param)
{
	t_fractol *f = (t_fractol *)param;
	
	cleanup(f);
	exit (EXIT_SUCCESS);
}

