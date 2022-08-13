/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtayache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:16:22 by nmaliare          #+#    #+#             *//*   Updated: 2022/07/05 15:58:52 by rtayache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_skipspaces(int a)
{
	if (a == '\t' || a == '\n' || a == '\v' || a == ' ')
		return (1);
	else
		return (0);
}

int	checkzero(int *row, int *col, int **arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[i][j] == 0)
			{
				*row = i;
				*col = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	checknoidentical(int currvalue, int i, int j, int **arr)
{
	int	a;

	a = 0;
	while (a < 4)
	{
		if (arr[i][a] == currvalue || arr[a][j] == currvalue)
			return (0);
		a++;
	}
	return (1);
}

int	checksolution(int *input, int **arr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!(checkvertical(input[i], input[i + 4], i, arr))
			|| !(checkhorizontal(input[i + 8], input [i + 12], i, arr)))
			return (0);
		i++;
	}
	return (1);
}

int	solver(int *input, int **arr)
{
	int	i;
	int	j;
	int	a;

	if (!checkzero(&i, &j, arr))
		return (1);
	a = 1;
	while (a <= 4)
	{
		if (checknoidentical(a, i, j, arr))
		{
			arr[i][j] = a;
			if (solver(input, arr))
			{
				if (checksolution(input, arr))
					return (1);
			}
			arr[i][j] = 0;
		}
		a++;
	}
	return (0);
}
