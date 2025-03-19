/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 15:50:26 by luda-cun          #+#    #+#             */
/*   Updated: 2024-11-21 15:50:26 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	if (j == 0)
		return (ft_strdup(""));
	j--;
	while (ft_strchr(set, s1[i]) && i <= j)
		i++;
	while (ft_strchr(set, s1[j]) && j > i)
		j--;
	if (i > j)
		return (ft_strdup(""));
	ptr = (char *)malloc(sizeof(char) * (j - i + 2));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[i], j - i + 2);
	return (ptr);
}
