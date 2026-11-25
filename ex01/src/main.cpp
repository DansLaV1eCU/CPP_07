/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 22:08:52 by danslav1e         #+#    #+#             */
/*   Updated: 2026/11/25 22:08:53 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>
#include <string>
#include "iter.hpp"

void increment(int& i) {
    ++i;
}

void printInt(int& i) {
    std::cout << i << " ";
}

void printConstInt(const int& i) {
    std::cout << i << " ";
}

template <typename T>
void printElement(const T& elem) {
    std::cout << elem << " ";
}

int main(void) {
    int intArray[] = { 1, 2, 3, 4, 5 };
    const std::size_t intArrayLen = sizeof(intArray) / sizeof(intArray[0]);

    const int constIntArray[] = { 10, 20, 30, 40, 50 };
    const std::size_t constIntArrayLen = sizeof(constIntArray) / sizeof(constIntArray[0]);

    std::string stringArray[] = { "School", "42", "Prague" };
    const std::size_t stringArrayLen = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "--- Non-const int array (initial) ---" << std::endl;
    ::iter(intArray, intArrayLen, printInt);
    std::cout << "\n\n";

    std::cout << "--- Non-const int array (after increment, printed via const-ref) ---" << std::endl;
    ::iter(intArray, intArrayLen, increment);
    ::iter(intArray, intArrayLen, printConstInt);
    std::cout << "\n\n";

    std::cout << "--- Const int array (const-ref function & template) ---" << std::endl;
    ::iter(constIntArray, constIntArrayLen, printConstInt);
    std::cout << std::endl;
    ::iter(constIntArray, constIntArrayLen, printElement<int>);
    std::cout << "\n\n";

    std::cout << "--- String array (template function) ---" << std::endl;
    ::iter(stringArray, stringArrayLen, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}