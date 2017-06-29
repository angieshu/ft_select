/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:20:03 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/29 15:34:20 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int size_ok(t_ttyset *t)
{
  int max_cols;

  max_cols = COLS / (t->max_len + 1);
  return (max_cols * (ROWS - 2) > t->q_names);
}

void print_items(t_ttyset *t)
{
  int index;
  int y;
  int x;

  index = -1;
  ft_putstr_fd(CL, 0);
  if (!size_ok(t))
    WRONG_SIZE;
  x = 0;
  y = 0;
  while (t->names[++index])
  {
    if (t->selected[index] == -1)
      continue ;
    goto_xy(x, y);
    (t->selected[index]) ? ft_putstr_fd(SO, 0) : 0;
    (index == t->cursor) ? ft_putstr_fd(US, 0) : 0;
    ft_putstr_fd(t->names[index], 0);
    ft_putchar_fd('\n', 0);
    normal_mode(t);
    (t->selected[index]) ? ft_putstr_fd(SE, 0) : 0;
    (y == ROWS - 2) ? (x += t->max_len + 1) : 0;
    y += (y == ROWS - 2) ? -y : 1;
  }
}
