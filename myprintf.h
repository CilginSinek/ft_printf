/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:47:07 by iduman            #+#    #+#             */
/*   Updated: 2025/06/16 18:54:05 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYPRINTF_H
# define MYPRINTF_H
# include <unistd.h>
# include <stdarg.h>

char	*ft_strchr(const char *s, int c);
void	ft_putchar_counter(char c, int *count);
void	ft_putstr_counter(const char *c, int *count);
void	ft_putnbr_counter(int n, int *count);
void	ft_puthex_counter(int n, int *count, char *base);
void	ft_pointer_counter(size_t n, int *count, char *base);
int		formatter(char c, int *count, va_list args);
int		ft_printf(const char *format, ...);

#endif
