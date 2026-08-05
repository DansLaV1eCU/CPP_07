/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:25:53 by danslav1e         #+#    #+#             */
/*   Updated: 2026/07/15 17:29:45 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

// 1. Standard function
void printInt( int& i ) {
    std::cout << i << " ";
}

// 2. Standard function handling const
void printConstInt( const int& i ) {
    std::cout << i << " ";
}

// 3. Template function
template <typename T>
void printElement( T& elem ) {
    std::cout << elem << " ";
}

int main( void ) {
    // Test Data
    int intArray[] = { 1, 2, 3, 4, 5 };
    size_t intArrayLen = sizeof(intArray) / sizeof(intArray[0]);

    const int constIntArray[] = { 42, 42, 42 };
    size_t constIntArrayLen = sizeof(constIntArray) / sizeof(constIntArray[0]);

    std::string stringArray[] = { "School", "42", "Prague" };
    size_t stringArrayLen = sizeof(stringArray) / sizeof(stringArray[0]);

    // Test 1: Integer array with standard function
    std::cout << "--- Integer Array (Standard Function) ---" << std::endl;
    ::iter(intArray, intArrayLen, printInt);
    std::cout << "\n\n";

    // Test 2: Const integer array with standard const function
    std::cout << "--- Const Integer Array (Standard Const Function) ---" << std::endl;
    ::iter(constIntArray, constIntArrayLen, printConstInt);
    std::cout << "\n\n";

    // Test 3: String array with template function
    std::cout << "--- String Array (Template Function) ---" << std::endl;
    // Notice we must explicitly instantiate the template function printElement<std::string>
    ::iter(stringArray, stringArrayLen, printElement<std::string>);
    std::cout << std::endl;

    return (0);
}