/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:25:00 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/30 20:05:17 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_err	_validation_win_size(t_pixel win_size)
{
	if ((640 <= win_size.x && win_size.x <= 3860)
		&& (320 <= win_size.y && win_size.y <= 2160))
		return (TRUE);
	else
		return (FALSE);
}

t_err	instance_window(void **win, void *mlx, t_pixel win_size, char *title)
{
	if (win == NULL
		|| *win != NULL
		|| mlx == NULL
		|| title == NULL
		|| _validation_win_size(win_size) == FALSE)
		return (FALSE);
	else
	{
		*win = mlx_new_window(mlx, win_size.x, win_size.y, title);
		if (*win == NULL)
			return (FALSE);
		else
			return (TRUE);
	}
}
