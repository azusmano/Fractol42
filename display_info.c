/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:36:55 by azusmano          #+#    #+#             */
/*   Updated: 2025/07/31 11:13:23 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "../includes/fractol.h"
#include "../includes/ft_display_helpers.h"

void	display_julia_params(t_fractol *f)
{
	char	buffer[100];

	if (f->fractal_type == JULIA)
	{
		ft_strcpy(buffer, "Julia c = ");
		ft_ftoa(buffer + ft_strlen(buffer), f->julia_c.r, 4);
		ft_strcat(buffer, " + ");
		ft_ftoa(buffer + ft_strlen(buffer), f->julia_c.i, 4);
		ft_strcat(buffer, "i");
		ft_printf("%s\n", buffer);
	}
	ft_strcpy(buffer, "Color mode: ");
	ft_itoa_to_buffer(f->color_mode, buffer + ft_strlen(buffer));
	ft_printf("%s\n", buffer);
}

void	display_info(t_fractol *f)
{
	char	buffer[200];

	if (f->fractal_type == MANDELBROT)
		ft_printf("Fractal: Mandelbrot\n");
	else if (f->fractal_type == JULIA)
		ft_printf("Fractal: Julia\n");

	ft_strcpy(buffer, "Zoom: ");
	ft_ftoa(buffer + ft_strlen(buffer), f->zoom, 2);
	ft_printf("%s\n", buffer);

	ft_strcpy(buffer, "Offset X: ");
	ft_ftoa(buffer + ft_strlen(buffer), f->offset_x, 2);
	ft_strcat(buffer, ", Y: ");
	ft_ftoa(buffer + ft_strlen(buffer), f->offset_y, 2);
	ft_printf("%s\n", buffer);

	ft_strcpy(buffer, "Max Iterations: ");
	ft_itoa_to_buffer(f->max_iter, buffer + ft_strlen(buffer));
	ft_printf("%s\n", buffer);
}
