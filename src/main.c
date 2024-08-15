/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:48:52 by dcingoz           #+#    #+#             */
/*   Updated: 2024/08/15 16:50:39 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"
#include <mlx.h>

int main(void)
{
    void *mlx;        // Pointer to the MLX instance
    void *win;        // Pointer to the window

    mlx = mlx_init();
    if (mlx == NULL) {
        return EXIT_FAILURE; // Initialization failed
    }
    win = mlx_new_window(mlx, 800, 600, "My Window");
    if (win == NULL) {
        free(mlx); // Clean up if window creation fails
        return EXIT_FAILURE;
    }
    mlx_loop(mlx);

    return EXIT_SUCCESS;
}