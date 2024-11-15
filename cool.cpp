#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <tuple>
// Функция преобразования строки IP адреса в кортеж
std::tuple<int, int, int, int> parse_ip_address(std::string ip_address_str) {
    // Разделение ip адреса на отдельные числа
    std::istringstream ip_stream(ip_address_str);
    
    int n1, n2, n3, n4;
    std::getline(ip_stream, ip_address_str, '.');
    n1 = std::stoi(ip_address_str);
    std::getline(ip_stream, ip_address_str, '.');
    n2 = std::stoi(ip_address_str);
    std::getline(ip_stream, ip_address_str, '.');
    n3 = std::stoi(ip_address_str);
    std::getline(ip_stream, ip_address_str, '.');
    n4 = std::stoi(ip_address_str);

    return std::make_tuple(n1, n2, n3, n4);
}

// Функция считывания файла 
std::vector<std::tuple<int, int, int, int>> read_ip_addresses(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << L"Ошибка открытия файла!" << std::endl;
        return {}; // Возвращаем пустой вектор в случае ошибки
    }

    std::vector<std::tuple<int, int, int, int>> ip_addresses; // Вектор с ip адресами

    // Считывание строк из файла 
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string text1, text2, text3;
        std::getline(iss, text1, '\t'); // Получаем IP адрес из строки
        std::getline(iss, text2, '\t');
        std::getline(iss, text3, '\t');

        // Преобразование строки в кортеж IP адреса
        auto ip_address = parse_ip_address(text1);

        // Добавление кортежа в вектор с ip адресами
        ip_addresses.push_back(ip_address);
    }

    // Закрываем файл
    file.close();

    return ip_addresses;
}

// Функция сортировки ip адресов
void sort_ip_addresses(std::vector<std::tuple<int, int, int, int>>& ip_addresses) {
    std::sort(ip_addresses.begin(), ip_addresses.end(), [](const auto& ip1, const auto& ip2) 
    {
        // Сравнение кортежей по порядку: n1, n2, n3, n4
        if (std::get<0>(ip1) != std::get<0>(ip2)) {
            return std::get<0>(ip1) > std::get<0>(ip2);
        } else if (std::get<1>(ip1) != std::get<1>(ip2)) {
            return std::get<1>(ip1) > std::get<1>(ip2);
        } else if (std::get<2>(ip1) != std::get<2>(ip2)) {
            return std::get<2>(ip1) > std::get<2>(ip2);
        } else {
            return std::get<3>(ip1) > std::get<3>(ip2);
        }
    });
}