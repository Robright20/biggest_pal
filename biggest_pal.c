/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:14:45 by fokrober          #+#    #+#             */
/*   Updated: 2019/12/15 21:51:25 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	int		len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

int		ft_cmp(char *start, char *end, int n)
{
	while (n--)
	{
		if (*start != *end)
			return (0);
		start++;
		end--;
	}
	return (*start == *end); 
}

void	ft_exec(char *s)
{
	int		len;
	int		k;
	char	*start;
	int		cmp;

	len = ft_strlen(s);
	k = len;
	start = s;
	while (!(cmp = ft_cmp(s, &s[k - 1], k/2)) && k > 3)
	{
		if (s != start)
			s--;
		else
		{
			k--;
			s += len - k;
		}
	}
	(void)(cmp && write(1, s, k));
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_exec(av[1]);
	write(1, "\n", 1);
	return (0);
}
