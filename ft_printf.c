/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaccaud <spaccaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:19:06 by spaccaud          #+#    #+#             */
/*   Updated: 2026/10/16 15:05:44 by spaccaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid_base(char *base)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = ft_strlen(base);
	if (size <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned long	size;
	char			c;
	unsigned long	n;
	int				i;

	i = 0;
	n = nbr;
	c = 0;
	size = 0;
	size = ft_strlen(base);
	if (is_valid_base(base) == 1)
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
			i++;
		}
		if (n >= size)
			i += ft_putnbr_base(n / size, base);
		i++;
		c = base[n % size];
		write(1, &c, 1);
	}
	return (i);
}

int	ft_check_purcent(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == '%')
		len += ft_putchar_fd('%', 1);
	else if (c == 'c')
		len += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			len += ft_putstr_fd("(null)", 1);
		else
			len += ft_putstr_fd(str, 1);
	}
	else if (c == 'p')
	{
		len += ft_putstr_fd("0x", 1);
		len += ft_putnbr_base((unsigned long)va_arg(args, void *), "0123456789abcdef");
	}
	else if (c == 'i' || c == 'd')
		len += ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else
		return (-1);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	int		result;
	va_list	args;

	if (!s)
		return (-1);
	va_start(args, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			result = ft_check_purcent(s[i + 1], args);
			if (result == -1)
			{
				len += ft_putchar_fd(s[i], 1);
				i++;
			}
			else
			{
				len += result;
				i += 2;
			}
		}
		else
		{
			len += ft_putchar_fd(s[i], 1);
			i++;
		}
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	int				nbr_print;
// 	char			*ptr;
// 	int				n_signed;
// 	int				i_signed;
// 	unsigned int	un;
// 	unsigned int	n_2;
// 	unsigned int	n_3;

// 	ptr = "hello world";
// 	n_signed = 1000;
// 	i_signed = -123;
// 	un = 23;
// 	n_2 = 17;
// 	n_3 = 4294967279;
// 	nbr_print = ft_printf("hello world, %%, [%c], [%s], [%p], [%d], [%i], [%u],
//			[%x], [%X] \n", ptr[3], ptr, ptr, n_signed, i_signed, un, n_2, n_3);
// 	printf(" sum %d \n", nbr_print);
// 	nbr_print = printf("hello world, %%, [%c], [%s], [%p], [%d], [%i], [%u],
//			[%x], [%X] \n", ptr[3], ptr, ptr, n_signed, i_signed, un, n_2, n_3);
// 	printf(" sum %d \n", nbr_print);
// 	return (0);
// }
