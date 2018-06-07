/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_file1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:15:50 by klee              #+#    #+#             */
/*   Updated: 2018/02/13 18:15:51 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int				find_coord(int i, t_smem *board, t_smem *piece, char c)
{
	int		g;
	int		k;
	char	c1;

	g = 0;
	k = 0;
	c1 = (c == 'X') ? 'O' : 'X';
	while (piece->place[g])
	{
		if ((i > board->size[0] * (board->size[1] + 1)) ||\
			(board->place[i] == '\n' && piece->place[g] != '\n'))
			return (0);
		if ((board->place[i] == c || board->place[i] == c + 32)\
			&& piece->place[g] == '*')
			k++;
		if ((board->place[i] == c1 || board->place[i] == c1 + 32)\
			&& piece->place[g] == '*')
			return (0);
		if (piece->place[g] == '\n')
			i += board->size[1] - piece->size[1];
		i++;
		g++;
	}
	return (k == 1) ? 1 : 0;
}

int				*find_data(char *source, char *word)
{
	int *size_d;

	size_d = (int*)malloc(sizeof(int) * 3);
	size_d[2] = 0;
	if (ft_strstr(source, word))
	{
		source = ft_strchr(source, ' ');
		size_d[0] = ft_atoi(source);
		source++;
		source = ft_strchr(source, ' ');
		size_d[1] = ft_atoi(source);
		return (size_d);
	}
	return (0);
}

char			*save_board(int *size_board, char *in)
{
	int		i;
	int		c;
	char	*line;
	char	*res;

	i = 0;
	res = ft_strdup("");
	if (!ft_strstr(in, "Piece"))
	{
		get_next_line(0, &line);
		free(line);
	}
	c = ft_strstr(in, "Piece") ? 0 : 4;
	while (i < size_board[0])
	{
		get_next_line(0, &line);
		ft_join_free(&res, line + c);
		ft_join_free(&res, "\n");
		free(line);
		i++;
	}
	return (res);
}
