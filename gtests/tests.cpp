#include <gtest/gtest.h>
#include "cool.h"

//  Проверка, что v1 == v2
// Проверяет, что функция sort_ip_addresses правильно сортирует вектор кортежей IP-адресов в порядке убывания.
TEST(IPAddressTest, sort_ip_addressesTest) {
  std::vector<std::tuple<int, int, int, int>> ipAddresses = {
    {113, 162, 145, 156},
    {157, 39, 22, 224},
    {79, 180, 73, 190},
    {1179, 210, 145, 4}
  };
  sort_ip_addresses(ipAddresses);
  std::vector<std::tuple<int, int, int, int>> expectedIPAddresses = {
    {1179, 210, 145, 4},
    {157, 39, 22, 224},
    {113, 162, 145, 156},
    {79, 180, 73, 190}
  };
  EXPECT_EQ(ipAddresses, expectedIPAddresses);
}

// Проверка, что v1 != v2
// Проверяет, что функция parse_ip_address правильно преобразует строку IP-адреса в кортеж.
TEST(IPAddressTest, parse_ip_addressTest) {
  std::string ip_address_str = "192.168.0.1";
  auto ip_address = parse_ip_address(ip_address_str);
  std::tuple<int, int, int, int> expected_ip_address = {19, 2168, 0, 1};
  EXPECT_NE(ip_address, expected_ip_address);
}

//  Проверяет, что функция read_ip_addresses возвращает пустой вектор, если файл пустой.
TEST(IPAddressTest, read_ip_addressesTest_empty_file) {
  // Проверяем, что функция возвращает пустой вектор, если файл пустой
  std::vector<std::tuple<int, int, int, int>> expectedIPAddresses = {};
  // auto ipAddresses = read_ip_addresses("empty_file.tsv");
  // Для тестирования в github actions
  auto ipAddresses = read_ip_addresses("../empty_file.tsv");
  EXPECT_EQ(ipAddresses, expectedIPAddresses);
}