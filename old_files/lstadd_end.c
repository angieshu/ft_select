/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:14:19 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/02 19:15:08 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void lstadd_end(t_list **head, char *content)
{
  t_list *old;
  t_list *new_node;

  old = *head;
  if (!(new_node = ft_lstnew(content, ft_strlen(content))))
    return;
  if (old)
  {
    while(old->next)
      old = old->next;
    old->next = new_node;
  }
  else
    (*head) = new_node;
}
