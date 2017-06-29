/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_xy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 13:05:06 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/29 15:00:44 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void goto_xy(int x, int y)
{
  if (x < 0 || y < 0 || x > COLS - 1|| y > ROWS - 1)
    ERROR_EXIT;
  ft_putstr_fd(tgoto(CM, x, y), 0);
}
