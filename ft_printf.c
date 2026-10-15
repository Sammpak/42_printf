/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaccaud <spaccaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:19:06 by spaccaud          #+#    #+#             */
/*   Updated: 2026/10/15 15:43:40 by spaccaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>

int		is_valid_base(char *base);

void	ft_putnbr_base(unsigned long nbr, char *base)
{
	int				basecheck;
	int				size;
	char			c;
	unsigned long	n;

	n = nbr;
	c = 0;
	size = 0;
	basecheck = 0;
	basecheck = is_valid_base(base);
	size = ft_strlen(base);
	if (basecheck == 1)
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		if (n >= size)
		{
			ft_putnbr_base(n / size, base);
		}
		c = base[n % size];
		write(1, &c, 1);
	}
}

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

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	char	*temp;
	va_list	args;
	char	*base_up;
	char	*base_low;

	va_start(args, s);
	base_up = "0123456789ABCDEF";
	base_low = "0123456789abcdef";
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '%')
				ft_putchar_fd('%', 1);
			else if (s[i + 1] == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (s[i + 1] == 's')
			{
				ft_putstr_fd(va_arg(args, char *), 1);
			}
			else if (s[i + 1] == 'p')
			{
				ft_putstr_fd("0x", 1);
				ft_putnbr_base(va_arg(args, long), base_low);
			}
			else if (s[i + 1] == 'i' || s[i + 1] == 'd')
			{
				ft_putnbr_fd(va_arg(args, int), 1);
			}
			else if (s[i + 1] == 'u')
			{
				ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
			}
			else if (s[i + 1] == 'x')
			{
				ft_putnbr_base(va_arg(args, unsigned int), base_low);
			}
			else if (s[i + 1] == 'X')
			{
				ft_putnbr_base(va_arg(args, unsigned int), base_up);
			} else {
				return -1;
			}
			i += 2;
			len++;
		}			
		write(1,&s[i],1);
		i++;
	}
	return (len + i);
}

// va_start, va_arg, va_copy, va_end
int	main(void)
{
	int nbr_print;
	char *ptr;
	ptr = "hello world";

	unsigned int un;
	unsigned int n;
	unsigned int n_2;
	unsigned int n_3;

	n = 10;
	n_2 = 17;
	n_3 = -17;
	un = -123;
	nbr_print = ft_printf("hello world, %%, [%c], [%s], [%p], [%d], [%i], [%u], [%x], [%X]", 	ptr[2], ptr, ptr, n, un, un, n_2, n_3);
	printf(" sum %d \n", nbr_print);
	nbr_print = printf("hello world, %%, [%c], [%s], [%p], [%d], [%i], [%u], [%x], [%X]", 		ptr[2], ptr, ptr, n, un, un, n_2, n_3);
	printf(" sum %d \n", nbr_print);

	return (0);
}