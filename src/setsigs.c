/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setsigs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 12:43:15 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/28 12:39:17 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void finish(int s)
{
  t_ttyset *t;

  t = NULL;
  t = old_settings(t);
  normal_mode(t);
  // if (!t->inited)
  //   t_init(t);
  // if (t->cur_mod == 0)
  //   return ;
  t->term.c_lflag |= (ICANON | ECHO);
  tcsetattr(t->fd, TCSANOW, &t->term);

  goto_xy(t, 0, ROWS - 1);
  ft_putchar('\n');
  ft_putstr(VE);
  // free(t);
  exit(s);
}

void setsigs(t_ttyset *t)
{
  t = old_settings(t);
  // signal(SIGWINCH, size_changed);
  // // signal(SIGTSPT, suspend);
  // // signal(SIGCONT, restart);
  // signal(SIGHUP, finish);
  // signal(SIGINT, finish);
  // signal(SIGQUIT, finish);
  // signal(SIGABRT, finish);
  // signal(SIGKILL, finish);
  // signal(SIGBUS, finish);
  // signal(SIGSEGV, finish);
  // signal(SIGALRM, finish);
  // signal(SIGTERM, finish);
  // signal(SIGUSR1, finish);
  signal(SIGUSR2, finish);

}
