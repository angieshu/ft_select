/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:01:29 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/29 16:40:16 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_ttyset	*old_settings(t_ttyset **t)
{
	static t_ttyset *tmp;

	if (*t == NULL)
		return (tmp);
	tmp = *t;
	return (*t);
}
