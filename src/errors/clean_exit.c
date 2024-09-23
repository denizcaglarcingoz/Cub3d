/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:04:27 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 16:05:15 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

static void	free_textures(t_all *data)
{
	if (data->tex_no.img)
	{
		mlx_destroy_image(data->libx.mlx, data->tex_no.img);
		data->tex_no.img = NULL;
	}
	if (data->tex_so.img)
	{
		mlx_destroy_image(data->libx.mlx, data->tex_so.img);
		data->tex_so.img = NULL;
	}
	if (data->tex_we.img)
	{
		mlx_destroy_image(data->libx.mlx, data->tex_we.img);
		data->tex_we.img = NULL;
	}
	if (data->tex_ea.img)
	{
		mlx_destroy_image(data->libx.mlx, data->tex_ea.img);
		data->tex_ea.img = NULL;
	}
}

int	ft_exit(t_all *data)
{
	clean_exit(data, 0);
	return (0);
}

void	clean_exit(t_all *data, int checker)
{
	if (data == NULL)
		exit(0);
	if (data->libx.img)
	{
		mlx_destroy_image(data->libx.mlx, data->libx.img);
		data->libx.img = NULL;
	}
	inp_data_free(&data->inp);
	free_textures(data);
	mlx_destroy_window(data->libx.mlx, data->libx.win);
	if (data->libx.mlx)
	{
		mlx_destroy_display(data->libx.mlx);
		if (data->libx.mlx)
			free(data->libx.mlx);
	}
	if (data->libx.auto_key)
		XCloseDisplay(data->libx.auto_key);
	if (checker == 1)
		malloc_error();
	exit(0);
}
