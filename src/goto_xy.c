/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_xy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 13:05:06 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/27 18:20:09 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void goto_xy(t_ttyset *t, int x, int y)
{
  if (x < 0 || y < 0 || x > COLS || y > ROWS)
    ERROR_EXIT(t);
  ft_putstr(tgoto(CM, x, y));
}