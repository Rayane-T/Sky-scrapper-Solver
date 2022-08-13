/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rtayache <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/07/02 17:22:56 by rtayache		  #+#	#+#			 */
/*   Updated: 2022/07/02 17:22:59 by rtayache		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "rush01.h"

void	i_cant(int **map)
{
	ft_free(map);
	write(1, "Error\n", 6);
}

void	do_smth(int *coords, int len)
{
	int		i;
	int		j;
	char	n;
	int		**map;

	map = map_creator(len);
	if (!solver (coords, map))
	{
		i_cant(map);
		return ;
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			n = map[i][j] + '0';
			write(1, &n, 1);
			if (j < 3)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
	ft_free(map);
}

void	check_input(char *input)
{
	int	i;
	int	numcounter;
	int	*coords;

	i = -1;
	numcounter = 0;
	while (input[++i])
	{
		if (ft_skipspaces(input[i]))
			;
		else if (input[i] >= '1' && input[i] <= '4')
			numcounter++;
		else
		{
			write(1, "Error\n", 6);
			return ;
		}
	}
	if (numcounter != 16)
	{
		write(1, "Error\n", 6);
		return ;
	}
	coords = ft_coords_creator(input, numcounter);
	do_smth(coords, numcounter);
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		check_input(av[1]);
	else
		write(1, "Error\n", 6);
	return (0);
}
