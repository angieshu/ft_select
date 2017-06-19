/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 12:25:52 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/18 19:03:28 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdio.h>

void finish(int sign)
{
  (void)sign;
  // normal();
  tty(-1, NULL;) /* Close Visual Mode */
  ft_putchar('\n');
  exit (0);
}
//
void clear_scr(char *p)
{
  if (!CL(p))
    return ;
  ft_putstr(CL(p));
}


void set_ttyset(int ac, char **av, t_ttyset *t)
{
  int i;
  int len;

  t->files = av + 1;
  t->count_files = ac - 1;
  i = -1;
  while (++i < 1000)
    t->hlight[i] = 0;
  t->count_selected = 0;
  t->curr_pos = 0;
  i = -1;
  len = 0;
  t->max_len = 0;
  while (t->files[++i])
  {
    len = ft_strlen(t->files[i]);
    if (len > t->max_len)
      t->max_len = len;
  }
  t->cur_mod = 0;
  t->inited = 0;
  t->close = 0;
}

void size_changed(int sign)
{
  t_ttyset *t;

  ft_putstr(*(t->files));
  (void)sign;
  ft_putstr("Hello, I'm changed\n");
}

void tty(int ac, char **av, char *p)
{
  static t_ttyset *t;

  if (ac == 0)
  {
    (!t->inited) ? tyinit(t) : 0;
    if (t->cur_mod == 1)
      return ;
    ioctl(t->fdtty, TCSETAW, &new);
    t->cur_mod = 1;
  }
  else if (ac == -1)
  {
    (!t->inited) ? ttyinit(t) : 0;
    if (t->cur_mod == 0)
      return ;
    ioctl(t->fdtty, TCSETAW, &old);
    t->cur_mod = 0;
  }
  else
  {
    t = (t_ttyset*)ft_memalloc(sizeof(t_ttyset));
    set_ttyset(ac, av, t);
    ttyinit(t);
  }
}

void setsigs(t_ttyset *t)
{
  signal(SIGWINCH, size_changed);
  // signal(SIGTSPT, suspend);
  // signal(SIGCONT, restart);
  signal(SIGHUP, finish);
  signal(SIGINT, finish);
  signal(SIGQUIT, finish);
  signal(SIGABRT, finish);
  signal(SIGKILL, finish);
  signal(SIGBUS, finish);
  signal(SIGSEGV, finish);
  signal(SIGALARM, finish);
  signal(SIGTERM, finish);
  signal(SIGUSR1, finish);
  signal(SIGUSR2, finish);

}
void ttyinit(t_ttyset *t)
{
  t->fdtty = open(ttyname(0), O_RDWR | O_NDELAY);
  if (tcgetattr(t->fdtty, &t->old))
  return ;
  t->new = t->old;
  t->new.c_iflag &= ~ICRNL;
  if ((t->old.c_cflag & CSIZE) == CS8)
  t->new.c_iflag &= ~ISTRIP;
  t->new.c_lflag &= ~(ICANON | ECHO);
  t->new.c_cc[VMIN] = 1;
  t->new.c_cc[VTIME] = 0;
  t->new.c_cc[VQUIT] = ESC;
  t->new.c_cc[VERASE] = 0;
  t->new.c_cc[VKILL] = BKS;
  setsigs(t);
  t->inited = 1;
}


int main(int ac, char **av)
{
  // t_ttyset t;
  char buf[2048];
  char *p;

  if (tgetent(buf, p = getenv("TERM")) <= 0)
    exit (1);
  tty(ac, av, p);
  tty(0, NULL, p);
  clear_scr(p);
  
  // ttyinit(t);
  // printf("%s\n", *(t->files));
  // if (ac < 2)
  // {
  //   ft_putchar_fd('\n', 2);
  //   exit(1);
  // }
  // setsigs();
  // sleep(5);
  // ft_putstr("Nothing..\n");
  // t = ft_memalloc(sizeof(t_ttyset));
}
