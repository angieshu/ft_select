/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stand_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 13:25:48 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/29 00:32:35 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void stand_end(t_ttyset *t)
{
  if (SE)
    ft_putstr_fd(SE, 0);
  else
    normal_mode(t);
}
