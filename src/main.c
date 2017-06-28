/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 12:25:52 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/28 12:59:34 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdio.h>

void make_list(t_files **head, t_ttyset *t, char **av)
{
  t_files *old;
  t_files *f;
  int i;

  i = 0;
  while (av[++i])
  {
    if (ft_strlen(av[i]) > t->max_len)
      t->max_len = ft_strlen(av[i]);
    f = (t_files*)ft_memalloc(sizeof(t_files));
    f->name = ft_strdup(av[i]);
    f->selected = 0;
    f->next = NULL;
    if (i == 1)
    {
      *head = f;
      old = *head;
      continue;
    }
    while (old->next)
    old = old->next;
    old->next = f;
  }
}

void print_items(t_ttyset *t, t_files *f)
{
  t_files *lst;

  lst = f;
  if (t->q_names > ROWS || t->max_len > COLS)
  {
    ft_putstr("Error: Not enough room.");
    exit(1);
  }
  while (lst)
  {

    if (lst->selected)
      ft_putstr(SO);
    ft_putstr(lst->name);
    ft_putchar('\n');
    // ft_putstr(NORM);
    lst = lst->next;
  }
}

void selected(t_files **f, int index)
{
  t_files *tmp;

  tmp = *f;
  while (index--)
    tmp = tmp->next;
  tmp->selected = (!tmp->selected) ? 1 : 0;
}

void t_init(t_ttyset *t)
{
  if (tgetent(NULL, getenv("TERM")) <= 0)
    ERROR_EXIT(t)
  if ((t->fd = open(ttyname(0), O_RDWR | O_NDELAY)) < 0)
    ERROR_EXIT(t)
  tcgetattr(t->fd, &t->term);
  t->term.c_lflag &= ~(ICANON | ECHO);
  t->term.c_cc[VMIN] = 1;
  t->term.c_cc[VTIME] = 0;
  tcsetattr(t->fd, TCSADRAIN, &t->term);
  setsigs(t);
  t->q_sel = 0;
  t->max_len = 0;
  t->cursor = 0;
}


int main(int ac, char **av)
{
  t_ttyset *t;
  t_files *f = NULL;

  t = (t_ttyset*)ft_memalloc(sizeof(t_ttyset));
  t_init(t);
  t->q_names = --ac;
  make_list(&f, t, av);
  // print_items(t, f);
  goto_xy(t, 0, ft_strlen(f->name));
  ft_putstr(VI);
  while (read(0, &t->key, 8) > 0)
  {
    clear_scr();
    print_items(t, f);
    put_item(f, 0, t->cursor, t->cursor);
    if (t->key == DOWN)
    {
      t->cursor++;
      (t->cursor == t->q_names) ? (t->cursor = 0) : 0;
    }
    if (t->key == SPC)
      selected(&f, t->cursor);
  }
}
