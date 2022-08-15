/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeinado <apeinado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:40:50 by apeinado          #+#    #+#             */
/*   Updated: 2022/06/14 15:13:45 by apeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cspdiuxx(char juan, int cnt, va_list paco)
{
	if (juan == 'c')
	{
		ft_putchar(va_arg(paco, int));
		cnt++;
	}
	else if (juan == 's')
		cnt += ft_putstr(va_arg(paco, char *));
	else if (juan == 'p')
		cnt = ft_hexad_0x(va_arg(paco, unsigned long), cnt, 1);
	else if (juan == 'd')
		cnt = ft_putnbr(va_arg(paco, int), cnt);
	else if (juan == 'i')
		cnt = ft_putnbr(va_arg(paco, int), cnt);
	else if (juan == 'u')
		cnt = ft_dec(va_arg(paco, unsigned int), cnt);
	else if (juan == 'x')
		cnt = ft_hexad_min(va_arg(paco, unsigned int), cnt);
	else if (juan == 'X')
		cnt = ft_hexad_ma(va_arg(paco, unsigned int), cnt);
	else if (juan == '%')
	{
		ft_putchar('%');
		cnt++;
	}
	return (cnt);
}

int	ft_printf(char const *juan, ...)
{
	va_list	paco;
	int		cnt;
	int		i;

	va_start(paco, juan);
	i = 0;
	cnt = 0;
	while (juan[i])
	{
		if (juan[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", juan[i + 1]))
				cnt = ft_cspdiuxx(juan[i++ + 1], cnt, paco);
		}
		else
		{
			ft_putchar(juan[i]);
			cnt++;
		}
		i++;
	}
	va_end(paco);
	return (cnt);
}
