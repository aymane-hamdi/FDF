/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:08:35 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/13 12:23:32 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					signe;
	unsigned long long	result;

	signe = 1;
	result = 0;
	if (!str)
		return (0);
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str && ft_isdigit(*str) == 1)
	{
		result = result * 10 + (*str - '0');
		if ((result > 9223372036854775807) && signe == 1)
			return (-1);
		if ((result > 9223372036854775807) && signe == -1)
			return (0);
		str++;
	}
	return ((int)result * signe);
}
