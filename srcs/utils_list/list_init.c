/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:50:36 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/30 23:51:17 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_err	list_init(t_list *list)
{
	if (list == NULL)
		return (FALSE);
	ft_memset(list, 0, sizeof(t_list));
	return (TRUE);
}