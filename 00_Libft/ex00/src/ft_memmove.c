/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:05:30 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 14:50:45 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	void				*dst_backup;
	void				*src_backup;
	void				buf[count];
	unsigned long long	i;

	src_backup = src;
	i = 0;
	if (!dst || !src)
		return (0);
	while (i < n)
		buf[i++] = *src_backup++;
	i = 0;
	while (i < n)
		*dst++ = buf[i++];
	return (dst_backup);
}
