/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:36:55 by azusmano          #+#    #+#             */
/*   Updated: 2025/07/31 17:36:05 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	handle_color_mode(mlx_key_data_t keydata, t_fractol *f)
{
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_1)
		f->color_mode = 0;
	else if (keydata.key == MLX_KEY_2)
		f->color_mode = 1;
	else if (keydata.key == MLX_KEY_3)
		f->color_mode = 2;
	else if (keydata.key == MLX_KEY_4)
		f->color_mode = 3;
	else if (keydata.key == MLX_KEY_5)
		f->color_mode = 4;
	else if (keydata.key == MLX_KEY_6)
		f->color_mode = 5;
	else if (keydata.key == MLX_KEY_7)
		f->color_mode = 6;
	else if (keydata.key == MLX_KEY_8)
		f->color_mode = 7;
	else if (keydata.key == MLX_KEY_9)
		f->color_mode = 8;
}

void	handle_zoom_key(mlx_key_data_t keydata, t_fractol *f)
{
	if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		f->zoom *= 1.1;
	else if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		f->zoom /= 1.1;
}

void	handle_arrow_pan(mlx_key_data_t keydata, t_fractol *f)
{
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_LEFT)
		f->offset_x -= 0.1 / f->zoom;
	else if (keydata.key == MLX_KEY_RIGHT)
		f->offset_x += 0.1 / f->zoom;
	else if (keydata.key == MLX_KEY_UP)
		f->offset_y -= 0.1 / f->zoom;
	else if (keydata.key == MLX_KEY_DOWN)
		f->offset_y += 0.1 / f->zoom;
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_fractol *f = (t_fractol *)param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_window(f);

	handle_arrow_pan(keydata, f);
	handle_color_mode(keydata, f);
	handle_zoom_key(keydata, f);

	render_fractal(f);
}
