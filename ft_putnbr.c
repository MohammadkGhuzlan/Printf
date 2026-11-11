/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghuzlan <mghuzlan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:08:45 by mghuzlan          #+#    #+#             */
/*   Updated: 2026/10/23 11:30:20 by mghuzlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	low(int *nb, int *co)
{
	*co += write(1, "-2147483648", 11);
	*nb = 0;
}

int	ft_putnbr(int nb)
{
	char	xx[11];
	int		x;
	int		i;
	int		co;

	i = 0;
	co = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb == -2147483648)
		low(&nb, &co);
	if (nb < 0)
	{
		nb = nb * -1;
		co += write(1, "-", 1);
	}
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
