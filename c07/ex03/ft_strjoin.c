/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdias <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 06:30:25 by fdias             #+#    #+#             */
/*   Updated: 2019/09/16 13:32:44 by fdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(dest);
	while (src[i])
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}

int		ft_calcul(int size, char **strs, char *sep)
{
	int	i;
	int	cmpt;
	int	len;

	i = 0;
	cmpt = 0;
	len = ft_strlen(sep);
	while (i < size)
	{
		cmpt += ft_strlen(strs[i]);
		if (i < size - 1)
			cmpt += len;
		i++;
	}
	return (cmpt);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		result;
	char	*str;

	result = ft_calcul(size, strs, sep);
	if (size < 1)
	{
		if (!(str = (char*)malloc(sizeof(char) * 1)))
			str[0] = '\0';
		return (str);
	}
	if (!(str = (char*)malloc(sizeof(char) * result + 1)))
		return (0);
	str[0] = '\0';
	i = 0;
	while (i < size)
	{
		str = ft_strcat(str, strs[i]);
		if (i < size - 1)
			str = ft_strcat(str, sep);
		i++;
	}
	return (str);
}
