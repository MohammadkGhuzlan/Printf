/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghuzlan <mghuzlan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:09:11 by mghuzlan          #+#    #+#             */
/*   Updated: 2026/10/23 12:00:14 by mghuzlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpoint(void *ptr)
{
	char	*digits;
	char	re[20];
	int		i;
	int		co;
	size_t	x;

	i = 0;
	co = 0;
	x = (size_t)ptr;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	digits = "0123456789abcdef";
	co += write(1, "0x", 2);
	while (x > 0)
	{
		re[i++] = digits[x % 16];
		x /= 16;
	}
	while (i > 0)
	{
		co += write(1, &re[--i], 1);
	}
	return (co);
}
