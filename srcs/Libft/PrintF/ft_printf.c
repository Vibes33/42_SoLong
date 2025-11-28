/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:00:00 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/28 16:00:00 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_putchar_count(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putstr_count(char *str)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		count += ft_putchar_count(*str);
		str++;
	}
	return (count);
}

static int	ft_putnbr_count(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr_count("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		count += ft_putchar_count('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_count(n / 10);
	count += ft_putchar_count((n % 10) + '0');
	return (count);
}

static int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	count += ft_putchar_count((n % 10) + '0');
	return (count);
}

static int	ft_puthex(unsigned long n, char format)
{
	int		count;
	char	*hex;

	count = 0;
	if (format == 'x' || format == 'p')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(n / 16, format);
	count += ft_putchar_count(hex[n % 16]);
	return (count);
}

static int	ft_putptr(unsigned long ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr_count("(nil)"));
	count = ft_putstr_count("0x");
	count += ft_puthex(ptr, 'p');
	return (count);
}

static int	handle_format(va_list args, char format)
{
	if (format == 'c')
		return (ft_putchar_count(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr_count(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_count(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_putchar_count('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_format(args, format[i]);
		}
		else
			count += ft_putchar_count(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
