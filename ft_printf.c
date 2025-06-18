/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:42:05 by iduman            #+#    #+#             */
/*   Updated: 2025/06/18 19:27:02 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pointer_helper(void *pointer, int *count)
{
	if (pointer == NULL)
		return (ft_putstr_counter("(nil)", count));
	ft_putstr_counter("0x", count);
	ft_pointer_counter((size_t)pointer, count, HEXL);
}

void	ft_pointer_counter(size_t n, int *count, char *base)
{
	if (n >= 16)
		ft_pointer_counter(n / 16, count, base);
	ft_putchar_counter(base[n % 16], count);
}

void	formatter(char c, int *count, va_list args)
{
	if (c == 'c')
		ft_putchar_counter((char)va_arg(args, int), count);
	else if (c == 's')
		ft_putstr_counter(va_arg(args, char *), count);
	else if (c == 'p')
		pointer_helper(va_arg(args, void *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_counter(va_arg(args, int), count);
	else if (c == 'u')
		ft_putnbr_counter((unsigned int)va_arg(args, int), count);
	else if (c == 'X')
		ft_puthex_counter(va_arg(args, int), count, HEXB);
	else if (c == 'x')
		ft_puthex_counter(va_arg(args, int), count, HEXL);
	else
		ft_putchar_counter(c, count);
}

int	is_need_format(const char *format, va_list args, int *count)
{
	if (*(format + 1))
	{
		if (*(format + 1) && ft_strchr("cspdiuxX%", *(format + 1)))
		{
			formatter(*(format + 1), count, args);
			return (1);
		}
		ft_putchar_counter(*format, count);
		return (0);
	}
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		tmp;
	va_list	args;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			tmp = is_need_format(format, args, &count);
			if (tmp == -1)
				return (-1);
			format += tmp;
		}
		else
			ft_putchar_counter(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}
