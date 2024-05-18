/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:08:35 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/18 10:30:58 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	error_at(void)
{
	write(2, "z is too long\n", 6);
	exit(1);
}

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
		str++;
	}
	if ((result > 2147483647) && signe == 1)
		error_at();
	if ((result > 2147483648) && signe == -1)
		error_at();
	return ((int)result * signe);
}
