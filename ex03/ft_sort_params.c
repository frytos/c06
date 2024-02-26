/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:17:47 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/22 22:28:49 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);
void	ft_sort(int len_array, char *array[]);
int		ft_strcmp(char *str1, char *str2);

int	main(int argc, char *argv[])
{
	int	index;

	if (argc <= 1)
		return (0);
	else if (argc == 2)
	{
		ft_putstr(argv[1]);
		ft_putstr("\n");
		return (0);
	}
	ft_sort(argc, argv);
	index = 1;
	while (index < argc)
	{
		ft_putstr(argv[index++]);
		ft_putstr("\n");
	}
	return (0);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	index;

	index = 0;
	while (str1[index] == str2[index] && str1[index])
		index++;
	return (str1[index] - str2[index]);
}

void	ft_sort(int len_array, char *array[])
{
	int		index;
	int		search_index;
	int		min_search;
	char	*buff;

	index = 1;
	while (index < len_array - 1)
	{
		search_index = index + 1;
		min_search = index;
		while (search_index < len_array)
		{
			if (ft_strcmp(array[min_search], array[search_index]) > 0)
				min_search = search_index;
			search_index++;
		}
		buff = array[min_search];
		array[min_search] = array[index];
		array[index] = buff;
		index++;
	}
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
