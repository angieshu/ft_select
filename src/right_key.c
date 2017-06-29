/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:41:12 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/29 16:42:50 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	right_key(t_ttyset *t)
{
	if ((t->cursor += (ROWS - 1)) > t->q_names - 1)
	{
		t->cursor = t->ac - 1;
		while (t->selected[t->cursor] == -1)
			t->cursor--;
	}
}
