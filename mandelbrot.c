/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:00:54 by azusmano          #+#    #+#             */
/*   Updated: 2025/07/31 17:01:11 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_mandelbrot_values(t_point p, double *pr,
	double *pi, t_fractol *f)
{
	*pr = 1.5 * (p.x - WIDTH / 2) / (0.5 * f->zoom * WIDTH) + f->offset_x;
	*pi = (p.y - HEIGHT / 2) / (0.5 * f->zoom * HEIGHT) + f->offset_y;
}

static int	mandelbrot_iterations(double pr, double pi, t_fractol *f)
{
	int		iter;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	iter = 0;
	while (zr * zr + zi * zi <= 4 && iter < f->max_iter)
	{
		tmp = zr * zr - zi * zi + pr;
		zi = 2 * zr * zi + pi;
		zr = tmp;
		iter++;
	}
	return (iter);
}

static void	iterate_pixels(t_fractol *f, t_point p)
{
	double	pr;
	double	pi;
	int		iter;

	init_mandelbrot_values(p, &pr, &pi, f);
	iter = mandelbrot_iterations(pr, pi, f);
	put_pixel(f, p.x, p.y, get_color(iter, f->max_iter, f->color_mode));
}

void	render_mandelbrot(t_fractol *f)
{
	t_point	p;

	write(1, "Rendering Mandelbrot\n", 22);
	p.y = 0;
	while (p.y < HEIGHT)
	{
		p.x = 0;
		while (p.x < WIDTH)
		{
			iterate_pixels(f, p);
			p.x++;
		}
		p.y++;
	}
}
