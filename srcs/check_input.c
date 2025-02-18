#include "push_swap.h"

long long	ft_atoll(char *nptr)
{
	int			i;
	long long	sign;
	long long	total;

	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	sign = 1;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		i++;
		sign = -1;
	}
	total = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		total = total * 10;
		total = total + nptr[i] - '0';
		i++;
	}
	return (total * sign);
}

int	check_only_digits(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_dups(char **arv, int index)
{
	int		len;
	char	*tmp;

	len = ft_strlen(arv[index]) + 1;
	tmp = arv[index];
	index++;
	while (arv[index])
	{
		if (ft_strncmp(tmp, arv[index], len) == 0)
			return (0);
		index++;
	}
	return (1);
}

int	check_params(char **arv)
{
	int			i;
	long long	holder;

	i = 1;
	while (arv[i])
	{
		holder = ft_atoll(arv[i]);
		if (!check_only_digits(arv[i]) || (holder < INT_MIN || holder > INT_MAX) || !check_dups(arv, i))
		{
			ft_printf(2, "Error\n");
			exit (EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}
