/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:21:30 by ykai-yua          #+#    #+#             */
/*   Updated: 2024/03/07 08:42:54 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	hadle_neg(char *ptr, int *n)
{
	if (*n < 0)
	{
		ptr[0] = '-';
		*n = -*n;
	}
	else if (*n == 0)
		ptr[0] = '0';
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;

	len = ft_len(n);
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len--] = '\0';
	if (n == -2147483648)
	{
		ft_strlcpy(ptr, "-2147483648", len + 2);
		return (ptr);
	}
	hadle_neg(ptr, &n);
	while (n > 0)
	{
		ptr[len--] = (n % 10) + 48;
		n /= 10;
	}
	return (ptr);
}
