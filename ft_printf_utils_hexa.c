/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hexa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeinado <apeinado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:11:57 by apeinado          #+#    #+#             */
/*   Updated: 2022/06/14 15:20:24 by apeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexad_min(unsigned int c, int tc)
{
	char	*base;

	base = "0123456789abcdef";
	if (c >= 16)
	{
		tc = ft_hexad_min(c / 16, tc);
		tc = ft_hexad_min(c % 16, tc);
	}
	else
	{
		ft_putchar(base[c]);
		tc++;
	}
	return (tc);
}

int	ft_dec(unsigned int c, int tc)
{
	char	*base;

	base = "0123456789";
	if (c >= 10)
	{
		tc = ft_dec(c / 10, tc);
		tc = ft_dec(c % 10, tc);
	}
	else
	{
		ft_putchar(base[c]);
		tc++;
	}
	return (tc);
}

int	ft_hexad_ma(unsigned int c, int tc)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (c >= 16)
	{
		tc = ft_hexad_ma(c / 16, tc);
		tc = ft_hexad_ma(c % 16, tc);
	}
	else
	{
		ft_putchar(base[c]);
		tc++;
	}
	return (tc);
}

int	ft_hexad_0x(unsigned long c, int tc, int boolean)
{
	char	*base;

	base = "0123456789abcdef";
	if (boolean)
	{
		write(1, "0x", 2);
		tc += 2;
	}
	if (c >= 16)
	{
		tc = ft_hexad_0x(c / 16, tc, 0);
		tc = ft_hexad_0x(c % 16, tc, 0);
	}
	else
	{
		ft_putchar(base[c]);
		tc++;
	}
	return (tc);
}
