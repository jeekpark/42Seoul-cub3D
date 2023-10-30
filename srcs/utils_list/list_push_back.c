/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:04:23 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/30 22:08:08 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_err	list_push_back(void* content, t_list *list)
{
	t_node	*node;

	if (list == NULL || content == NULL)
		return (FALSE);
	node = (t_node *)ft_calloc(sizeof(t_node), 1);
	if (node == NULL)
		return (FALSE);
	node->content = content;
	node->next_node = NULL;
	node->prev_node = list->tail;
	if (node->prev_node != NULL)
		node->prev_node->next_node = node;
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
		list->cursor = node;
		return (TRUE);
	}
	list->tail = node;
	return (TRUE);
}
