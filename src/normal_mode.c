/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 16:39:08 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/29 16:39:14 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	normal_mode(t_ttyset *t)
{
	if (NORM)
		ft_putstr_fd(NORM, 0);
	else
		stand_end(t);
}
