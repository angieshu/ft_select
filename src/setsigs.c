/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setsigs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 12:43:15 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/29 16:03:15 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void suspend(int s)
{
  struct termios t_attr;
  char susp[2];

  (void)s;
  if (tcgetattr(0, &t_attr) == -1)
    ERROR_EXIT;
  susp[0] = t_attr.c_cc[VSUSP];
  susp[1] = 0;
  t_attr.c_lflag |= ICANON;
  t_attr.c_lflag |= ECHO;
  t_attr.c_oflag |= OPOST;
  if (tcsetattr(0, TCSADRAIN, &t_attr) == -1)
    ERROR_EXIT;
  ft_putstr_fd(VE, 2);
  ft_putstr_fd(TE, 2);
  signal(SIGTSTP, SIG_DFL);
  ioctl(0, TIOCSTI, susp);
}

static void restart(int s)
{
  t_ttyset *t;
  char buf[2];

  (void)s;
  t = NULL;
  t = old_settings(&t);
  tcgetattr(t->fd, &t->term);
  t->term.c_lflag &= ~(ICANON | ECHO);
  t->term.c_oflag &= ~(OPOST);
  t->term.c_cc[VMIN] = 1;
  t->term.c_cc[VTIME] = 0;
  tcsetattr(t->fd, TCSANOW, &t->term);
  if (tgetent(NULL, getenv("TERM")) <= 0)
    ERROR_EXIT;
  setsigs(t);
  ft_putstr_fd(VI, 0);
  ft_putstr_fd(TI, 0);
  buf[0] = -62;
  buf[1] = 0;
  ioctl(0, TIOCSTI, buf);
}

static void size_changed(int s)
{
  t_ttyset *t;

 (void)s;
 t = NULL;
 t = old_settings(&t);
 if (tgetent(NULL, getenv("TERM")) <= 0)
   ERROR_EXIT;
 print_items(t);
}

void setsigs(t_ttyset *t)
{
  t = old_settings(&t);
  signal(SIGWINCH, size_changed);
  signal(SIGTSTP, suspend);
  signal(SIGCONT, restart);
  signal(SIGILL, finish);
  signal(SIGPIPE, finish);
  signal(SIGFPE, finish);
  signal(SIGSYS, finish);
  signal(SIGEMT, finish);
  signal(SIGTRAP, finish);
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
