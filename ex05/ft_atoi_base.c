/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcho <zytls92@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 02:04:35 by mcho              #+#    #+#             */
/*   Updated: 2020/07/14 05:06:56 by mcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			check(char *base)
{
	int		idx;
	int		idx1;

	idx = 0;
	while (*(base + idx) != '\0')
	{
		if (base[idx] == '+' || base[idx] == '-'
				|| base[idx] == ' ' || base[idx] == '\n'
					|| base[idx] == '\t' || base[idx] == '\r'
						|| base[idx] == '\v' || base[idx] == '\f')
			return (0);
		idx++;
		idx1 = idx + 1;
		while (*(base + idx1) != '\0')
		{
			if (base[idx] == base[idx1])
				return (0);
			idx1++;
		}
	}
	if (idx < 2)
		return (0);
	return (1);
}

int			get_size(char *base)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int			check_pm(int idx, char *c, int *cnt)
{
	while (c[idx] == '+' || c[idx] == '-')
	{
		if (c[idx] == '-')
			(*cnt)++;
		idx++;
	}
	return (idx);
}

void		check_num(int idx, char *c, char *base, int *res)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (*(base + i) != '\0')
	{
		if (c[idx] == base[i])
		{
			*res = *res * get_size(base) + i;
			flag = 1;
		}
		i++;
	}
	if (flag == 1)
		check_num(idx + 1, c, base, res);
}

int			ft_atoi_base(char *str, char *base)
{
	int res;
	int	cnt;
	int	num;
	int	idx;
	int size;

	idx = 0;
	size = 0;
	cnt = 0;
	res = 0;
	if (check(base) == 0)
		return (0);
	while (str[idx] == '\t' || str[idx] == '\n'
			|| str[idx] == ' ' || str[idx] == '\v'
			|| str[idx] == '\f' || str[idx] == '\r')
		idx++;
	check_num(check_pm(idx, str, &cnt), str, base, &res);
	if (cnt % 2 == 1)
		res *= -1;
	return (res);
}
