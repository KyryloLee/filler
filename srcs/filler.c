/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 10:53:17 by klee              #+#    #+#             */
/*   Updated: 2018/02/07 10:53:48 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

static int		g_number;

int				f_player(char *line)
{
	static int	number_player = 0;

	if (ft_strstr(line, "exec p1"))
	{
		if (ft_strstr(line, "klee.filler"))
			number_player += 1;
	}
	else if (ft_strstr(line, "exec p2"))
	{
		if (ft_strstr(line, "klee.filler"))
			number_player += 2;
	}
	return (number_player);
}

int				super_strategy(t_smem *board, t_smem *piece, int number)
{
	static int	i = 0;
	int			n;

	n = 0;
	if (i == n)
	{
		i++;
		return (find_position_ur1(board, piece, number));
	}
	else if (i == n + 1)
	{
		i++;
		return (find_position_dr1(board, piece, number));
	}
	else if (i == n + 2)
	{
		i++;
		return (find_position_ur(board, piece, number));
	}
	else if (i == n + 3)
	{
		i = n;
		return (find_position_dl(board, piece, number));
	}
	return (0);
}

void			make_good_clean(t_smem **board, t_smem **piece)
{
	free((*board)->size);
	free((*board)->place);
	free((*piece)->size);
	free((*piece)->place);
}

t_smem			*make_new_struct(void)
{
	t_smem	*new;

	new = malloc(sizeof(t_smem));
	new->size = NULL;
	new->place = NULL;
	return (new);
}

int				main(void)
{
	char			*line;
	t_smem			*board;
	t_smem			*piece;

	board = make_new_struct();
	piece = make_new_struct();
	while (get_next_line(0, &line))
	{
		g_number = f_player(line);
		if (ft_strstr(line, "Plateau"))
		{
			board->size = find_data(line, "Plateau");
			board->place = save_board(board->size, "Plateau");
		}
		if (ft_strstr(line, "Piece"))
		{
			piece->size = find_data(line, "Piece");
			piece->place = save_board(piece->size, "Piece");
			(!super_strategy(board, piece, g_number)) ?\
			ft_printf("0 0\n") : 1 - 1;
			make_good_clean(&board, &piece);
		}
		free(line);
	}
	return (0);
}
