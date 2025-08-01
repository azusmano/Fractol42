/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:00:54 by azusmano          #+#    #+#             */
/*   Updated: 2025/08/01 09:41:39 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdlib.h>
#include <unistd.h>
#include "../includes/ft_display_helpers.h"
#include "../libft/libft.h"
#include "MLX42/MLX42.h"

int main(int argc, char **argv)
{
    t_fractol f;
    
    ft_bzero(&f, sizeof(t_fractol));
    
    if (argc < 2)
    {
        print_error();
        print_usage();
        return (1);
    }
    
    if (handle_args(&f, argc, argv) != 0)
    {
        print_error();
        print_usage();
        return (1);
    }
    
    if (!init_fractol(&f, argv[1]))
    {
        write(2, "Error: Fractal initialization failed\n", 37);
        cleanup(&f);
        return (1);
    }
    
    if (mlx_image_to_window(f.mlx, f.img, 0, 0) < 0)
    {
        write(2, "Error: failed to put image to window\n", 37);
        cleanup(&f);
        return (1);
    }
    
    ft_printf("Fractal type: %d\n", f.fractal_type);
    
    render_fractal(&f);
    
    setup_hooks(&f);
    
    mlx_loop(f.mlx);
    
    return (0);
}
