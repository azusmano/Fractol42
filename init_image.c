/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:00:54 by azusmano          #+#    #+#             */
/*   Updated: 2025/08/01 11:36:38 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "../includes/fractol.h"

void init_image(t_fractol *f)
{
    if (f->img && f->mlx)
    {
        mlx_delete_image(f->mlx, f->img);
        f->img = NULL;
        f->img_buffer = NULL;
    }
    
    f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    if (!f->img)
    {
        write(2, "Failed to create image\n", 24);
        cleanup(f);
        exit(EXIT_FAILURE);
    }
    
    f->img_buffer = (uint32_t *)f->img->pixels;
    if (!f->img_buffer)
    {
        write(2, "Error getting image buffer\n", 28);
        cleanup(f);
        exit(EXIT_FAILURE);
    }
}
