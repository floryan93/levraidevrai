/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 09:03:36 by fdias             #+#    #+#             */
/*   Updated: 2019/09/19 13:21:56 by fdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_base(char *base);
int		ft_atoi_base(char *str, char *base);
char	*ft_malloc(int nbr, char *base);
char	*ft_conv(long nbr, char *base, char *nb, int sbase);
int		ft_count(int sbase, long nb);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec;
	int		i;
	char	*conv;

	i = 0;
	if (!(check_base(base_from) && check_base(base_to)))
		return (NULL);
	dec = ft_atoi_base(nbr, base_from);
	conv = ft_malloc(dec, base_to);
	return (conv);
}

int		check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '\n' || base[i] == '\r' || base[i] == '\f' || base[i]
				== '\v' || base[i] <= ' ' || base[i] > '~' || base[i] == '+'
				|| base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	j;

	sign = 1;
	result = 0;
	j = -1;
	while (*str == '\n' || *str == '\r' || *str == '\f'
			|| *str == '\v' || *str == '\t' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (base[++j])
		if (*str == base[j] && check_base(base))
		{
			result = result * check_base(base) + j;
			j = -1;
			str++;
		}
	return (result * sign);
}

char	*ft_malloc(int nbr, char *base)
{
	int		sbase;
	int		i;
	long	n;
	char	*nb;

	n = nbr;
	sbase = check_base(base);
	i = ft_count(sbase, n);
	if (n < 0)
	{
		if (!(nb = (char*)malloc(sizeof(char) * i + 2)))
			return (0);
	}
	else
	{
		if (!(nb = (char*)malloc(sizeof(char) * i + 1)))
			return (0);
	}
	nb = ft_conv(n, base, nb, sbase);
	return (nb);
}
