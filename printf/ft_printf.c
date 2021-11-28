/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:40:31 by asouinia          #+#    #+#             */
/*   Updated: 2021/11/28 17:32:23 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	condition_check(char *str, int total, va_list args)
{
	if (*str == '%')
		total += ft_putchar('%');
	if (*str == 'c')
		total += ft_putchar(va_arg(args, int));
	if (*str == 's')
		total += ft_putstr(va_arg(args, char *));
	if (*str == 'd')
		total += ft_putnbr(va_arg(args, int), 0);
	if (*str == 'i')
		total += ft_putnbr(va_arg(args, int), 0);
	if (*str == 'u')
		total += ft_putnbr(va_arg(args, unsigned int), 0);
	if (*str == 'x')
		total += ft_printhex(va_arg(args, unsigned int), 0, 0);
	if (*str == 'X')
		total += ft_printhex(va_arg(args, unsigned int), 1, 0);
	if (*str == 'p')
		total += ft_address((unsigned long)va_arg(args, void *));
	return (total);
}

int	ft_printf(const char *str, ...)
{
	int		total;
	int		i;
	va_list	args;

	i = -1;
	total = 0;
	va_start(args, str);
	while (str && str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			total = condition_check((char *)str + i, total, args);
		}
		else
			total += ft_putchar(str[i]);
	}
	return (total);
}
