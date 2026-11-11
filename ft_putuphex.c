/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghuzlan <mghuzlan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:09:04 by mghuzlan          #+#    #+#             */
/*   Updated: 2026/10/23 11:19:03 by mghuzlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuphex(unsigned int x)
{
	char	*digits;
	char	re[11];
	int		i;
	int		co;

	i = 0;
	co = 0;
	digits = "0123456789ABCDEF";
	if (x == 0)
		return (write(1, "0", 1));
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
