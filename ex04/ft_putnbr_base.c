/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcho <zytls92@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:20:08 by mcho              #+#    #+#             */
/*   Updated: 2020/07/13 23:01:10 by mcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int			dupcheck(char ch, char *exist)
{
	printf("dupcheck start!!\n");
	int idx;

	idx = 0;
	while (*(exist + idx) != '\0')
	{
		if(ch == *(exist +idx))
			return (0);
		idx++;
	}
	return (1);
}
int			check(char *base)
{
	char	*exist;
	int		idx;
	char	ch;
	int		dup;

	idx = 0;
	dup = 2;
	while (*(base + idx) != '\0')
	{
		ch = *(base + idx);
		printf("ch is %c!! \n",ch);
		if (ch == '+' || ch == '-')
			return (dup);
		if (idx != 0)
			dup = dupcheck(ch, exist);
		if (dup < 1)
			return (dup);
		printf("why?? \n");
		exist[idx] = ch;
		printf("not priniting!!\n");
		idx++;
	}
	if (idx < 2)
		return (dup);
	return (dup);
}

int main()
{
	char base[10] = "abcda";
	int res;

	res = check(&base[0]);
}

/*void		ft_putnbr_base(int nbr, char *base)
{

}*/
