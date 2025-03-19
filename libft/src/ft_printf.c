/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:30:14 by luda-cun          #+#    #+#             */
/*   Updated: 2024/12/12 16:38:30 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_arg(const char format, va_list args)
{
	if (format == 'c')
		return (val_cara(va_arg(args, int)));
	if (format == 's')
		return (val_str(va_arg(args, char *)));
	if (format == 'd')
		return (val_int(va_arg(args, int)));
	if (format == 'i')
		return (val_int(va_arg(args, int)));
	if (format == 'u')
		return (val_unsi_int(va_arg(args, unsigned int)));
	if (format == 'x')
		return (val_hexa_min(va_arg(args, unsigned int)));
	if (format == 'X')
		return (val_hexa_maj(va_arg(args, unsigned int)));
	if (format == 'p')
		return (val_point(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	args;

	va_start(args, format);
	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX", *format))
				ret += ft_conv_arg(*format, args);
			else if (*format == '%')
				ret += val_cara('%');
		}
		else
			ret += val_cara(*format);
		format++;
	}
	va_end(args);
	return (ret);
}
