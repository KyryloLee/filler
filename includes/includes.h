/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:47:12 by klee              #+#    #+#             */
/*   Updated: 2018/02/07 12:47:14 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include "../libft/includes/libft.h"

typedef struct		s_mem
{
	int		*size;
	char	*place;
}					t_smem;

int					find_coord(int i, t_smem *board, t_smem *piece, char c);
int					*find_data(char *source, char *word);
char				*save_board(int *size_board, char *in);
int					dop_f(int i1, int i2);
int					find_position_dl(t_smem *board, t_smem *piece, int number);
int					find_position_ur(t_smem *board, t_smem *piece, int number);
int					find_position_ur1(t_smem *board, t_smem *piece, int number);
int					find_position_dr1(t_smem *board, t_smem *piece, int number);

#endif
