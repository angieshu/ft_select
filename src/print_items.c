/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:20:03 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/28 18:57:01 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int size_ok(t_ttyset *t)
{
  int i;
  int max_cols;

  t->max_len = 0;
  i = -1;
  while (t->names[++i])
  {
    if (ft_strlen(t->names[i]) > t->max_len)
      t->max_len = ft_strlen(t->names[i]);
  }
  max_cols = COLS / (t->max_len + 1);
  return (max_cols * ROWS > t->q_names);
}

void print_items(t_ttyset *t)
{
  int index;
  int y;
  int x;

  index = -1;
  clear_scr();
  if (!size_ok(t))
    WRONG_SIZE
  x = 0;
  y = 0;
  while (t->names[++index])
  {
    if (t->selected[index] == -1)
      continue ;
    if (y == ROWS - 1)
      goto_xy(x += t->max_len + 1, y = 0);
    (t->selected[index]) ? ft_putstr(SO) : 0;
    (index == t->cursor) ? ft_putstr(US) : 0;
    ft_putstr(t->names[index]);
    ft_putchar('\n');
    normal_mode(t);
    (t->selected[index]) ? ft_putstr(SE) : 0;
    y++;
    ft_putnbr(COLS);
  }
}
