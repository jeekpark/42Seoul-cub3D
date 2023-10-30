/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:50:36 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/30 22:03:54 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_err	init_list(t_list *list)
{
	if (list == NULL)
		return (FALSE);
	ft_memset(list, 0, sizeof(t_list));
	return (TRUE);
}