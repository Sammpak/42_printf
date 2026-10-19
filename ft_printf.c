/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaccaud <spaccaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:19:06 by spaccaud          #+#    #+#             */
/*   Updated: 2026/10/19 13:00:09 by spaccaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned long	size;
	char			c;
	int				i;

	i = 0;
	size = ft_strlen(base);
	if (nbr >= size)
		i += ft_putnbr_base(nbr / size, base);
	i++;
	c = base[nbr % size];
	write(1, &c, 1);
	return (i);
}

int	ft_print_ptr(void *ptr)
{
	int	len;

	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	len = ft_putstr_fd("0x", 1);
	len += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	return (len);
}

int	ft_check_purcent(char c, va_list args)
{
	char	*str;

	if (c == '%')
		return (ft_putchar_fd('%', 1));
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (c == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			return (ft_putstr_fd("(null)", 1));
		return (ft_putstr_fd(str, 1));
	}
	if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	if (c == 'i' || c == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (c == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	return (-1);
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
		result = -1;
		if (s[i] == '%' && s[i + 1])
			result = ft_check_purcent(s[i + 1], args);
		if (result == -1)
			len += ft_putchar_fd(s[i++], 1);
		else
		{
			len += result;
			i += 2;
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