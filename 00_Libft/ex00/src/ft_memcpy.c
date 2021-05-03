/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:53:40 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 15:15:18 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t num)
{
	unsigned char *restrict dst_backup;
	unsigned char *restrict src_backup;

	dst_backup = (unsigned char *restrict)dst;
	src_backup = (unsigned char *restrict)src;
	while (num)
	{
		*dst_backup++ = *src_backup++;
		num--;
	}
	return (dst_backup);
}
