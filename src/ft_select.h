/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:50:25 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/27 18:20:00 by ashulha          ###   ########.fr       */
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
// # define DOWN 0x425B1B
# define DOWN 80
# define RIGHT 0x435B1B
# define LEFT 0x445B1B

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
# define NORM (tgetstr("me", NULL))

# define SELECTED 10000

# define MSG (ft_putstr("Error occured\n"))
# define ERROR_EXIT(t) {MSG;free(t);exit(1);}

typedef struct  s_files
{
  char *name;
  int cursor;
  int selected;
  struct s_files *next;
}               t_files;


typedef struct  s_ttyset
{
  // int width;
  // int height;
  // char **names;
  // int sel[SELECTED];
  int q_names;
  int q_sel;
  // int curr_pos;
  int max_len;
  int cur_mod;
  int inited;
  int fd;
  char *p;
  struct termios old;
  struct termios new;
  // t_files files;

}               t_ttyset;


void clear_scr(void);
void t_init(t_ttyset *t);
void goto_xy(t_ttyset *t, int x, int y);
void normal_mode(t_ttyset *t);
void stand_end(t_ttyset *t);
void stand_out(t_ttyset *t);
void put_item(char *name, int x, int y, int out);
void finish(int s);

t_ttyset *old_settings(t_ttyset *t);

#endif
