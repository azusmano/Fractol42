/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_helpers.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azusmano <azusmano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:36:55 by azusmano          #+#    #+#             */
/*   Updated: 2025/07/27 21:19:13 by azusmano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_HELPERS_H
# define FT_DISPLAY_HELPERS_H

int		ft_strlen(const char *s);
void	ft_strcpy(char *dst, const char *src);
void	ft_strcat(char *dst, const char *src);
void	ft_itoa_to_buffer(int n, char *buf);
void	ft_ftoa(char *buf, double n, int precision);
int		ft_isdigit(int c);

#endif
