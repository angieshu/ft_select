/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 12:25:52 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/16 18:16:38 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void size_changed(int sign)
{
  (void)sign;
  ft_putstr("Hello, I'm changed\n");
}

void setsigs(void)
{
  signal(SIGWINCH, size_changed);
  // signal(SIGTSPT, suspend);
  // signal(SIGCONT, restart);
  // signal(SIGHUP, finish);
  // signal(SIGINT, finish);
  // signal(SIGQUIT, finish);
  // signal(SIGABRT, finish);
  // signal(SIGKILL, finish);
  // signal(SIGBUS, finish);
  // signal(SIGSEGV, finish);
  // signal(SIGALARM, finish);
  // signal(SIGTERM, finish);
  // signal(SIGUSR1, finish);
  // signal(SIGUSR2, finish);

}

int main(int ac, char **av)
{
  // t_ttyset t;
  // if (ac < 2)
  // {
  //   ft_putchar_fd('\n', 2);
  //   exit(1);
  // }
  setsigs();
  sleep(5);
  // ft_putstr("Nothing..\n");
  // t = ft_memalloc(sizeof(t_ttyset));
}
