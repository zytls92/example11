/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcho <zytls92@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:38:49 by mcho              #+#    #+#             */
/*   Updated: 2020/07/13 21:01:21 by mcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_print(int nb)
{
	int		num[10];
	int		pone;
	int		idx;

	idx = 0;
	while (nb / 10 != 0)
	{
		pone = nb % 10;
		if (pone < 0)
			pone *= -1;
		num[idx++] = pone + 48;
		nb /= 10;
	}
	if (nb < 0)
		nb *= -1;
	num[idx] = nb + 48;
	while (idx >= 0)
		write(1, &num[idx--], 1);
}

void		ft_putnbr(int nb)
{
	char	mi;

	mi = '-';
	if (nb < 0)
	{
		write(1, &mi, 1);
		ft_print(nb);
	}
	else
		ft_print(nb);
}
