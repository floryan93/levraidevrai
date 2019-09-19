/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:49:54 by fdias             #+#    #+#             */
/*   Updated: 2019/09/01 00:23:16 by fdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char boulette;

	boulette = 'z';
	while (boulette >= 97)
	{
		write(1, &boulette, 1);
		boulette--;
	}
}
