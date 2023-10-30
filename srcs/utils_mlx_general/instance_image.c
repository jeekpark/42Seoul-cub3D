/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:03:01 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/31 01:48:38 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_err	_validation_image_size(t_pixel image_size)
{
	if ((1 <= image_size.x && image_size.x <= 8192)
		&& (1 <= image_size.y && image_size.y <= 8192))
		return (TRUE);
	else
		return (FALSE);
}

t_err	instance_image(void **img, void *mlx, t_pixel image_size)
{
	if (img == NULL
		|| mlx == NULL
		|| _validation_image_size(image_size) == FALSE)
		return (FALSE);
	*img = mlx_new_image(mlx, image_size.x, image_size.y);
	if (*img == NULL)
		return (FALSE);
	else
		return (TRUE);	
}
