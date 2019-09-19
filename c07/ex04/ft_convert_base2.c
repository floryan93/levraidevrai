/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:05:42 by fdias             #+#    #+#             */
/*   Updated: 2019/09/19 11:13:55 by fdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_base(char *base);
int		ft_atoi_base(char *str, char *base);
char	*ft_malloc(int nbr, char *base);
char	*ft_conv(long nbr, char *base, char *nb, int sbase);
int		ft_count(int sbase, long nb);

int		ft_count(int sbase, long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb = nb / sbase;
		i++;
	}
	return (i);
}

char	*ft_conv(long nbr, char *base, char *nb, int sbase)
{
	int	i;

	i = ft_count(sbase, nbr);
	if (nbr < 0)
	{
		nbr = -nbr;
		nb[0] = '-';
		i++;
	}
	if (nbr == 0)
	{
		nb[0] = base[nbr % sbase];
		nbr = nbr / sbase;
	}
	else
	{
		nb[i] = '\0';
		while (--i > 0 || (i == 0 && nb[0] != '-'))
		{
			nb[i] = base[nbr % sbase];
			nbr = nbr / sbase;
		}
	}
	return (nb);
}
