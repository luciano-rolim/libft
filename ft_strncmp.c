/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeneghe <lmeneghe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:58:27 by lmeneghe          #+#    #+#             */
/*   Updated: 2024/04/18 14:46:47 by lmeneghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		result = ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (result != 0)
			return (result);
		i++;
	}
	return (result);
}
