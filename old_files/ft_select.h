/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 11:55:27 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/05 10:26:29 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <stdio.h>
# include <unistd.h>
# include <curses.h>
# include <term.h>
# include <stdlib.h>
# include <termios.h>
# include <signal.h>
# include <fcntl.h>
# include "libft/libft.h"

# define CL(p)  (tgetstr("cl", &p))
# define COL    (tgetnum("co"))
# define ROW    (tgetnum("li"))
# define SO(p)  (tgetstr("so", &p))

typedef struct  s_tty
{
  int cur_mod;
  int inited;
  int tty_fd;
  struct termio *old;
  struct termio *new;
}               t_tty;

void clear_scr(char *p);
void lstadd_end(t_list **head, char *content);
void free_lst_node(t_list *list);

#endif
