/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:15:46 by ashulha           #+#    #+#             */
/*   Updated: 2017/06/02 19:15:58 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void lst_delind(t_list **head, int index)
{
  t_list *list;
  t_list *cur;

  list = *head;
  if (!head || !*head)
    return ;
  if (index == 0)
  {
    (*head) = list->next;
    free_lst_node(list);
    return ;
  }
  while (list && --index > 0)
    list = list->next;
  if (!list)
    return ;
  cur = list->next;
  list->next = (cur->next) ? cur->next : NULL;
  free_lst_node(cur);
}
