/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 12:25:52 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/29 01:23:07 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdio.h>

void return_selected(t_ttyset *t)
{
  int i;

  i = -1;
  ft_putstr_fd(CL, 0);
  while (t->names[++i])
  {
    if (t->selected[i] == 1)
    {
      ft_putstr(t->names[i]);
      ft_putchar(' ');
    }
  }
  finish(-1);
}

static void key(t_ttyset *t)
{
  if (t->key == ESC)
    finish(-2);
  if (t->key == SPC)
  {
    t->selected[t->cursor] = (t->selected[t->cursor]) ? 0 : 1;
    t->cursor++;
    while (t->selected[t->cursor] == -1 || t->cursor == t->ac)
    {
      (t->selected[t->cursor] == -1) ? t->cursor++ : 0;
      (t->cursor == t->ac) ? t->cursor = 0 : 0;
    }
  }
  if (t->key == UP)
  {
    t->cursor--;
    while (t->selected[t->cursor] == -1 || t->cursor == -1)
    {
      (t->selected[t->cursor] == -1) ? t->cursor-- : 0;
      (t->cursor == -1) ? (t->cursor = t->ac - 1) : 0;
    }
  }
  if (t->key == DOWN)
  {
    t->cursor++;
    while (t->selected[t->cursor] == -1 || t->cursor == t->ac)
    {
      (t->selected[t->cursor] == -1) ? t->cursor++ : 0;
      (t->cursor == t->ac) ? t->cursor = 0 : 0;
    }
  }
  if (t->key == RIGHT)
  {
    if ((t->cursor += (ROWS - 1)) > t->q_names - 1)
    {
      t->cursor = t->ac - 1;
      while (t->selected[t->cursor] == -1)
        t->cursor--;
    }
  }
  if (t->key == LEFT)
  {
    if ((t->cursor -= (ROWS - 1)) < 0)
    {
      t->cursor = 0;
      while (t->selected[t->cursor] == -1)
        t->cursor++;
    }
  }
  if (t->key == DEL || t->key == BKS)
  {
    t->selected[t->cursor] = -1;
    t->cursor++;
    (t->cursor == t->ac) ? t->cursor = 0 : 0;
    t->q_names--;
  }
  if (t->key == '\n')
    return_selected(t);
  t->key = 0;
}

void t_init(t_ttyset *t, int i)
{
  if (tgetent(NULL, getenv("TERM")) <= 0)
    ERROR_EXIT
  if ((t->fd = open(ttyname(0), O_RDWR | O_NDELAY)) < 0)
    ERROR_EXIT
  tcgetattr(t->fd, &t->term);
  t->term.c_lflag &= ~(ICANON | ECHO);
  t->term.c_cc[VMIN] = 1;
  t->term.c_cc[VTIME] = 0;
  tcsetattr(t->fd, TCSANOW, &t->term);
  setsigs(t);
  t->max_len = 0;
  t->cursor = 0;
  while (i-- > 0)
    t->selected[i] = 0;
  i = -1;
  while (t->names[++i])
  {
    if (ft_strlen(t->names[i]) > t->max_len)
      t->max_len = ft_strlen(t->names[i]);
  }
  ft_putstr_fd(VI, 2);
}

int main(int ac, char **av)
{
  t_ttyset *t;

  if (ac < 2)
    NO_ARG
  t = (t_ttyset*)ft_memalloc(sizeof(t_ttyset));
  t->selected = (int*)ft_memalloc(ac - 1);
  t->names = ++av;
  t->ac = --ac;
  t->q_names = ac;
  t_init(t, ac);
  goto_xy(0, 0);
  while (1)
  {
    print_items(t);
    read(0, &t->key, 8);
    key(t);
    if (!t->q_names)
      finish(0);
  }
}
