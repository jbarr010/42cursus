/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:55:42 by jbarredo          #+#    #+#             */
/*   Updated: 2021/11/15 20:02:12 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_defvalue(char *format, int i, va_list arg)
{
	int	count;

	count = 0;
	if (format[i + 1] == 'c')
		count = ft_printchar(va_arg(arg, int));
	if (format[i + 1] == 's')
		count = ft_str(va_arg(arg, char *));
	if (format[i + 1] == 'd')
		count = ft_printnumbers(va_arg(arg, int));
	if (format[i + 1] == 'p')
		count = ft_str("0x") + ft_hex(va_arg(arg, unsigned long int), 'x');
	if (format[i + 1] == 'i')
		count = ft_printnumbers(va_arg(arg, int));
	if (format[i + 1] == 'u')
		count = ft_printunumber(va_arg(arg, unsigned int));
	if (format[i + 1] == 'x')
		count = ft_hex(va_arg(arg, unsigned int), 'x');
	if (format[i + 1] == 'X')
		count = ft_hex(va_arg(arg, unsigned int), 'X');
	if (format[i + 1] == '%')
		count = ft_printchar('%');
	return (count);
}

int	ft_count_format(const char *format, va_list arg)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	count = 0;
	str = ft_strdup(format);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		else
		{
			count += ft_defvalue(str, i, arg);
			i++;
		}
		i++;
	}
	free (str);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;

	if (!format)
		return (0);
	len = 0;
	va_start (arg, format);
	len = ft_count_format(format, arg);
	va_end(arg);
	return (len);
}
