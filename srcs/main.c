/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:06:21 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/30 20:57:35 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	
	game = ft_calloc(sizeof(t_game), 1);
	if (game == NULL)
		return (EXIT_FAILURE);
	if (instance_mlx(&game->mlx) == FALSE)
	{
		ft_putendl_fd("Error\ninstance_mlx(): Failed\n", STDERR_FILENO);
		exit_game(game);
		free(game);
		return (EXIT_FAILURE);
	}
	if (instance_window(&game->win, game->mlx, set_pixel(1920, 1080), "cub3D")
		== FALSE)
	{
		ft_putstr_fd("Error\ninstance_window(): Failed", STDERR_FILENO);
		exit_game(game);
		free(game);
		return (EXIT_FAILURE);
	}

	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
