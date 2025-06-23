/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:58:18 by iduman            #+#    #+#             */
/*   Updated: 2025/06/23 14:06:20 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (1)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
}

void	ft_putchar_counter(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr_counter(const char *c, int *count)
{
	if (c == NULL)
		return (ft_putstr_counter("(null)", count));
	while (*c)
	{
		ft_putchar_counter(*c, count);
		c++;
	}
}

void	ft_putnbr_counter(long long n, int *count)
{
	long long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_counter('-', count);
	}
	if (nbr >= 10)
	{
		ft_putnbr_counter(nbr / 10, count);
		ft_putchar_counter((nbr % 10) + '0', count);
		nbr /= 10;
	}
	else
	{
		ft_putchar_counter(nbr + '0', count);
	}
}

void	ft_puthex_counter(unsigned int n, int *count, char *base)
{
	int	temp;
	int	turn;

	if (n < 0)
	{
		turn = 4;
		while (turn--)
		{
			temp = *(((unsigned char *)(&n)) + turn);
			ft_putchar_counter(base[(temp / 16) % 16], count);
			ft_putchar_counter(base[temp % 16], count);
		}
	}
	else
	{
		if (n >= 16)
		{
			ft_puthex_counter(n / 16, count, base);
			ft_putchar_counter(base[n % 16], count);
			n /= 16;
		}
		else
			ft_putchar_counter(base[n % 16], count);
	}
}
