/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 23:07:57 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/09 11:26:14 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void free_lst_node(t_list *list)
{
  free(list->content);
  free(list);
}

void title(char *p)
{
  int n;
  int len;
  int col;

  n = 0;
  len = 9;
  col =((COL - len)/ 2) - 1;
  clear_scr(p);
  while (n++ < col)
    printf("_");
  printf(" ft_select ");
  n += len + 1;
  col = COL - 1;
  while (n++ < col)
    printf("_");
    printf("\n");
}

void reset_tty(t_tty *tty_set)
{
  tty_set->cur_mod = 0;
  tty_set->inited = 0;
  tty_set->fd_tty = open(ttyname(0), o_RDWR | O_NDELAY);
  ioctl(fdtty, TCGETA, tty_set->old);
  new = old;

}

void visual_mod(void)
{
  t_tty *tty_set;

  reset_tty(tty_set);


}

int main(int ac, char **av, char **envp)
{
  char    buf[2048];
  char    *p;
  t_list  *list;
  int     i;
  // int     tty_fd;

  i = 1;
  list = NULL;
  while (i < ac)
    lstadd_end(&list, av[i++]);
  // tty_fd = open(ttyname(0), O_RDWR | O_NDELAY)
  if (tgetent(buf, p = getenv("TERM")) <= 0)
    exit (1);
  title(p);
  while (list)
  {
    printf("%s\n", list->content);
    list = list->next;
  }
  // clear_scr(p);
  // char *termtype;
  // int yes;
  //
  // termtype = getenv("TERM");
  // yes = tgetent(buf, termtype);
  // printf("%s\n", buf);
  // printf("ttyname is %s\n", ttyname(0));
  // printf("ttyslot is %d\n", ttyslot());
}
