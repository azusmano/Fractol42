/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_helpers_float.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:36:55 by azusmano          #+#    #+#             */
/*   Updated: 2025/07/27 21:18:05 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/ft_display_helpers.h"

void	ft_ftoa(char *buf, double n, int precision)
{
	int		int_part;
	double	frac;
	int		i;

	i = 0;
	if (n < 0)
	{
		buf[i++] = '-';
		n = -n;
	}
	int_part = (int)n;
	ft_itoa_to_buffer(int_part, buf + i);
	i += ft_strlen(buf + i);
	buf[i++] = '.';
	frac = n - int_part;
	while (precision-- > 0)
	{
		frac *= 10;
		buf[i++] = '0' + ((int)frac % 10);
	}
	buf[i] = '\0';
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
