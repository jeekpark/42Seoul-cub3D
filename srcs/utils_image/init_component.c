/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_component.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:31:51 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/30 20:45:49 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_err	_validation_img_size(t_pixel img_size)
{
	if ((1 <= img_size.x && img_size.x <= 8192)
		&& (1 <= img_size.y && img_size.y <= 8192))
		return (TRUE);
	else
		return (FALSE);
}

static t_err	_validation_component(t_component *comp)
{
	if (comp == NULL)
		return (FALSE);
	if (comp->img)
		return (FALSE);
	return (TRUE);
}

static t_err	_validation_mlx(void *mlx)
{
	if (mlx == NULL)
		return (FALSE);
	else
		return (TRUE);
}

t_err	init_component(void *mlx, t_component *comp, t_pixel img_size)
{
	if (_validation_mlx(mlx) == FALSE
		|| _validation_component(comp) == FALSE
		|| _validation_img_size(img_size) == FALSE)
		return (FALSE);
	comp->img = mlx_new_image(mlx, img_size.x, img_size.y);
	if (comp->img == NULL)
		return (FALSE);
	comp->width = img_size.x;
	comp->height = img_size.y;
	comp->mlx_data_addr = (int*)mlx_get_data_addr(comp->img, &comp->bpp,
			&comp->line_size, &comp->endian);
	if (comp->mlx_data_addr == NULL)
		return (FALSE);
	return (TRUE);
}
