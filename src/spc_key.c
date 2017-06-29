/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:35:48 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/29 16:46:11 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	spc_key(t_ttyset *t)
{
	t->selected[t->cursor] = (t->selected[t->cursor]) ? 0 : 1;
	t->cursor++;
	while (t->selected[t->cursor] == -1 || t->cursor == t->ac)
	{
		(t->selected[t->cursor] == -1) ? t->cursor++ : 0;
		(t->cursor == t->ac) ? t->cursor = 0 : 0;
	}
}
