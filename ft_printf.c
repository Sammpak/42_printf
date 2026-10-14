/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaccaud <spaccaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:19:06 by spaccaud          #+#    #+#             */
/*   Updated: 2026/10/14 16:27:09 by spaccaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"

int ft_printf(const char *s, ...)	
{
	char result[100];
	int i;

	i = 0;
	while(s[i])
	{
		if(s[i] == '%')
		{
			if(s[i + 1] == '%')
			printf("found pourcnet");
			break;
		}
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';

	printf("\n result : %s ", result);
	return (1);

	// va_list args;
	// va_start (args, s);
	// //count arg
	// ft_putstr_fd(va_arg(args, char *), 1);
	
	// va_end (args);   
	 
	// return (0);
	
}



//va_start, va_arg, va_copy, va_end
int main()
{
	// no %
	//ft_printf("hello world \n");
	// %c Prints a single character.
	ft_printf("single char [%c] \n");

	return (0);
// %s Prints a string (as defined by the common C convention).
// %p The void * pointer argument has to be printed in hexadecimal format.
// %d Prints a decimal (base 10) number.
// %i Prints an integer in base 10.
// %u Prints an unsigned decimal (base 10) number.
// %x Prints a number in hexadecimal (base 16) lowercase format.
// %X Prints a number in hexadecimal (base 16) uppercase format.
// %% Prints a percent sign
}