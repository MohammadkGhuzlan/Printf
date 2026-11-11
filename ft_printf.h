/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghuzlan <mghuzlan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 10:56:00 by mghuzlan          #+#    #+#             */
/*   Updated: 2026/10/23 13:12:21 by mghuzlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putuphex(unsigned int x);
int		ft_putlohex(unsigned int x);
int		ft_putun(unsigned int nb);
int		ft_putpoint(void *ptr);
int		ft_putstr(char *str);

#endif