/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setsigs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 12:43:15 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/29 01:34:17 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void suspend(int s)
{
  t_ttyset *t;
  char susp[3];

  (void)s;
  t = old_settings(&t);
  ft_putstr_fd(CL, 0);
  t->term.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, TCSANOW, &t->term);
  ft_putstr_fd(TE, 0);
  ft_putstr_fd(VE, 0);
  // normal_mode(t);
  signal(SIGTSTP, SIG_DFL);
  susp[0] = t->term.c_cc[VSUSP];
  susp[1] = '\n';
  susp[2] = '\0';
  ioctl(0, TIOCSTI, &susp);
}

static void restart(int s)
{
  t_ttyset *t;

  (void)s;
  t = old_settings(&t);
  t_init(t, t->ac);
  setsigs(t);
  print_items(t);
}

static void size_changed(int s)
{
  t_ttyset *t;

  (void)s;
  t = NULL;
  t = old_settings(&t);
  if (tgetent(NULL, getenv("TERM")) <= 0)
    ERROR_EXIT
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
  ft_putstr_fd(CL, 0);
  if (s != -2)
    goto_xy(0, 0);
  else if (t->q_names > ROWS)
    goto_xy(0, ROWS - 1);
  else
    goto_xy(0, t->q_names);
  ft_putstr_fd(VE, 0);
  close(t->fd);
  free(t->selected);
  free(t);
  exit(s);
}

void setsigs(t_ttyset *t)
{
  t = old_settings(&t);
  signal(SIGWINCH, size_changed);
  signal(SIGTSTP, suspend);
  signal(SIGCONT, restart);
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
