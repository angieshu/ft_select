/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:19:49 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/28 12:43:36 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void put_item(t_files *f, int x, int y, int n)
{
  t_ttyset *t;
  t_files *lst;

  t = NULL;
  t = old_settings(t);
  lst = f;
  (lst->selected) ? stand_out() : 0;
  while (n-- > 0)
    lst = lst->next;
  goto_xy(t, x, y);
    ft_putstr(US);
  ft_putstr(lst->name);
  (lst->selected) ? stand_end(t) : 0;
  normal_mode(t);
}
