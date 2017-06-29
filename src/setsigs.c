/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setsigs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 12:43:15 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/28 18:55:51 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void size_changed(int s)
{
  t_ttyset *t;

  (void)s;
  t = NULL;
  t = old_settings(&t);
  print_items(t);
}

void finish(int s)
{
  t_ttyset *t;

  t = NULL;
  t = old_settings(&t);
  normal_mode(t);
  t->term.c_lflag |= (ICANON | ECHO);
  tcsetattr(t->fd, TCSANOW, &t->term);
  clear_scr();
  goto_xy(0, t->q_names);
  ft_putstr(VE);
  close(t->fd);
  free(t->selected);
  free(t);
  exit(s);
}

void setsigs(t_ttyset *t)
{
  t = old_settings(&t);
  signal(SIGWINCH, size_changed);
  // // signal(SIGTSPT, suspend);
  // // signal(SIGCONT, restart);
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
