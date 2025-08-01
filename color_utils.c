/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:36:55 by azusmano          #+#    #+#             */
/*   Updated: 2025/08/01 09:27:33 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <math.h>

int	get_color_mode4(int iter)
{
	int	r = fmax(0, fmin(255, (int)(sin(0.016 * iter + 4) * 127 + 128)));
	int	g = fmax(0, fmin(255, (int)(sin(0.013 * iter + 2) * 127 + 128)));
	int	b = fmax(0, fmin(255, (int)(sin(0.01 * iter + 1) * 127 + 128)));
	return ((r << 16) | (g << 8) | b);
}

int	get_color_mode5(int iter)
{
	int r = (iter * 9) % 256;
	int g = (iter * 2) % 256;
	int b = (iter * 1) % 256;
	return ((r << 16) | (g << 8) | b);
}

int	get_color_mode6(int iter)
{
	int r = (int)(127 + 127 * sin(0.1 * iter));
	int g = (int)(127 + 127 * sin(0.15 * iter + 2));
	int b = (int)(127 + 127 * sin(0.2 * iter + 4));
	return ((r << 16) | (g << 8) | b);
}

int	get_color_alt(int iter, int max_iter, int mode)
{
	double	t;

	if (max_iter <= 0)
		max_iter = 1;
	if (iter >= max_iter)
		return (0x000000);
	t = (double)iter / max_iter;

	if (mode == 0)
	{
		return (((int)(9 * (1 - t) * t * t * t * 255) << 16)
			| ((int)(15 * (1 - t) * (1 - t) * t * t * 255) << 8)
			| ((int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255)));
	}
	else if (mode == 1)
		return ((int)(t * 255) << 16);
	else if (mode == 2)
		return ((int)(t * 255) << 8);
	else if (mode == 3)
		return ((int)(t * 255));
	else if (mode == 4)
		return (get_color_mode4(iter));
	else if (mode == 5)
		return (get_color_mode5(iter));
	else if (mode == 6)
		return (get_color_mode6(iter));
	else if (mode == 7)
		return ((iter * 5) << 8 | (iter * 3));
	else if (mode == 8)
		return ((iter * 2) << 16 | (iter * 4));
	else
		return (get_color_mode4(iter));
}
