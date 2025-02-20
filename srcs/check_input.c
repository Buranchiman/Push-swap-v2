/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivallee <wivallee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:33:26 by wivallee          #+#    #+#             */
/*   Updated: 2025/02/20 16:40:32 by wivallee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
