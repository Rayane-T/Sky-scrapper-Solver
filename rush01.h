/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtayache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:41:16 by rtayache          #+#    #+#             */
/*   Updated: 2022/07/03 19:41:19 by rtayache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

//----main.c
void	i_cant(int **map);
void	ft_free(int **map);
void	check_input(char *input);

//----creator.c
int		*ft_coords_creator(char *input, int len);
int		**map_creator(int arrsize);

//----check_with_rules.c
void	ft_free(int **map);
int		vertical_bot(int i, int **arr);
int		checkvertical(int input_top, int input_bot, int i, int **arr);
int		horizontal_right(int i, int **arr);
int		checkhorizontal(int input_left, int input_right, int i, int **arr);

//----rush01.c
int		ft_skipspaces(int a);
int		solver(int *input, int **arr);
int		checksolution(int *input, int **arr);
int		checknoidentical(int currvalue, int i, int j, int **arr);
int		checkzero(int *row, int *col, int **arr);

#endif
