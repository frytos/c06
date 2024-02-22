/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:17:47 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/22 04:41:26 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str);
void	ft_sort(int len_array, char *array[]);
int		ft_strcmp(char *str1, char *str2);
void	ft_swap(char *a[], char *b[]);
// void	print_array(int len, char *agrv[]);

int	main(int argc, char *argv[])
{
	char	**sorted_argv;
	int		index;

	if (argc <= 1)
		return (0);
	else if (argc == 2)
	{
		ft_putstr(argv[1]);
		ft_putstr("\n");
		return (0);
	}
	index = 1;
	sorted_argv = malloc ((argc - 1) * sizeof (char *));
	if (sorted_argv == NULL)
		return (-1);
	while (index < argc)
	{
		sorted_argv[index - 1] = argv[index];
		index++;
	}
	ft_sort(argc - 1, sorted_argv);
	print_array(argc - 1, sorted_argv);
	free (sorted_argv);
	return (0);
}

void	print_array(int len, char *agrv[])
{
	int	index;

	index = 0;
	while (index < len)
	{
		ft_putstr(agrv[index++]);
		ft_putstr("\n");
	}
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
	int		max_search;
	char	*buff;

	index = len_array -1;
	while (0 <= index)
	{
		search_index = index - 1;
		max_search = index;
		while (0 <= search_index)
		{
			if (ft_strcmp(array[search_index], array[index]) > 0)
				max_search = search_index;
			search_index--;
		}
		buff = array[max_search];
		array[max_search] = array[index];
		array[index] = buff;
		index--;
	}
}

// void	ft_swap(char *a[], char *b[])
// {
// 	char	*buff;

// 	buff = *a;
// 	*a = *b;
// 	*b = buff;
// }

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
