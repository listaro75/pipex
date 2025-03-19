/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:41:54 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/10 12:16:48 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		val_int(int nbr);
int		val_cara(int c);
int		val_str(char *s);
int		val_unsi_int(unsigned int nbr);
int		val_hexa_min(unsigned int x);
void	ft_print_revers(char *str, int i);
int		val_hexa_maj(unsigned int x);
int		val_point(void *p);

#endif
