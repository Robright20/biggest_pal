/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 20:03:56 by fokrober          #+#    #+#             */
/*   Updated: 2019/12/15 20:22:18 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int		cmp_rev(char *s1, char *s2, int	n)
{
	char	*start;

	start = s2;
	if (n < 1 || !*s1 || ft_strlen(s2) <= n)
		return (-1);
	s2 += n;
	while (n-- && s2 != start)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2--;
	}
	return (*s1 - *s2);
}

int		check(char *s, int len)
{
	int		mid;
	int		cmp;
	int		inc;

	mid = len / 2;
	inc = 0;
	if (len % 2)
		inc = 1;
	cmp = cmp_rev(s, &s[mid + inc], mid - 1);
	return (!cmp);
}

void	run(char *s)
{
	int		len;
	int		ret;
	int		k;
	char	*start;

	len = ft_strlen(s);
	k = len;
	start = s;
	while (!(ret = check(s, k)) && k > 3)
	{
		if (s != start)
			s--;
		else
		{
			k--;
			s += len - k;
		}
	}
	(void)(ret && write(1, s, k));
	return ;
}

int		main(int ac, char **av)
{
	if (ac == 2)
		run(av[1]);
	write(1, "\n", 1);
	return (0);
}
