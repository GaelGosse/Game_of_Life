/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:54:27 by gael              #+#    #+#             */
/*   Updated: 2025/07/02 17:00:38 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_of_life.h"

extern t_app	app;

int	num_len(long int nbr)
{
	long int	len;

	len = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char		*str;
	long int	len;
	long int	sign;
	long int	nb;

	sign = 0;
	len = num_len(nbr);
	nb = nbr;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
		sign = 1;
	}
	str[len] = '\0';
	while (--len >= sign)
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}

int	abs(int nbr)
{
	if (nbr < 0)
		return nbr * -1;
	return nbr;
}
