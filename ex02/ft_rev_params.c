/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:12:44 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/21 23:06:01 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);

int	main(int argc, char *argv[])
{
	int index;

	index = argc - 1;
	while (index > 0)
	{
		while (*argv[index])
			write(1, argv[index]++, 1);
		ft_putchar(10);
		index--;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}
		

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
