/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 02:14:59 by asouinia          #+#    #+#             */
/*   Updated: 2021/11/28 02:20:51 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putnbr(long n, int counter);
int	ft_putstr(char *str);
int	ft_printhex(size_t n, int lower_upper, int counter);
int	ft_address(size_t addr);
int	ft_printf(const char *str, ...);

#endif
