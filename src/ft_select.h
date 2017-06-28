/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:50:25 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/28 13:11:03 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "../libft/libft.h"
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
// # define BKS 0x7F
# define DEL 0x7F
# define UP 0x415B1B
// # define UP 65
# define DOWN 0x425B1B
// # define DOWN 66
// # define RIGHT 67
# define RIGHT 0x435B1B
# define LEFT 0x445B1B
// # define LEFT 68

# define COLS (tgetnum("co"))
# define ROWS (tgetnum("li"))

# define SO (tgetstr("so", NULL))
# define SE (tgetstr("se", NULL))
# define CL (tgetstr("cl", NULL))
# define CM (tgetstr("cm", NULL))
# define VE (tgetstr("ve", NULL))
# define VI (tgetstr("vi", NULL))
# define US (tgetstr("us", NULL))
# define UL (tgetstr("ul", NULL))
# define DO (tgetstr("do", NULL))
# define NORM (tgetstr("me", NULL))

# define SELECTED 10000

# define MSG (ft_putstr("Error occured\n"))
# define ERROR_EXIT(t) {MSG;free(t);exit(1);}

typedef struct  s_files
{
  char *name;
  // int cursor;
  int selected;
  struct s_files *next;
}               t_files;


typedef struct  s_ttyset
{
  // int key[3];
  long key;
  int cursor;
  int q_names;
  int q_sel;
  int max_len;
  int cur_mod;
  int inited;
  int fd;
  struct termios term;
  // struct termios new;
  // t_files files;

}               t_ttyset;


void clear_scr(void);
void t_init(t_ttyset *t);
void goto_xy(t_ttyset *t, int x, int y);
void normal_mode(t_ttyset *t);
void stand_end(t_ttyset *t);
void stand_out(void);
void put_item(t_files *f, int x, int y, int n);
void finish(int s);
void setsigs(t_ttyset *t);

t_ttyset *old_settings(t_ttyset *t);

#endif
