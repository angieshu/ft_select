/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:50:25 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/29 16:32:01 by ashulha          ###   ########.fr       */
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
# define TE (tgetstr("te", NULL))
# define TI (tgetstr("ti", NULL))

# define NORM (tgetstr("me", NULL))

# define SELECTED 10000

# define MSG1 (ft_putstr_fd("Error occured\n", 2))
# define MSG2 (ft_putstr_fd("Not enough room.\n", 2))
# define MSG3 (ft_putstr_fd("No arguments received.\n", 2))
# define ERROR_EXIT do{MSG1;finish(0);}while(0)
# define WRONG_SIZE ({MSG2;return;})
# define NO_ARG do{MSG3;exit(0);}while(0)

typedef struct		s_ttyset
{
	long			key;
	char			**names;
	int				*selected;
	int				cursor;
	int				ac;
	int				q_names;
	int				max_len;
	int				cur_mod;
	int				inited;
	int				fd;
	struct termios	term;
}					t_ttyset;

void				goto_xy(int x, int y);
void				normal_mode(t_ttyset *t);
void				stand_end(t_ttyset *t);
void				finish(int s);
void				setsigs(t_ttyset *t);
void				print_items(t_ttyset *t);

void				spc_key(t_ttyset *t);
void				up_key(t_ttyset *t);
void				down_key(t_ttyset *t);
void				right_key(t_ttyset *t);
void				left_key(t_ttyset *t);
void				del_key(t_ttyset *t);

t_ttyset			*old_settings(t_ttyset **t);

#endif
