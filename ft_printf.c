/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghuzlan <mghuzlan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:28:50 by mghuzlan          #+#    #+#             */
/*   Updated: 2026/10/23 20:20:45 by mghuzlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	typecheck(char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar((va_arg(args, int))));
	else if (type == 's')
		return (ft_putstr((va_arg(args, char *))));
	else if (type == 'p')
		return (ft_putpoint(va_arg(args, void *)));
	else if (type == 'i' || type == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_putun(va_arg(args, unsigned int)));
	else if (type == 'x')
		return (ft_putlohex(va_arg(args, unsigned int)));
	else if (type == 'X')
		return (ft_putuphex(va_arg(args, unsigned int)));
	else if (type == '%')
		write(1, "%", 1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		co;
	va_list	args;

	i = 0;
	co = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			co += write(1, &format[i], 1);
			++i;
		}
		if (format[i] == '%')
		{
			co += typecheck(format[++i], args);
			i++;
		}
	}
	va_end(args);
	return (co);
}
