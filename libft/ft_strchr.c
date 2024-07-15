/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:25:58 by ykai-yua          #+#    #+#             */
/*   Updated: 2024/02/25 03:33:03 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((*s != (char)c) && *s)
		s++;
	if (*s)
		return ((char *)s);
	else if (!*s && ((char)c) == 0)
		return ((char *)s);
	else
		return (NULL);
}
