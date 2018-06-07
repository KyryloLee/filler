/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:15:06 by klee              #+#    #+#             */
/*   Updated: 2018/02/13 18:15:09 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int				dop_f(int i1, int i2)
{
	ft_printf("%d %d\n", i1, i2);
	return (1);
}

int				find_position_dl(t_smem *board, t_smem *piece, int number)
{
	int		i[3];
	char	c;

	c = (number == 1) ? 'O' : 'X';
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (i[2] < board->size[1])
	{
		if (find_coord(i[0], board, piece, c))
			return (dop_f(i[1], i[2]));
		if (i[1] > board->size[0])
		{
			i[2]++;
			i[1] = 0;
			i[0] = i[2];
		}
		else
		{
			i[0] += (board->size[1] + 1);
			i[1]++;
		}
	}
	return (0);
}

int				find_position_ur(t_smem *board, t_smem *piece, int number)
{
	int		i[4];
	char	c;

	c = (number == 1) ? 'O' : 'X';
	i[0] = (board->size[0] * (board->size[1] + 1)) - 1;
	i[1] = board->size[0] - 1;
	i[2] = board->size[1];
	i[3] = 2;
	while (i[2] >= 0)
	{
		if (find_coord(i[0], board, piece, c))
			return (dop_f(i[1], i[2]));
		if (i[1] <= 0)
		{
			i[2]--;
			i[1] = board->size[0] - 1;
			i[0] = (board->size[0] * (board->size[1] + 1) - i[3]++);
		}
		else
		{
			i[0] = i[0] - (board->size[1] + 1);
			i[1]--;
		}
	}
	return (0);
}

int				find_position_ur1(t_smem *board, t_smem *piece, int number)
{
	int		i[3];
	char	c;

	c = (number == 1) ? 'O' : 'X';
	i[0] = (board->size[1] - 1);
	i[1] = 0;
	i[2] = board->size[1] - 1;
	while (i[1] < board->size[0])
	{
		if (find_coord(i[0], board, piece, c))
			return (dop_f(i[1], i[2]));
		if (i[2] <= 0)
		{
			i[1]++;
			i[2] = board->size[1] - 1;
			i[0] = ((board->size[1] + 1) * (i[1] + 1)) - 2;
		}
		else
		{
			i[0]--;
			i[2]--;
		}
	}
	return (0);
}

int				find_position_dr1(t_smem *board, t_smem *piece, int number)
{
	int		i[3];
	char	c;

	c = (number == 1) ? 'O' : 'X';
	i[0] = ((board->size[0] - 1) * (board->size[1] + 1));
	i[1] = board->size[0] - 1;
	i[2] = 0;
	while (i[1] >= 0)
	{
		if (find_coord(i[0], board, piece, c))
			return (dop_f(i[1], i[2]));
		if (i[2] >= board->size[1])
		{
			i[1]--;
			i[2] = 0;
			i[0] = ((board->size[1] + 1) * (i[1]));
		}
		else
		{
			i[0]++;
			i[2]++;
		}
	}
	return (0);
}
