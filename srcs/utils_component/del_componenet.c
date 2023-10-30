/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_componenet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 01:57:24 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/31 02:27:11 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	del_component(void *content)
{
	t_component	*temp;

	if (content == NULL)
		return ;
	temp = (t_component*)content;
	free(temp->name);
	mlx_destroy_image(temp->mlx, temp->img);
	free(temp);
}