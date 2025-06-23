/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:47:07 by iduman            #+#    #+#             */
/*   Updated: 2025/06/23 14:12:27 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# define HEXB "0123456789ABCDEF"
# define HEXL "0123456789abcdef"

char	*ft_strchr(const char *s, int c);
void	ft_putchar_counter(char c, int *count);
void	ft_putstr_counter(const char *c, int *count);
void	ft_putnbr_counter(long long n, int *count);
void	ft_puthex_counter(unsigned int n, int *count, char *base);
int		ft_printf(const char *format, ...);

#endif
