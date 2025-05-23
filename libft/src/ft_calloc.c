/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:26:32 by luda-cun          #+#    #+#             */
/*   Updated: 2024/11/19 22:13:37 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	bytes;
	void	*new;

	bytes = size * count;
	if (size != 0 && ((bytes / size) != count))
		return (NULL);
	new = (void *)malloc(count * size);
	if (!new)
		return (NULL);
	ft_bzero(new, size * count);
	return (new);
}
