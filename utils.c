/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:00:54 by azusmano          #+#    #+#             */
/*   Updated: 2025/07/31 11:20:20 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <unistd.h>
#include <stdlib.h>
#include "../includes/ft_display_helpers.h"
double ft_atof(const char *str);

void	print_usage(void)
{
	write(1, "\033[34mUsage: \033[0m\n", 16);
	write(1, " \033[32m./fractol mandelbrot\033[0m\n", 31);
	write(1, " \033[32m./fractol julia <real> <imaginary>\033[0m\n", 47);
}

void	print_error(void)
{
	write(2, "\033[33mError: Invalid parameters\033[0m\n", 36);
}

int	is_valid_number(const char *s)
{
	int	dot_seen;

	dot_seen = 0;
	if (*s == '-' || *s == '+')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s == '.')
		{
			if (dot_seen)
				return (0);
			dot_seen = 1;
		}
		else if (!ft_isdigit((unsigned char)*s))
			return (0);
		s++;
	}
	return (1);
}

int	handle_args(t_fractol *f, int argc, char **argv)
{
	double	re;
	double	im;

	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		if (argc != 2)
			return (1);
		init_mandelbrot(f, "mandelbrot");
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc == 4 && is_valid_number(argv[2]) && is_valid_number(argv[3]))
		{
			re = ft_atof(argv[2]);
			im = ft_atof(argv[3]);
			init_julia(f, re, im);
		}
		else
			return (1);
	}
	else
		return (1);
	return (0);
}

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		ptr[i] = 0;
		i++;
	}
}
