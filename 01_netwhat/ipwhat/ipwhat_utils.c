/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipwhat_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 23:14:28 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/13 23:18:05 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ipwhat.h"

static int	is_space(char str)
{
	if (str == ' ' || (str >= 9 && str <= 13))
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	unsigned long long	absol;
	int					minus;

	minus = 1;
	absol = 0;
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
		absol = absol * 10 + (*str++ - '0');
	if (absol >= 9223372036854775807 && minus == 1)
		return (-1);
	else if (absol >= 9223372036854775807 && minus == -1)
		return (0);
	return (minus * absol);
}
