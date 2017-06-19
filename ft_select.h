/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:50:25 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/18 17:07:06 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft/libft.h"
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <signal.h>
# include <fcntl.h>
# include <time.h>
# include <curses.h>

# define ESC 0x1B
# define SPC 0x20
# define ENR 0xA
# define BKS 0x7F
# define DEL 0x7E335B1B
# define UP 0x415B1B
# define DOWN 0x425B1B
# define RIGHT 0x435B1B
# define LEFT 0x445B1B

# define WIDTH (tgetnum("co"))
# define HEIGHT (tgetnum("li"))

# define HLIGHT 1000

# define CL(p) (tgetstr("cl", &p))

# define NORM(p) (tgetstr("me", &p))

typedef struct  s_ttyset
{
  // int width;
  // int height;
  char **files;
  int count_files;
  int hlight[HLIGHT];
  int count_selected;
  int curr_pos;
  int max_len;
  int cur_mod;
  int inited;
  int fdtty;
  int close;
  struct termios old;
  struct termios new;
}               t_ttyset;


#endif
