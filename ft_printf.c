/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:53:59 by nnemeth           #+#    #+#             */
/*   Updated: 2021/12/18 13:42:15 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printchar(int c)
{
	return(write(1, &c, 1));
}

static	int	ft_flag(const char *flag, va_list args)
{
	int i;
	int print;
	
	i = 0;
	print = 0;
	if (flag[i] == 'c')
		print = print + ft_printchar(va_arg(args, int));
	if (flag[i] == 's')
		print = print + ft_putstr(va_arg(args, char *));
	return(print);
}

int	ft_printf(const char *flag, ...)
{
	int i;
	int	print;
	
	i = 0;
	print = 0;
	va_list	args;
	va_start(args, flag);
	while (*flag != '\0')
	{
		if(*flag == '%')
		{
			print = print + ft_flag(&flag[i + 1], args);
			flag++;
		}
		else 
			print = (print + *ft_printchar(flag[i]));
		flag++;	
	}
	va_end(args);
	return(print);
}