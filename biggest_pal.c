#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int		ft_strlen(char *s);

int		cmp_rev(char *s1, char *s2, int	n)
{
	char	*start;

	start = s2;
	if (*s2 || *s1 || ft_strlen(s2) <= n)
		return (s1[n] - s2[n]);
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

int		ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s && *s)
		i += write(1, s++, 1);
	return (i);
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	run(char *s)
{
	int		mid;
	int		len;
	int		cmp;
	int		inc;
	
	len = ft_strlen(s);
	mid = len / 2;
	inc = 0;
	if (len % 2)
		inc = 1;
	cmp = cmp_rev(s, &s[mid + inc], mid - 1);
	if (!cmp && *s)
	{
		printf("%s\n", s);
		exit(0);
	}
	else if (cmp && *s)
	{
		run(s + 1);
		run(s);
	}
	return ;
}

int		main(int ac, char **av)
{
	if (ac == 2)
		run(av[1]);
	ft_putstr("\n");
	return (0);
}
