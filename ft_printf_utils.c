/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeinado <apeinado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:58:50 by apeinado          #+#    #+#             */
/*   Updated: 2022/06/14 15:18:58 by apeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr(int c, int tc)
{
	if (c == -2147483648)
		tc += ft_putstr("-2147483648");
	else if (c < 0)
	{
		ft_putchar('-');
		tc++;
		tc = ft_putnbr(c * -1, tc);
	}
	else if (c < 10)
	{
		ft_putchar(c + 48);
		tc++;
	}
	else if (c >= 10)
	{
		tc = ft_putnbr(c / 10, tc);
		ft_putchar((c % 10) + '0');
		tc++;
	}
	return (tc);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if ((*str) == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (i += 6);
	}
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}
	return (i);
}
