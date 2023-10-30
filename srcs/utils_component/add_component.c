/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_component.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 01:53:41 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/31 02:22:04 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_err	add_component_to_list(t_component *comp, t_list *list, char *name)
{
	if (comp == NULL || list == NULL || name == NULL)
	{
		return (FALSE);
	}
	if (find_component_by_name(list, name))
	{
		return (FALSE);
	}
	comp->name = ft_strdup(name);
	if (comp->name == NULL)
	{
		return (FALSE);
	}
	if (list_push_back((void*)comp, list) == FALSE)
	{
		return (FALSE);
	}
	return (TRUE);
}
