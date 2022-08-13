/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtayache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:53:59 by rtayache          #+#    #+#             */
/*   Updated: 2022/07/03 21:54:02 by rtayache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	*ft_coords_creator(char *input, int len)
{
	int	*map;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (len != 16)
		return (0);
	map = (int *)malloc(sizeof(int) * len);
	while (input[i])
	{
		if (ft_skipspaces(input[i]))
			;
		else if (input[i] >= '1' && input[i] <= '4')
		{
			map[j] = input[i] - '0';
			j++;
		}
		i++;
	}
	return (map);
}

int	**map_creator(int arrsize)
{
	int	**arr;
	int	i;
	int	j;

	i = 0;
	j = 0;
	arr = (int **)malloc(sizeof(int) * arrsize);
	while (i < 4)
	{
		arr[i] = (int *)malloc(sizeof(int) * 4);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (arr);
}
