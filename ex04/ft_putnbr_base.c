/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcho <zytls92@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:20:08 by mcho              #+#    #+#             */
/*   Updated: 2020/07/14 05:07:14 by mcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			dupcheck(char ch, char exist[])
{
	int idx;

	idx = 0;
	while (*(exist + idx) != '\0')
	{
		if (ch == *(exist + idx))
			return (0);
		idx++;
	}
	return (1);
}

int			check(char *base)
{
	char	exist[100];
	int		idx;
	char	ch;
	int		dup;

	idx = 0;
	dup = 2;
	while (*(base + idx) != '\0')
	{
		ch = *(base + idx);
		if (ch == '+' || ch == '-')
			return (0);
		if (idx != 0)
			dup = dupcheck(ch, exist);
		if (dup < 1)
			return (0);
		exist[idx] = ch;
		idx++;
	}
	if (idx < 2)
		return (0);
	return (1);
}

int			find_size(char *base)
{
	int		idx;

	idx = 0;
	while (*(base + idx) != '\0')
		idx++;
	return (idx);
}

void		ft_print(int nbr, char *base, int size)
{
	char	num[100];
	int		idx;
	int		pone;

	idx = 0;
	while (nbr / size != 0)
	{
		pone = nbr % size;
		if (nbr < 0)
			pone *= -1;
		num[idx++] = base[pone];
		nbr /= size;
	}
	if (nbr < 0)
		nbr *= -1;
	num[idx] = base[nbr];
	while (idx >= 0)
		write(1, &num[idx--], 1);
}

void		ft_putnbr_base(int nbr, char *base)
{
	int		size;
	char	mi;

	mi = '-';
	size = find_size(base);
	if (check(base) == 0)
		return ;
	else
	{
		if (nbr < 0)
			write(1, &mi, 1);
		ft_print(nbr, base, size);
	}
}
