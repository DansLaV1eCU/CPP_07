/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:27:21 by danslav1e         #+#    #+#             */
/*   Updated: 2026/08/08 19:46:37 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>

template <typename T, typename Func>
void iter(T* arr, size_t length, Func f) {
    for (size_t i = 0; i < length; ++i) {
        f(arr[i]);
    }
}

#endif