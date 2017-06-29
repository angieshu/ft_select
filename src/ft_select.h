/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:50:25 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/28 18:53:25 by ashulha          ###   ########.fr       */
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
# define DEL 0x7E335B1B
# define BKS 0x7F
# define UP 0x415B1B
# define DOWN 0x425B1B
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
# define DO (tgetstr("do", NULL))
# define NORM (tgetstr("me", NULL))

# define SELECTED 10000

# define MSG (ft_putstr("Error occured\n"))
# define ERROR_EXIT {MSG;finish(0);}
# define WRONG_SIZE {ft_putstr("Not enough room.\n");return;}
# define NO_ARG {ft_putstr("No arguments received.\n");exit(0);}

typedef struct  s_ttyset
{
  long key;
  char **names;
  int *selected;
  int cursor;
  int ac;
  int q_names;
  int q_sel;
  int max_len;
  int cur_mod;
  int inited;
  int fd;
  struct termios term;
}               t_ttyset;


void clear_scr(void);
void goto_xy(int x, int y);
void normal_mode(t_ttyset *t);
void stand_end(t_ttyset *t);
void finish(int s);
void setsigs(t_ttyset *t);
void print_items(t_ttyset *t);

t_ttyset *old_settings(t_ttyset **t);

#endif
