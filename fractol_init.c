/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:36:55 by azusmano          #+#    #+#             */
/*   Updated: 2025/08/01 09:42:47 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "../includes/fractol.h"
#include "../includes/ft_display_helpers.h"
#include <stdlib.h>
#include <unistd.h>

static int init_graphics(t_fractol *f)
{
    f->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
    if (!f->mlx)
    {
        write(2, "Error: failed to initialize MLX42\n", 34);
        return (0);
    }
    
    f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    if (!f->img)
    {
        write(2, "Error: failed to create image\n", 31);
        return (0);
    }
    
    f->img_buffer = (uint32_t *)f->img->pixels;
    if (!f->img_buffer)
    {
        write(2, "Error: failed to get image buffer\n", 35);
        return (0);
    }
    
    return (1);
}

int init_fractol(t_fractol *f, char *type)
{
    f->mlx = NULL;
    f->img = NULL;
    f->img_buffer = NULL;
    
    if (!init_graphics(f))
    {
        cleanup(f);
        return (0);
    }
    
    f->zoom = 1.0;
    f->offset_x = 0.0;
    f->offset_y = 0.0;
    f->julia_c.r = -0.8;
    f->julia_c.i = 0.156;
    f->julia_offset_x = 0.0;
    f->julia_offset_y = 0.0;
    f->pan_x = 0.0;
    f->pan_y = 0.0;
    f->max_iter = MAX_ITER;
    f->color_mode = 0;
    
    if (ft_strncmp(type, "mandelbrot", 10) == 0)
        f->fractal_type = MANDELBROT;
    else if (ft_strncmp(type, "julia", 5) == 0)
        f->fractal_type = JULIA;
    else
    {
        write(2, "Error: Unknown fractal type\n", 29);
        cleanup(f);
        return (0);
    }
    
    return (1);
}
