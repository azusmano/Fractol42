/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:36:55 by azusmano          #+#    #+#             */
/*   Updated: 2025/08/01 09:19:17 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <math.h>

static int handle_special_case(double v)
{
    int color;
    color = (int)(v * 255);
    return ((color << 24) | (color << 16) | (color << 8) | 0xFF);
}

static void assign_rgb(double r, double g, double b, double rgb[3])
{
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;
}

static void get_rgb_values(double h, double s, double v, double rgb[3])
{
    double p;
    double q;
    double t;
    int i;
    double f;
    
    h /= 60.0;
    i = (int)floor(h);
    f = h - i;
    p = v * (1.0 - s);
    q = v * (1.0 - f * s);
    t = v * (1.0 - (1.0 - f) * s);
    
    if (i == 0)
        assign_rgb(v, t, p, rgb);
    else if (i == 1)
        assign_rgb(q, v, p, rgb);
    else if (i == 2)
        assign_rgb(p, v, t, rgb);
    else if (i == 3)
        assign_rgb(p, q, v, rgb);
    else if (i == 4)
        assign_rgb(t, p, v, rgb);
    else
        assign_rgb(v, p, q, rgb);
}

int hsv_to_rgb(double h, double s, double v)
{
    double rgb[3];
    int r;
    int g;
    int b;
    
    if (s == 0)
        return (handle_special_case(v));
    
    get_rgb_values(h, s, v, rgb);
    r = (int)(rgb[0] * 255);
    g = (int)(rgb[1] * 255);
    b = (int)(rgb[2] * 255);
    
    r = (r < 0) ? 0 : (r > 255) ? 255 : r;
    g = (g < 0) ? 0 : (g > 255) ? 255 : g;
    b = (b < 0) ? 0 : (b > 255) ? 255 : b;
    
    return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

uint32_t get_color(int iteration, int max_iter, int color_mode)
{
    if (iteration >= max_iter)
        return (0x000000FF);
    
    double t = (double)iteration / max_iter;
    uint8_t r, g, b;
    
    switch (color_mode)
    {
        case 0:
            r = 0;
            g = (uint8_t)(255 * t);
            b = 255;
            break;
        case 1:
            r = (uint8_t)(255 * t);
            g = 0;
            b = 0;
            break;
        case 2:
            r = 0;
            g = (uint8_t)(255 * t);
            b = 0;
            break;
        case 3:
            r = (uint8_t)(128 * t);
            g = 0;
            b = (uint8_t)(255 * t);
            break;
        case 4:
            return (hsv_to_rgb(t * 360.0, 1.0, 1.0));
        case 5:
            r = 255;
            g = (uint8_t)(165 * t);
            b = 0;
            break;
        case 6:
            r = 0;
            g = (uint8_t)(255 * t);
            b = (uint8_t)(255 * t);
            break;
        case 7:
            r = (uint8_t)(255 * t);
            g = (uint8_t)(255 * t);
            b = 0;
            break;
        case 8:
            r = 255;
            g = (uint8_t)(192 * t);
            b = (uint8_t)(203 * t);
            break;
        default:
            r = (uint8_t)(255 * t);
            g = (uint8_t)(255 * t);
            b = (uint8_t)(255 * t);
            break;
    }
    
    return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

void draw_pixel(t_fractol *f, int x, int y, int iteration)
{
    uint32_t color;
    
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    
    if (iteration >= f->max_iter)
        color = 0x000000FF;
    else
        color = get_color(iteration, f->max_iter, f->color_mode);
    
    mlx_put_pixel(f->img, x, y, color);
}
