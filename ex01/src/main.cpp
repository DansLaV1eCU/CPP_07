/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:25:53 by danslav1e         #+#    #+#             */
/*   Updated: 2026/08/08 19:41:48 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

void printInt( int& i ) {
    std::cout << i << " ";
}

void printConstInt( const int& i ) {
    std::cout << i << " ";
}

template <typename T>
void printElement( T& elem ) {
    std::cout << elem << " ";
}

int main( void ) {
    int intArray[] = { 1, 2, 3, 4, 5 };
    size_t intArrayLen = sizeof(intArray) / sizeof(intArray[0]);

    const int constIntArray[] = { 42, 42, 42 };
    size_t constIntArrayLen = sizeof(constIntArray) / sizeof(constIntArray[0]);

    std::string stringArray[] = { "School", "42", "Prague" };
    size_t stringArrayLen = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "--- Integer Array (Standard Function) ---" << std::endl;
    ::iter(intArray, intArrayLen, printInt);
    std::cout << "\n\n";

    std::cout << "--- Const Integer Array (Standard Const Function) ---" << std::endl;
    ::iter(constIntArray, constIntArrayLen, printConstInt);
    std::cout << "\n\n";

    std::cout << "--- String Array (Template Function) ---" << std::endl;

    ::iter(stringArray, stringArrayLen, printElement<std::string>);
    std::cout << std::endl;

    return (0);
}