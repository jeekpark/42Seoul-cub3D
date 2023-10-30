/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:25:00 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/30 17:22:30 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_err	_validation_win_size(t_pixel win_size)
{
	if ((640 <= win_size.x && win_size.x <= 3860)
		&& (320 <= win_size.y && win_size.y <= 2160))
		return (TRUE);
	else
		return (FALSE);
}

t_err	_assign_mlx_instances(
	void **mlx,
	void **win,
	t_pixel win_size,
	char *title)
{
	*mlx = mlx_init();
	if (*mlx == NULL)
	{
		ft_putstr_fd("Error\n init_window(): Failed to make mlx instance.\n",
			STDERR_FILENO);
		return (FALSE);
	}
	*win = mlx_new_window(*mlx, win_size.x, win_size.y, title);
	if (*win == NULL)
	{
		ft_putstr_fd("Error\n init_window(): Failed to make window instance.\n",
			STDERR_FILENO);
		return (FALSE);
	}
	return (TRUE);
}

t_err	init_window(
	void **mlx,
	void **win,
	t_pixel win_size,
	char *title)
{
	if (title == NULL || mlx == NULL || win == NULL)
	{
		ft_putstr_fd("Error\ninit_window(): NULL arguments detected.\n",
			STDERR_FILENO);
		return (FALSE);
	}
	if (*mlx || *win)
	{
		ft_putstr_fd("Error\ninit_window(): Already mlx or window \
			instances are exist.\n",
			STDERR_FILENO);
		return (FALSE);
	}
	if (_validation_win_size(win_size) == FALSE)
	{
		ft_putstr_fd("Error\ninit_window(): win_size is out of range.\n",
			STDERR_FILENO);
		return (FALSE);
	}
	if (_assign_mlx_instances(mlx, win, win_size, title) == FALSE)
		return (FALSE);
	else
		return (TRUE);
}
