/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtayache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:55:52 by rtayache          #+#    #+#             */
/*   Updated: 2022/07/03 19:55:56 by rtayache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	vertical_bot(int i, int **arr)
{
	int	a;
	int	counter;
	int	currmax;

	a = 4;
	counter = 0;
	currmax = 0;
	while (--a >= 0)
	{
		if (arr[a][i] > currmax)
		{
			currmax = arr[a][i];
			counter++;
		}
	}
	return (counter);
}

int	checkvertical(int input_top, int input_bot, int i, int **arr)
{
	int	a;
	int	counter;
	int	currmax;

	a = -1;
	counter = 0;
	currmax = 0;
	while (++a < 4)
	{
		if (arr[a][i] > currmax)
		{
			currmax = arr[a][i];
			counter++;
		}
	}
	if (input_top != counter)
		return (0);
	counter = vertical_bot(i, arr);
	if (input_bot != counter)
		return (0);
	return (1);
}

int	horizontal_right(int i, int **arr)
{
	int	a;
	int	counter;
	int	currmax;

	a = 4;
	counter = 0;
	currmax = 0;
	while (--a >= 0)
	{
		if (arr[i][a] > currmax)
		{
			currmax = arr[i][a];
			counter++;
		}
	}
	return (counter);
}

int	checkhorizontal(int input_left, int input_right, int i, int **arr)
{
	int	a;
	int	counter;
	int	currmax;

	a = -1;
	counter = 0;
	currmax = 0;
	while (++a < 4)
	{
		if (arr[i][a] > currmax)
		{
			currmax = arr[i][a];
			counter++;
		}
	}
	if (input_left != counter)
		return (0);
	counter = horizontal_right(i, arr);
	if (input_right != counter)
		return (0);
	return (1);
}

void	ft_free(int **map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
