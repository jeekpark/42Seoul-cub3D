/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_component_by_name.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 02:07:48 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/31 02:18:33 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	_strcmp_alt(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (TRUE);
		++s1;
		++s2;
	}
	return (FALSE);
}

t_node	*find_component_by_name(t_list *list, char *name)
{
	t_component	*temp;

	if (list == NULL || name == NULL)
		return (FALSE);
	list->cursor = list->head;
	while (list->cursor)
	{
		temp = (t_component*)list->cursor->content;
		if (_strcmp_alt(name, temp->name) == TRUE)
			return (list->cursor);
		list->cursor = list->cursor->next_node;
	}
	return (NULL);
}