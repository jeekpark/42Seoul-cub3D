/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:17:47 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/30 20:05:18 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_err	instance_mlx(void** mlx)
{
	if (mlx == NULL || *mlx)
		return (FALSE);
	else
	{
		*mlx = mlx_init();
		if (*mlx == NULL)
			return (FALSE);
		else
			return (TRUE);
	}
}
