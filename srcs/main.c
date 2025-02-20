/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivallee <wivallee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:34:05 by wivallee          #+#    #+#             */
/*   Updated: 2025/02/20 17:25:10 by wivallee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arc, char **arv)
{
	t_holder	holder;

	if (arc == 1)
		return (1);
	holder.a = NULL;
	holder.b = NULL;
	get_numbers(arv, arc, &holder);
	rank_list(&(holder).a);
	window_sort(&holder);
	sort_small(&holder);
	refill_a(&holder);
	ft_stackclear(&(holder).a);
	return (0);
}

GERER LES DUPS UNE FOIS EN CHIFFRE ET PAS AVANT
+ FAIRE UN SCRIPT POUR TESTER LE MAX DE COMBINAISONS
VOIR POUR FAIRE UN MAKEFILE + CLEAN (POUR LE MAIN ET LE MAIN BONUS LE CHANGEMENTS DOIVENT ETRES PRIS EN COMPTE)
