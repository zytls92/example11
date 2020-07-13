/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcho <zytls92@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:01:47 by mcho              #+#    #+#             */
/*   Updated: 2020/07/13 22:15:46 by mcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		check_isspace(char *c)
{
	int idx;

	idx = 0;
	while (c[idx] == '\t' || c[idx] == '\n'
			|| c[idx] == ' ' || c[idx] == '\v'
			|| c[idx] == '\f' || c[idx] == '\r')
		idx++;
	return (idx);
}

int		check_pm(int idx, char *c, int *cnt)
{
	while (c[idx] == '+' || c[idx] == '-')
	{
		if (c[idx] == '-')
			(*cnt)++;
		idx++;
	}
	return (idx);
}

int		check_num(int idx, char *c)
{
	int	res;

	res = 0;
	while (c[idx] >= '0' && c[idx] <= '9')
	{
		res = res * 10 + (c[idx] - 48);
		idx++;
	}
	return (res);
}

int		ft_atoi(char *str)
{
	int cnt;
	int num;

	cnt = 0;
	num = check_num(check_pm(check_isspace(str), str, &cnt), str);
	if (cnt % 2 == 1)
		num *= -1;
	return (num);
}
