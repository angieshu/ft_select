/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 12:25:52 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/27 19:22:01 by ashulha          ###   ########.fr       */
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
    f->cursor = 0;
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
  t_files lst;

  lst = f;
  if (t->q_names > ROWS || t->max_len > COLS)
  {
    ft_putstr("Error: Not enough room.")
    exit(1);
  }
  while (lst)
  {
    if (lst->cursor)
        ft_putstr(US);
    if (lst->selected)
      ft_putstr(SO);
    ft_putstr(lst->name);
    ft_putstr(NORM);
    lst = lst->next;
}
// static void print_items(t_ttyset *t)
// {
//   int i;
//
//   i = 0;
//   while (t->name[i])
//   {
//     ft_putstr(t->name[i++]);
//     ft_putchar('\n');
//   }
// }

static void visual_mode(t_ttyset *t)
{
  if (!t->inited)
    t_init(t);
  if (t->cur_mod == 1)
    return ;
  tcsetattr(t->fd, TCSADRAIN, &t->new);
  t->cur_mod = 1;
}


static void init(t_ttyset *t, int ac)
{
  char buf[2048];

  if (tgetent(buf, getenv("TERM")) <= 0)
    ERROR_EXIT(t)
  // t->names = av + 1;
  t->q_names = ac - 1;
  t->cur_mod = 0;
  t->inited = 0;
  t->cur_mod = 0;
  t->q_sel = 0;
  t->max_len = 0;
}

/*
** out = 1 -> cursor
** out = 2 -> selected
*/



int main(int ac, char **av)
{
  int i;
  // char *c;
  t_ttyset *t;
  t_files *f = NULL;

  t = (t_ttyset*)ft_memalloc(sizeof(t_ttyset));
  init(t, ac);
  t_init(t);
  make_list(&f, t, av);
  visual_mode(t);
  clear_scr();
  print_items(t, f);
  // c = ft_strnew(5);
  // while (i++ < 5)
  // {
  //   read(0, &c, 1);
  //   ft_putstr(c);
  // }

  // while (t->q_names)
  // {
    // ft_putstr();
    // put_item(t->names[i], 0, i, 1);
    // if (c[0] == DOWN)
    // {
    //   i++;
    //   (i == t->q_names) ? (i = 0) : 0;
    // }
    // else if (c[0] == '\b' || c[0] == DEL)
    // {
    //   i--;
    //   (i < 0) ? (i = t->q_names - 1) : 0;
    // }
    // else if (c[0] == ESC)
    //   exit(1);
    // ft_strclr(c);
    // put_item(t->names[i], 0, i, 0);
    // else if ()

    // ft_putstr(UL(t);
    // MS();
  // }

}
