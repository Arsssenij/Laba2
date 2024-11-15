#ifndef IP_FILTER_H
#define IP_FILTER_H

#include <string>
#include <vector>

// Структура для представления IPv4-адреса
struct IPv4 {
    unsigned char n1, n2, n3, n4;

    // Конструктор, инициализирующий поля из строки
    IPv4(const std::string& ip_str);
};

// Оператор сравнения для сортировки в обратном лексикографическом порядке
bool operator<(const IPv4& lhs, const IPv4& rhs);

// Функция для чтения IPv4-адресов из файла
std::vector<IPv4> read_ip_addresses(const std::string& filename);

// Функция для вывода списка IPv4-адресов
void print_ip_addresses(const std::vector<IPv4>& ip_addresses);

// Функция для вывода адресов с первым байтом 1
void print_addresses_with_first_byte_1(const std::vector<IPv4>& ip_addresses);

// Функция для вывода адресов с первым байтом 46 и вторым 70
void print_addresses_with_first_byte_46_and_second_byte_70(const std::vector<IPv4>& ip_addresses);

// Функция для вывода адресов, содержащих 46 в любом байте
void print_addresses_with_46_in_any_byte(const std::vector<IPv4>& ip_addresses);

#endif // IP_FILTER_H