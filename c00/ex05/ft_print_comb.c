/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:59:37 by fdias             #+#    #+#             */
/*   Updated: 2019/08/31 23:12:42 by fdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_suite(int a, int b, int c)
{
	if (!(a == b | b == c | a == c))
	{
		if (a < b && b < c)
		{
			ft_putchar(a);
			ft_putchar(b);
			ft_putchar(c);
			if (a != '7')
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
}

void	ft_print_comb(void)
{
	int a;
	int b;
	int c;

	a = '0';
	b = '0';
	c = '0';
	while (a <= '9')
	{
		while (b <= '9')
		{
			while (c <= '9')
			{
				ft_suite(a, b, c);
				c++;
			}
			b++;
			c = '0';
		}
		a++;
		b = '0';
	}
}
