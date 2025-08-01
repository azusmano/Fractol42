/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:00:54 by azusmano          #+#    #+#             */
/*   Updated: 2025/04/30 15:06:53 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "../includes/fractol.h"

void	set_mandelbrot_params(t_render *v);
void	set_julia_params(t_render *v);
void	initialize_vars(t_render *vars, t_fractol *f);
void	calculate_and_draw_pixel(t_render *v);
void	calculate_julia(t_render *v);

#endif
