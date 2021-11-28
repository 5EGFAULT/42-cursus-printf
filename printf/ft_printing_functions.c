/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 02:12:52 by asouinia          #+#    #+#             */
/*   Updated: 2021/11/28 15:49:00 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(long n, int counter)
{
	if (n < 0)
	{
		ft_putchar('-');
		return (ft_putnbr(n * -1, 0) + 1);
	}
	if (n < 10 && n >= 0)
		return (ft_putchar('0' + n));
	counter += ft_putnbr(n / 10, counter);
	counter += ft_putchar('0' + (n % 10));
	return (counter);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)"));
	i = -1;
	while (str && str[++i] != '\0')
		write(1, str + i, 1);
	return (i);
}

int	ft_printhex(unsigned long n, int lower_upper, int counter)
{
	char	*set;

	if (lower_upper)
		set = "0123456789ABCDEF";
	else
		set = "0123456789abcdef";
	if (n < 16 && n >= 0)
		return (ft_putchar(set[n]));
	counter = ft_printhex(n / 16, lower_upper, counter);
	ft_putchar(set[n % 16]);
	counter++;
	return (counter);
}

int	ft_address(unsigned long addr)
{
	ft_putchar('0');
	ft_putchar('x');
	return (ft_printhex(addr, 0, 0) + 2);
}
