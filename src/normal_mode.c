/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 13:23:03 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/29 00:32:53 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void normal_mode(t_ttyset *t)
{
  if (NORM)
    ft_putstr_fd(NORM, 0);
  else
    stand_end(t);
}
