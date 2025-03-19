/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:01:09 by luda-cun          #+#    #+#             */
/*   Updated: 2024/12/12 16:31:23 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsi_fd(unsigned int n, int fd)
{
	if (n > 9)
		ft_putnbr_unsi_fd(n / 10, fd);
	if (n <= 9)
	{
		ft_putchar_fd(n + 48, fd);
		return ;
	}
	ft_putchar_fd((n % 10 + 48), fd);
}

int	val_int(int nbr)
{
	long int	ret;
	int			i;

	ret = nbr;
	i = 0;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		i++;
	}
	if (nbr == 0)
		i = 1;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	ft_putnbr_fd(ret, 1);
	if (ret == -2147483648)
		i = 11;
	return (i);
}

int	val_str(char *s)
{
	int	i;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	i = ft_strlen(s);
	return (i);
}

int	val_cara(int c)
{
	ft_putchar_fd((int)c, 1);
	return (1);
}

int	val_unsi_int(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (val_cara('0'));
	ft_putnbr_unsi_fd(nbr, 1);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}
