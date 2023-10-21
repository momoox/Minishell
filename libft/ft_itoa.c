/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <olivierliove@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:15:08 by momox             #+#    #+#             */
/*   Updated: 2023/10/21 22:26:23 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

long int	secu(long int nb, char **str)
{
	if (nb < 0)
	{
		(*str)[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
	{
		(*str)[0] = '0';
		(*str)[1] = '\0';
		return (nb);
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;

	nb = n;
	i = len(nb);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	nb = secu(nb, &str);
	str[i] = '\0';
	i--;
	while (nb)
	{
		str[i] = '0' + (nb % 10);
		nb = nb / 10;
		i--;
	}
	return (str);
}