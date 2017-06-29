/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 12:25:52 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/29 15:45:34 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdio.h>

static void return_selected(t_ttyset *t)
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
    finish(0);
  if (t->key == SPC)
    spc_key(t);
  if (t->key == UP)
    up_key(t);
  if (t->key == DOWN)
    down_key(t);
  if (t->key == RIGHT)
    right_key(t);
  if (t->key == LEFT)
    left_key(t);
  if (t->key == DEL || t->key == BKS)
    del_key(t);
  if (t->key == '\n')
    return_selected(t);
  t->key = 0;
}

static void t_init(t_ttyset *t, int i)
{
  if (!getenv("TERM"))
    ERROR_EXIT;
  if (tgetent(NULL, getenv("TERM")) <= 0)
    ERROR_EXIT;
  if ((t->fd = open(ttyname(0), O_RDWR | O_NDELAY)) < 0)
    ERROR_EXIT;
  tcgetattr(t->fd, &t->term);
  t->term.c_lflag &= ~(ICANON | ECHO);
  t->term.c_oflag &= ~(OPOST);
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
  ft_putstr_fd(VI, 0);
}

int main(int ac, char **av, char **env)
{
  t_ttyset *t;

  if (*env == NULL || env == NULL)
  {
    ft_putstr_fd("No enviroment.\n", 2);
    exit(1);
  }
  if (ac < 2)
    NO_ARG;
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
