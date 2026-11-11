/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghuzlan <mghuzlan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:04:27 by mghuzlan          #+#    #+#             */
/*   Updated: 2026/10/23 11:47:51 by mghuzlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	co;

	co = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str != '\0')
		co += write(1, str++, 1);
	return (co);
}
