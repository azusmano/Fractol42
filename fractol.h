/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:00:54 by azusmano          #+#    #+#             */
/*   Updated: 2025/08/01 09:23:18 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <math.h>
# include "../libft/libft.h"
# include <MLX42/MLX42.h>

# define MAX_ITER 100
# define WIDTH 800
# define HEIGHT 800
# define ZOOM_FACTOR 1.1

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA
}	t_fractal_type;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_fractol
{
	mlx_t		*mlx;
	int			fractal_type;
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		scale;
	int			max_iter;
	t_complex	julia_c;
	int			color_mode;
	double		julia_offset_x;
	double		julia_offset_y;
	double		pan_x;
	double		pan_y;
	int			color_shift;
	int			mouse_lock;
	mlx_image_t	*img;
	uint32_t	*img_buffer;
}	t_fractol;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_render
{
	int			x;
	int			y;
	t_fractol	*f;
	t_complex	c;
	t_complex	z;
	int			iteration;
	int			color;
}	t_render;

void	put_pixel(t_fractol *f, int x, int y, uint32_t color);
uint32_t	get_color(int iteration, int max_iter, int color_mode);
void	close_window(void *param);

void	initialize_vars(t_render *vars, t_fractol *f);
void	set_fractal_params(t_render *v);
void	set_mandelbrot_params(t_render *v);
void	set_julia_params(t_render *v);
int		calculate_julia(t_render *v);
int		calculate_mandelbrot(t_render *v);
void	calculate_and_draw_pixel(t_render *v);

void	render_fractal(t_fractol *f);
void	iterate_image(t_render *v);

void	setup_hooks(t_fractol *f);

int		init_fractol(t_fractol *f, char *type);
void	display_info(t_fractol *f);
void	draw_fractal(t_fractol *f);

void	mouse_hook(double xdelta, double ydelta, void *param);
void	key_hook(mlx_key_data_t keydata, void *param);
void	handle_mouse_zoom(mouse_key_t button, double x, double y, void *param);
void	handle_scroll(double xdelta, double ydelta, void *param);

int		init_mlx(t_fractol *f);
void	init_controls(t_fractol *f);
void	init_image(t_fractol *f);
void	init_julia(t_fractol *f, double c_re, double c_im);
void	init_mandelbrot(t_fractol *f, const char *type);
void	handle_julia(mlx_key_data_t keydata, t_fractol *f);
void	handle_color_mode(mlx_key_data_t keydata, t_fractol *f);
void	handle_zoom(mlx_key_data_t keydata, t_fractol *f);
void	cleanup(t_fractol *f);
void	ft_bzero(void *s, size_t len);
void	print_error(void);
void	print_usage(void);
int		handle_args(t_fractol *f, int argc, char **argv);
void	zoom(t_fractol *f, double zoom_factor, int x, int y);
void	render_mandelbrot(t_fractol *f);
void	render_julia(t_fractol *f);
void	key_handler(mlx_key_data_t keydata, void *param);
void	draw_pixel(t_fractol *f, int x, int y, int iteration);

#endif
