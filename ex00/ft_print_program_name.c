/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:58:35 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/21 16:20:28 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_program_name(char *argv[]);

int	main(int argc, char *argv[])
{
	(void)argc;
	ft_print_program_name(argv);
	return (0);
}

void	ft_print_program_name(char *argv[])
{
	int	len;

	len = 0;
	while (argv[0][len] != 0)
	{
		write(1, &argv[0][len], 1);
		len++;
	}
	write(1, &"\n", 1);
}
