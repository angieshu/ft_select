/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:44:06 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/29 15:44:42 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void del_key(t_ttyset *t)
{
  t->selected[t->cursor] = -1;
  t->cursor++;
  (t->cursor == t->ac) ? t->cursor = 0 : 0;
  t->q_names--;
}
