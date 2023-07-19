/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:31:26 by ohortal-          #+#    #+#             */
/*   Updated: 2023/04/20 11:13:22 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

int			ft_put_char(char c);
int			ft_print_nbr(int nbr);
int			ft_print_ptr(void *ptr);
int			ft_print_string(char *str);
int			ft_printf(const char *str, ...);
int			ft_print_codif(char c, va_list args);
int			ft_print_hex(unsigned int nbr, char c);
int			ft_print_unsigned_int(unsigned int nbr);

#endif
