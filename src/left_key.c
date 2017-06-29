/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:42:26 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/29 15:42:53 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void left_key(t_ttyset *t)
{
  if ((t->cursor -= (ROWS - 1)) < 0)
  {
    t->cursor = 0;
    while (t->selected[t->cursor] == -1)
      t->cursor++;
  }
}
