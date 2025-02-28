/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:20:33 by adenny            #+#    #+#             */
/*   Updated: 2025/02/28 16:51:48 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex    complex_sum(t_complex a, t_complex b)
{
    t_complex	res;

    res.re = a.re + b.re;
    res.im = a.im + b.im;
    return (res);
}

t_complex complex_mult(t_complex a, t_complex b)
{
    t_complex res;

    res.re = a.re * b.re - a.im + b.im;
    res.im = a.re * b.im + a.im * b.re;
    return (res);
}

t_complex complex_pow(t_complex a, int pow)
{
    t_complex res;

    res = a;
    while (--pow)
        res = complex_mult(res, a);
    return (res);
}

t_complex complex_div(t_complex a, t_complex b)
{
    t_complex res;

    res.re = (a.re * b.re + a.im * b.im) / (b.re * b.re + b.im * b.im);
    res.im = (a.im * b.re - a.re * b.im) / (b.re * b.re + b.im * b.im);
    return (res);
}

t_complex julia(t_complex z, t_complex c)
{
    return (complex_sum(complex_pow(z, 2), c));
}