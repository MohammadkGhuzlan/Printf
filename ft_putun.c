/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghuzlan <mghuzlan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:06:14 by mghuzlan          #+#    #+#             */
/*   Updated: 2026/10/23 13:18:27 by mghuzlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putun(unsigned int nb)
{
	char			xx[11];
	unsigned int	x;
	int				i;
	int				co;

	i = 0;
	co = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	while (nb > 0)
	{
		x = nb % 10;
		nb = nb / 10;
		xx[i++] = x + 48;
	}
	while (i > 0)
		co += write(1, &xx[--i], 1);
	return (co);
}
