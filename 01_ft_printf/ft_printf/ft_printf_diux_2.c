/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diux_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:02:03 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/20 19:19:44 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

int			print_if_minus(char *nb, int wtp, int ptp)
{
	int output;

	output = 0;
	while (ptp-- > 0)
	{
		output++;
		write(1, "0", 1);
	}
	output += ft_putstr(nb);
	while (wtp-- > 0)
	{
		output++;
		write(1, " ", 1);
	}
	return (output);
}

int			print_if_zero(char *nb, int wtp)
{
	int output;

	output = 0;
	while (wtp-- > 0)
	{
		output++;
		write(1, "0", 1);
	}
	output += ft_putstr(nb);
	return (output);
}

int			print_neg_if_minus(char *nb, int wtp, int ptp)
{
	int output;

	output = 0;
	write(1, "-", 1);
	wtp--;
	while (ptp-- > 0)
	{
		output++;
		write(1, "0", 1);
	}
	output += (ft_putstr(nb) + 1);
	while (wtp-- > 0)
	{
		output++;
		write(1, " ", 1);
	}
	return (output);
}

int			print_neg_if_zero(char *nb, int wtp)
{
	int output;

	output = 1;
	write(1, "-", 1);
	wtp--;
	while (wtp-- > 0)
	{
		output++;
		write(1, "0", 1);
	}
	output += ft_putstr(nb);
	return (output);
}
