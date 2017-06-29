/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:26:12 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/29 16:25:22 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	finish(int s)
{
	t_ttyset *t;

	t = NULL;
	t = old_settings(&t);
	normal_mode(t);
	t->term.c_lflag |= (ICANON | ECHO);
	t->term.c_oflag |= OPOST;
	tcsetattr(t->fd, TCSANOW, &t->term);
	(s == -1) ? 0 : ft_putstr_fd(CL, 0);
	ft_putstr_fd(VE, 0);
	close(t->fd);
	free(t->selected);
	free(t);
	exit(s);
}
