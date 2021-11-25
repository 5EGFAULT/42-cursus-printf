/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:40:31 by asouinia          #+#    #+#             */
/*   Updated: 2021/11/25 17:40:32 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *s;
	int i;
	int j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (0);
	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (0);
	while (s1[++j])
		s[j] = s1[j];
	while (s2[++i])
		s[i + j] = s2[i];
	s[i + j] = '\0';
	free(s2);
	free(s1);
	return (s);
}

static int get_length(int n)
{
	int tmp;
	int len;

	tmp = n / 10;
	len = 1;
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	if (n < 0)
		len++;
	return (len);
}

char *ft_itoa(int n)
{
	int length;
	char *str;
	long tmp;
	int i;

	length = get_length(n);
	str = (char *)malloc(length + 1);
	if (!str)
		return (0);
	i = -1;
	tmp = n;
	if (n < 0)
		str[++i] = '-';
	if (n < 0)
		tmp *= -1;
	while (++i < length)
	{
		if (n < 0)
			str[length - i] = tmp - (tmp / 10) * 10 + '0';
		else
			str[length - i - 1] = tmp - (tmp / 10) * 10 + '0';
		tmp /= 10;
	}
	str[length] = '\0';
	return (str);
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		write(1, str + i, 1);
	return (i);
}

char *ft_address(char *str)
{
	char *s;
	int i;

	s = malloc(ft_strlen(str) + 2);
	if (!s || !str)
		return (NULL);
	i = 0;
	if (str[0] == '-')
	{
		s[0] = '-';
		i++;
	}
	s[i] = '0';
	s[i + 1] = 'x';
	while (str[i])
	{
		s[i + 2] = str[i];
		i++;
	}
	return (s);
}

char *ft_itoh(long n, int lower_upper)
{
	char *set;
	char *str;

	str = malloc(2);
	if (!str)
		return (NULL);
	str[1] = '\0';
	if (lower_upper)
		set = "0123456789ABCDEF";
	else
		set = "0123456789abcdef";
	if (n < 16 && n >= 0)
	{
		str[0] = set[n];
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		return (ft_strjoin(str, ft_itoh((-1 * n), lower_upper)));
	}
	str[0] = set[n % 16];
	return (ft_strjoin(ft_itoh(n / 16, lower_upper), str));
}

static int condition_check(char *str, int total, va_list args)
{
	if (*str == '%')
		total += ft_putchar('%');
	if (*str == 'c')
		total += ft_putchar(va_arg(args, int));
	if (*str == 's')
		total += ft_putstr(va_arg(args, char *));
	if (*str == 'd')
		total += ft_putstr(ft_itoa(va_arg(args, int)));
	if (*str == 'i')
		total += ft_putstr(ft_itoa(va_arg(args, int)));
	if (*str == 'u')
		total += ft_putstr(ft_itoa(va_arg(args, unsigned int)));
	if (*str == 'x')
		total += ft_putstr(ft_itoh((long)va_arg(args, int), 0));
	if (*str == 'X')
		total += ft_putstr(ft_itoh((long)va_arg(args, int), 1));
	if (*str == 'p')
		total += ft_putstr(ft_address(ft_itoh((long)va_arg(args, int), 1)));
	return (total);
}

int ft_printf(const char *str, ...)
{
	int total;
	int i;
	va_list args;

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
