/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:18:12 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/22 03:23:08 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	int a;
	int i;

	a = 1;
	i = 0;
	while (i < 4)
	{
		printf("%d\n", a);
		a <<= 1;
		a |= 1;
		i++;
	}
}
