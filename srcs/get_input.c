/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivallee <wivallee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:24:45 by wivallee          #+#    #+#             */
/*   Updated: 2025/02/20 16:33:18 by wivallee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_list(char *list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		while (list[i] == ' ')
			i++;
		if (list[i] == '-' || list[i] == '+')
			i++;
		if (list[i] && !ft_isdigit(list[i]))
			return (0);
		while (ft_isdigit(list[i]))
			i++;
		if (list[i] && list[i] != ' ')
			return (0);
	}
	return (1);
}

char	*join_with_space(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*cat;

	cat = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (cat == NULL)
		return (NULL);
	ft_bzero(cat, ft_strlen(s1) + ft_strlen(s2) + 2);
	i = 0;
	while (s1 && s1[i])
	{
		cat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		cat[i + j] = s2[j];
		j++;
	}
	cat[i + j] = ' ';
	if (s1)
		free(s1);
	return (cat);
}

char	*get_list(char **arv, int arc)
{
	int			i;
	char		*complete_list;

	i = 1;
	complete_list = NULL;
	while (i < arc)
	{
		if (!valid_list(arv[i]))
		{
			free(complete_list);
			ft_printf(2, "Error\n");
			exit (EXIT_FAILURE);
		}
		complete_list = join_with_space(complete_list, arv[i]);
		if (complete_list == NULL)
		{
			ft_printf(2, "Error\n");
			exit (EXIT_FAILURE);
		}

		i++;
	}
	return (complete_list);
}

void	get_numbers(char **arv, int arc, t_holder *holder)
{
	int			i;
	char		*complete_list;
	char		**nb_tab;
	long long	tmp;

	complete_list = get_list(arv, arc);
	nb_tab = ft_split(complete_list, ' ');
	free(complete_list);
	i = 0;
	while (nb_tab[i])
	{
		tmp = ft_atoll(nb_tab[i]);
		if ((tmp < INT_MIN
				|| tmp > INT_MAX) || !check_dups(nb_tab, i))
		{
			ft_printf(2, "Error\n");
			ft_clear_tab(nb_tab);
			ft_stackclear(&(holder)->a);
			exit (EXIT_FAILURE);
		}
		ft_stackadd_back(&(holder)->a, ft_new_stack(ft_atoi(nb_tab[i])));
		i++;
	}
	ft_clear_tab(nb_tab);
}
