#include "ip_filter.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

// Конструктор IPv4
IPv4::IPv4(const string& ip_str) {
    stringstream ss(ip_str);
    string temp;

    getline(ss, temp, '.'); 
    n1 = stoi(temp);
    getline(ss, temp, '.'); 
    n2 = stoi(temp);
    getline(ss, temp, '.'); 
    n3 = stoi(temp);
    getline(ss, temp, '.'); 
    n4 = stoi(temp);
}

// Оператор сравнения IPv4
bool operator<(const IPv4& lhs, const IPv4& rhs) {
    if (lhs.n1 != rhs.n1) {
        return lhs.n1 < rhs.n1;
    }
    if (lhs.n2 != rhs.n2) {
        return lhs.n2 < rhs.n2;
    }
    if (lhs.n3 != rhs.n3) {
        return lhs.n3 < rhs.n3;
    }
    return lhs.n4 < rhs.n4;
}

// Функция для чтения IPv4-адресов из файла
vector<IPv4> read_ip_addresses(const string& filename) {
    vector<IPv4> ip_addresses;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка открытия файла " << filename << endl;
        return ip_addresses;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string ip_str;
        getline(ss, ip_str, '\t');
        ip_addresses.push_back(IPv4(ip_str));
    }

    file.close();
    return ip_addresses;
}

// Функция для вывода списка IPv4-адресов
void print_ip_addresses(const vector<IPv4>& ip_addresses) {
    for (const auto& ip : ip_addresses) {
        cout << static_cast<int>(ip.n1) << "." << static_cast<int>(ip.n2)
             << "." << static_cast<int>(ip.n3) << "." << static_cast<int>(ip.n4)
             << endl;
    }
}

// Функция для вывода адресов с первым байтом 1
void print_addresses_with_first_byte_1(const vector<IPv4>& ip_addresses) {
    cout<<"Список адресов с первым байтом 1:"<<endl;
    for (const auto& ip : ip_addresses) {
        if (ip.n1 == 1) {
            cout << static_cast<int>(ip.n1) << "." << static_cast<int>(ip.n2)
                 << "." << static_cast<int>(ip.n3) << "." << static_cast<int>(ip.n4)
                 << endl;
        }
    }
}

// Функция для вывода адресов с первым байтом 46 и вторым 70
void print_addresses_with_first_byte_46_and_second_byte_70(const vector<IPv4>& ip_addresses) {
    cout<<"Список адресов с первым байтом 46 и вторым 70: "<<endl;
    for (const auto& ip : ip_addresses) {
        if (ip.n1 == 46 && ip.n2 == 70) {
            cout << static_cast<int>(ip.n1) << "." << static_cast<int>(ip.n2)
                 << "." << static_cast<int>(ip.n3) << "." << static_cast<int>(ip.n4)
                 << endl;
        }
    }
}

// Функция для вывода адресов, содержащих 46 в любом байте
void print_addresses_with_46_in_any_byte(const vector<IPv4>& ip_addresses) {
    cout<<"Вывод адресов, содержащих 46 в любом байте:"<<endl;
    for (const auto& ip : ip_addresses) {
        if (ip.n1 == 46 || ip.n2 == 46 || ip.n3 == 46 || ip.n4 == 46) {
            cout << static_cast<int>(ip.n1) << "." << static_cast<int>(ip.n2)
                 << "." << static_cast<int>(ip.n3) << "." << static_cast<int>(ip.n4)
                 << endl;
        }
    }
}

int main() {
    string filename = "C:\\labskazenkov\\lab2\\02\\ip_filter.tsv";
    vector<IPv4> ip_addresses = read_ip_addresses(filename);

    // Сортировка в обратном лексикографическом порядке
    sort(ip_addresses.begin(), ip_addresses.end(), [](const IPv4& lhs, const IPv4& rhs) {
        return rhs < lhs; // Обратный лексикографический порядок
    });

    // Вывод отсортированных адресов
    cout << "Отсортированные адреса:" << endl;
    print_ip_addresses(ip_addresses);

    // Вывод адресов с первым байтом 1
    print_addresses_with_first_byte_1(ip_addresses);

    // Вывод адресов с первым байтом 46 и вторым 70
    print_addresses_with_first_byte_46_and_second_byte_70(ip_addresses);

    // Вывод адресов, содержащих 46 в любом байте
    print_addresses_with_46_in_any_byte(ip_addresses);

    return 0;
}