/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:42:05 by iduman            #+#    #+#             */
/*   Updated: 2025/06/16 18:52:53 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myprintf.h"

void	ft_pointer_counter(size_t n, int *count, char *base)
{
	if (n >= 16)
		ft_pointer_counter(n / 16, count, base);
	ft_putchar_counter(base[n % 16], count);
}

int	formatter(char c, int *count, va_list args)
{
	char	*hexb;
	char	*hexl;

	hexb = "0123456789ABCDEF";
	hexl = "0123456789abcdef";
	if (c == 'c')
		ft_putchar_counter((char)va_arg(args, int), count);
	else if (c == 's')
		ft_putstr_counter(va_arg(args, char *), count);
	else if (c == 'p')
		ft_pointer_counter((size_t)va_arg(args, void *), count, hexl);
	else if (c == 'd' || c == 'i')
		ft_putnbr_counter(va_arg(args, int), count);
	else if (c == 'u')
		ft_putnbr_counter((unsigned int)va_arg(args, int), count);
	else if (c == 'X')
		ft_puthex_counter(va_arg(args, int), count, hexb);
	else if (c == 'x')
		ft_puthex_counter(va_arg(args, int), count, hexl);
	else
		return (-1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) && ft_strchr("cspdiuxX%", *(format + 1)))
			{
				if (formatter(*(format + 1), &count, args) == -1)
					return (-1);
				format++;
			}
			else
				return (-1);
		}
		else
			ft_putchar_counter(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}
