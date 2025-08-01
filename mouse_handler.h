/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:00:54 by azusmano          #+#    #+#             */
/*   Updated: 2025/04/30 19:28:58 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mouse_handler.h"

int	handle_mouse_zoom(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4)
		zoom(fractol, 0.8, x, y);
	else if (button == 5)
		zoom(fractol, 1.2, x, y);
	return (0);
}
