/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:36:55 by azusmano          #+#    #+#             */
/*   Updated: 2025/07/27 21:28:41 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	parse_sign(const char **str, int *sign)
{
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
}

static void	parse_fraction(const char **str, double *frac, int *divider)
{
	while (**str && **str >= '0' && **str <= '9')
	{
		*frac = *frac * 10.0 + (**str - '0');
		*divider *= 10;
		(*str)++;
	}
}

double	ft_atof(const char *str)
{
	double	result;
	double	frac;
	int		sign;
	int		divider;

	result = 0.0;
	frac = 0.0;
	sign = 1;
	divider = 1;
	parse_sign(&str, &sign);
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		parse_fraction(&str, &frac, &divider);
	}
	return (sign * (result + frac / divider));
}
