#ifndef COOL_H 
#define COOL_H 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <tuple>
std::tuple<int, int, int, int> parse_ip_address(std::string ip_address_str); // Функция преобразования строки IP адреса в кортеж
std::vector<std::tuple<int, int, int, int>> read_ip_addresses(std::string fileName); // Функция считывания файла
void sort_ip_addresses(std::vector<std::tuple<int, int, int, int>>& ipAddresses); // Функция сортировки ip адресов

#endif