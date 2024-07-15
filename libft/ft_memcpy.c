/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 23:52:10 by ykai-yua          #+#    #+#             */
/*   Updated: 2024/02/28 22:04:04 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;

	if (src == NULL && dest == NULL)
		return (NULL);
	i = 0;
	while (n)
	{
		*((unsigned char *)dest + i++) = *(unsigned char *)src++;
		n--;
	}
	return (dest);
}
