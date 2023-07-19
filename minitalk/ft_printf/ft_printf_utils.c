/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:43:30 by ohortal-          #+#    #+#             */
/*   Updated: 2023/05/08 11:14:32 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_int(unsigned int nbr)
{
	unsigned int	rest;
	int				i;
	int				flag;

	i = 0;
	rest = (nbr % 10) + '0';
	if (!(nbr / 10))
		return (write(1, &rest, 1));
	flag = ft_print_unsigned_int((nbr / 10));
	if (flag < 0)
		return (-1);
	else
	{
		i += flag;
		if (write(1, &rest, 1) < 0)
			return (-1);
		return (++i);
	}
}

int	ft_print_string(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	if (*str == '\0')
		return (0);
	while (str[i])
	{
		if (write(1, &str[i], 1) < 0)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_print_nbr(int nb)
{
	unsigned int	b;
	int				i;
	int				flag;

	i = 0;
	b = nb;
	if (nb < 0)
	{
		i += write (1, "-", 1);
		b = -nb;
	}
	if (i < 0)
		return (-1);
	if ((b / 10) == 0)
	{
		if (ft_put_char((char)((b % 10) + 48)) < 0)
			return (-1);
		return (++i);
	}
	flag = ft_print_nbr(b / 10);
	if (flag < 0 || ft_put_char(((char)((b % 10) + 48))) < 0)
		return (-1);
	return (i + 1 + flag);
}

int	ft_put_char(char c)
{
	return (write(1, &c, 1));
}
