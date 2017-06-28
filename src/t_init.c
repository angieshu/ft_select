/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 12:43:15 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/27 18:21:54 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void finish(int s)
{
  t_ttyset *t;

  t = NULL;
  t = old_settings(t);
  normal_mode(t);
  if (!t->inited)
    t_init(t);
  if (t->cur_mod == 0)
    return ;
  tcsetattr(t->fd, TCSANOW, &t->old);
  t->cur_mod = 0;
  goto_xy(t, 0, ROWS - 1);
  ft_putchar('\n');
  ft_putstr(VE);
  // free(t);
  exit(s);
}

static void setsigs(t_ttyset *t)
{
  t = old_settings(t);
  // signal(SIGWINCH, size_changed);
  // // signal(SIGTSPT, suspend);
  // // signal(SIGCONT, restart);
  // signal(SIGTSTP, finish);
  // signal(SIGCONT, finish);
  signal(SIGHUP, finish);
  signal(SIGINT, finish);
  signal(SIGQUIT, finish);
  signal(SIGABRT, finish);
  signal(SIGKILL, finish);
  signal(SIGBUS, finish);
  signal(SIGSEGV, finish);
  signal(SIGALRM, finish);
  signal(SIGTERM, finish);
  signal(SIGUSR1, finish);
  signal(SIGUSR2, finish);

}

void t_init(t_ttyset *t)
{
  t->fd = open(ttyname(0), O_RDWR | O_NDELAY);
  tcgetattr(t->fd, &t->old);
  t->new = t->old;
  t->new.c_iflag &= ~ICRNL;
  if ((t->old.c_cflag & CSIZE) == CS8)
      t->new.c_iflag &= ~ISTRIP;
  t->new.c_lflag &= ~(ICANON | ECHO);
  t->new.c_cc[VMIN] = 1;
  t->new.c_cc[VTIME] = 0;
  t->new.c_cc[VQUIT] = ESC;
  t->new.c_cc[VKILL] = DEL;
  setsigs(t);
  t->inited = 1;
}
