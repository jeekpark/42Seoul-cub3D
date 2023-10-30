/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_component.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:31:51 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/31 02:26:31 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_err	init_component(void *mlx, t_component *comp, t_pixel image_size)
{
	if (mlx == NULL || comp == NULL)
		return (FALSE);
	if (instance_image(&comp->img, mlx, image_size) == FALSE)
		return (FALSE);
	comp->name = NULL;
	comp->mlx = mlx;
	comp->width = image_size.x;
	comp->height = image_size.y;
	comp->mlx_data_addr = (int*)mlx_get_data_addr(comp->img, &comp->bpp,
			&comp->line_size, &comp->endian);
	if (comp->mlx_data_addr == NULL)
		return (FALSE);
	return (TRUE);
}
