/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:36:55 by azusmano          #+#    #+#             */
/*   Updated: 2025/07/30 15:29:16 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "../includes/fractol.h"
#include "../includes/ft_display_helpers.h"

void	display_fractal(t_fractol *f)
{
	char	buffer[100];

	if (f->fractal_type == JULIA)
	{
		ft_strcpy(buffer, "JULIA c = ");
		ft_ftoa(buffer + ft_strlen(buffer), f->julia_c.r, 4);
		ft_strcat(buffer, " + ");
		ft_ftoa(buffer + ft_strlen(buffer), f->julia_c.i, 4);
		ft_strcat(buffer, "i");
	}
	ft_strcpy(buffer, "Color mode: ");
	ft_itoa_to_buffer(f->color_mode, buffer + ft_strlen(buffer));
	ft_printf("Arrows: Julia | 1-6: Color mode | ESC: Exit\n");
}
