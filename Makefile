# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 18:58:34 by jeekpark          #+#    #+#              #
#    Updated: 2023/10/30 23:56:17 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D
CC				=	cc
CFLAGS			=	#-Wall -Wextra -Werror
HEADER			=	./includes/

SRCS			=	srcs/main.c									\
					srcs/init/init_cub3d.c						\
					srcs/init/init_cub3d_parse.c				\
					srcs/init/line_validation.c					\
					srcs/init/line_validation_map.c				\
					srcs/init/line_validation_rgb.c				\
					srcs/init/line_validation_rgb_to_int.c		\
					srcs/init/line_validation_texture.c			\
					srcs/init/load_images.c						\
					srcs/init/load_images_texture.c				\
					srcs/init/map_validation.c					\
					srcs/init/map_validation_dfs.c				\
					srcs/init/map_validation_is_surround.c		\
					srcs/init/reset_terminal_interface.c		\
					srcs/hook/key_press.c						\
					srcs/hook/key_release.c						\
					srcs/hook/mouse_move.c						\
					srcs/hook/mouse_press.c						\
					srcs/hook/mouse_release.c					\
					srcs/hook/loop_hook.c						\
					srcs/hook/reset_vector.c					\
					srcs/hook/title_menu_key_press.c			\
					srcs/hook/title_menu_loop_hook.c			\
					srcs/hook/title_menu_mouse_move.c			\
					srcs/hook/title_menu_mouse_press.c			\
					srcs/render/render_mini_map.c				\
					srcs/render/render_game_scene.c				\
					srcs/render/render_game_scene_line.c		\
					srcs/render/render_game_scene_line_wall.c	\
					srcs/render/render_cross_hair.c				\
					srcs/render/render_shoot.c					\
					srcs/render/render_hand.c					\
					srcs/render/render_ammo_count.c				\
					srcs/utils/exit_game.c						\
					srcs/utils/free_split.c						\
					srcs/utils/free_game.c						\
					srcs/utils/destroy_instance.c				\
					srcs/utils_draw/draw_line_to_img.c			\
					srcs/utils_draw/draw_pixel_to_img.c			\
					srcs/utils_draw/draw_rect_to_img.c			\
					srcs/utils_draw/pipette_color_from_img.c	\
					srcs/utils_draw/set_pixel.c					\
					srcs/utils_draw/rgb8_to_int.c				\
					srcs/utils_list/list_init.c					\
					srcs/utils_list/list_push_back.c			\
					srcs/utils_list/list_del_all_node.c			\
					srcs/utils_list/list_del_one_node.c			\
					srcs/utils_image/init_component.c			\
					srcs/utils_math/add_vector.c				\
					srcs/utils_math/deg_to_rad.c				\
					srcs/utils_math/rotate_vector.c				\
					srcs/utils_math/substract_vector.c			\
					srcs/utils_math/set_vector.c				\
					srcs/utils_math/move_vector.c				\
					srcs/utils_math/distance_vector.c			\
					srcs/utils_math/map_int.c					\
					srcs/utils_math/map_double.c				\
					srcs/utils_ray_casting/ray_casting.c		\
					srcs/utils_ray_casting/init_ray_casting.c	\
					srcs/utils_mlx_general/instance_mlx.c		\
					srcs/utils_mlx_general/instance_window.c
					

OBJS			=	$(SRCS:.c=.o)

LIBFT_A			=	srcs/libft/libft.a
LIBMLX_FLAGS	=	-L. -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(MAKE) -C srcs/libft
	#make -j 1 -C srcs/mlx 2>/dev/null
	#mv ./srcs/mlx/libmlx.dylib ./libmlx.dylib
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJS) $(LIBFT_A) $(LIBMLX_FLAGS) -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean :
	$(MAKE) -C srcs/libft clean
	#$(MAKE) -C srcs/mlx clean
	rm -rf $(OBJS) 

fclean :
	$(MAKE) -C srcs/libft fclean
	#$(MAKE) -C srcs/mlx clean
	rm -rf $(OBJS) $(NAME) #./libmlx.dylib

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all re clean fclean bonus

# ----- for M1 ----------------------------------------------------------------#
CC_M1				=	arch -x86_64 cc
LIBMLX_M1_FLAGS		=	-L. -lmlx -framework OpenGL -framework Appkit
m1 :
	make CC="$(CC_M1)" LIBMLX_FLAGS="$(LIBMLX_M1_FLAGS)" all
# 제출 전 해야할 것.
# 	1. ./libmlx.dylib 삭제
# 	2. ./includes/mlx.h 삭제
# 	3. 해당 주석 파트 전체 삭제.
#	4. 작동 확인.
# -----------------------------------------------------------------------------#