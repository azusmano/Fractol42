/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_helpers_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:36:55 by azusmano          #+#    #+#             */
/*   Updated: 2025/07/27 21:16:46 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/ft_display_helpers.h"

static int	ft_fill_tmp(int n, char *tmp)
{
	int	len;
	int	temp;

	len = 0;
	temp = n;
	while (temp > 0)
	{
		tmp[len++] = '0' + (temp % 10);
		temp /= 10;
	}
	return (len);
}

void	ft_itoa_to_buffer(int n, char *buf)
{
	int		len;
	char	tmp[12];
	int		neg;
	int		i;

	if (n == 0)
		return ((void)(buf[0] = '0', buf[1] = '\0'));
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	len = ft_fill_tmp(n, tmp);
	if (neg)
		tmp[len++] = '-';
	i = -1;
	while (++i < len)
		buf[i] = tmp[len - 1 - i];
	buf[len] = '\0';
}
