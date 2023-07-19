/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:43:44 by ohortal-          #+#    #+#             */
/*   Updated: 2023/05/08 10:53:35 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_ptr(unsigned long long int nbr, int index)
{
	char	*base[2];
	int		i;
	int		flag;

	base[0] = "0123456789abcdef";
	base[1] = "0123456789ABCDEF";
	i = 0;
	if (!(nbr / 16))
	{
		if (write(1, &base[index][nbr % 16], 1) < 0)
			return (-1);
		return (1);
	}
	flag = ft_put_ptr(nbr / 16, index);
	if (flag < 0 || write(1, &base[index][nbr % 16], 1) < 0)
		return (-1);
	return (i + 1 + flag);
}

int	ft_print_hex(unsigned int nbr, char c)
{
	if (c == 'x')
		return (ft_put_ptr(nbr, 0));
	return (ft_put_ptr(nbr, 1));
}

int	ft_print_ptr(void *ptr)
{
	int	i;

	i = write(1, "0x", 2);
	if (i < 0)
		return (-1);
	return (i + ft_put_ptr((unsigned long long int)ptr, 0));
}

int	ft_printf_codif(char c, va_list args)
{
	int	ch;

	if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'c')
	{
		ch = va_arg(args, int);
		return (write(1, &ch, 1));
	}
	else if (c == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_unsigned_int(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), c));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i[2];
	int		count;
	va_list	argv;

	va_start(argv, str);
	i[0] = -1;
	i[1] = 0;
	while (str[++i[0]])
	{
		if (str[i[0]] == '%')
		{
			count = ft_printf_codif(str[++i[0]], argv);
			if (count < 0)
				return (-1);
			i[1] += count;
		}
		else
		{
			if (write(1, &str[i[0]], 1) <= 0)
				return (-1);
			i[1]++;
		}
	}
	va_end(argv);
	return (i[1]);
}
