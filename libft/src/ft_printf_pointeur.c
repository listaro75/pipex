/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointeur.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-13 15:11:52 by luda-cun          #+#    #+#             */
/*   Updated: 2024-12-13 15:11:52 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(unsigned int hexa)
{
	if (hexa < 10)
		ft_putchar_fd('0' + hexa, 1);
	else
		ft_putchar_fd('a' + hexa - 10, 1);
}

int	val_point(void *p)
{
	unsigned long	addr;
	int				i;
	char			hexa[16];
	int				ret;

	if (!p)
		return (val_str("(nil)"));
	addr = (unsigned long)p;
	i = 0;
	while (addr > 0)
	{
		hexa[i] = addr % 16;
		addr /= 16;
		i++;
	}
	i += val_str("0x");
	ret = i;
	i = i - 3;
	while (i >= 0)
	{
		ft_print_ptr(hexa[i]);
		i--;
	}
	return (ret);
}
