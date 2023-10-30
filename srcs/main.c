/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:06:21 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/30 17:20:38 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	
	game = ft_calloc(sizeof(t_game), 1);
	if (game == NULL)
		return (EXIT_FAILURE);
	if (init_window(&game->mlx, &game->win, set_pixel(1920, 1080), "cub3D")
		== FALSE)
	{
		ft_putstr_fd("Error\ninit_window(): Returns FALSE", STDERR_FILENO);
		exit_game(game);
		return (EXIT_FAILURE);
	}
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
