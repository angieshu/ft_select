/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:37:59 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/29 16:47:27 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	up_key(t_ttyset *t)
{
	t->cursor--;
	while (t->selected[t->cursor] == -1 || t->cursor == -1)
	{
		(t->selected[t->cursor] == -1) ? t->cursor-- : 0;
		(t->cursor == -1) ? (t->cursor = t->ac - 1) : 0;
	}
}
