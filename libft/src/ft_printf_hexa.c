/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:51:54 by luda-cun          #+#    #+#             */
/*   Updated: 2024/12/12 16:28:24 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_revers(char *str, int i)
{
	int	j;

	j = i -1;
	while (j >= 0)
	{
		ft_putchar_fd(str[j], 1);
		j--;
	}
}

int	val_hexa_min(unsigned int x)
{
	char			*list_hexa;
	char			stack_hexa[32];
	unsigned int	hexa;
	int				i;

	list_hexa = "0123456789abcdef";
	hexa = x;
	i = 0;
	if (x == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	while (hexa > 0)
	{
		stack_hexa[i] = list_hexa[hexa % 16];
		hexa = hexa / 16;
		i++;
	}
	ft_print_revers(stack_hexa, i);
	return (i);
}

int	val_hexa_maj(unsigned int x)
{
	char			*list_hexa;
	char			stack_hexa[32];
	unsigned int	hexa;
	int				i;

	list_hexa = "0123456789ABCDEF";
	hexa = x;
	i = 0;
	if (x == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	while (hexa > 0)
	{
		stack_hexa[i] = list_hexa[hexa % 16];
		hexa = hexa / 16;
		i++;
	}
	ft_print_revers(stack_hexa, i);
	return (i);
}
