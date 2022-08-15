/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeinado <apeinado@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:02:54 by apeinado          #+#    #+#             */
/*   Updated: 2022/06/14 15:20:30 by apeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

void	ft_putchar(char c);
int		ft_putnbr(int c, int tc);
int		ft_printf(char const *juan, ...);
char	*ft_strchr(const char *str, int c);
int		ft_putstr(char *str);
int		ft_dec(unsigned int c, int tc);
int		ft_hexad_min(unsigned int c, int tc);
int		ft_hexad_ma(unsigned int c, int tc);
int		ft_hexad_0x(unsigned long c, int tc, int boolean);
int		ft_cspdiuxx(char juan, int cnt, va_list paco);
int		ft_printf(char const *juan, ...);

#endif