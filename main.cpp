#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <tuple>
#include "cool.h"

int main() {
    std::vector<std::tuple<int, int, int, int>> ipAddresses = read_ip_addresses("D:\\univer\\Laba2\\ip_filter.tsv");

    sort_ip_addresses(ipAddresses);

    // Задание 1: Вывод отсортированного списка
    std::cout << "Задание 1: Отсортированный список" << std::endl;
    for (const auto& ip : ipAddresses) {
        std::cout << std::get<0>(ip) << "." << std::get<1>(ip) << "." << std::get<2>(ip) << "." << std::get<3>(ip) << std::endl;   
    }
    std::cout  << std::endl;  

    // Задание 2: Вывод отсортированного списка адресов, первый байт которых равен 1
    std::cout << "Задание 2: Адреса с первым байтом 1" << std::endl;
    for (const auto& ip : ipAddresses) {
        if (std::get<0>(ip) == 1) {
            std::cout << std::get<0>(ip) << "." << std::get<1>(ip) << "." << std::get<2>(ip) << "." << std::get<3>(ip) << std::endl;
        }
    }
    std::cout  << std::endl; 


    // Задание 3: Вывод отсортированного списка адресов, первый байт которых равен 46, а второй – 70
    std::cout << "Задание 3: Адреса с первым байтом 46 и вторым 70" << std::endl;
    for (const auto& ip : ipAddresses) {
        if ((std::get<0>(ip) == 46) && (std::get<1>(ip) == 70)) {

            std::cout << std::get<0>(ip) << "." << std::get<1>(ip) << "." << std::get<2>(ip) << "." << std::get<3>(ip) << std::endl;
        }
    }
    std::cout  << std::endl; 
    
    // Задание 4: Вывод отсортированного списка адресов, любой байт которых равен 46
    std::cout << "Задание 4: Адреса с байтом 46" << std::endl;
    for (const auto& ip : ipAddresses) {
        if ((std::get<0>(ip) == 46) || (std::get<1>(ip) == 46) || (std::get<2>(ip) == 46) || (std::get<3>(ip) == 46))
        {
            std::cout << std::get<0>(ip) << "." << std::get<1>(ip) << "." << std::get<2>(ip) << "." << std::get<3>(ip) << std::endl;
        }
    }

    return 0;
}