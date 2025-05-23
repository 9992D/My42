/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:55:52 by adenny            #+#    #+#             */
/*   Updated: 2025/03/02 15:00:03 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(argc, argv) 
{
    if ((argc == 2 && argv[1] == "Mandelbrot") || (argc == 4 && argv[1] == "Julia"))
    {
        return 0;
    }
    else
        write(1, "Usage: ./fractol [Mandelbrot] or [Julia]\n", 42);
}