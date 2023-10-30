/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del_all_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:43:23 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/30 23:58:00 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_err	list_del_all_node(t_list *list, void (*del)(void *))
{
	list->cursor = list->head;
	while (list->cursor)
		list_del_one_node(list, list->cursor, del);
	return (TRUE);
}
