#include "gtest/gtest.h" 
#include "ip_filter.h"

#include <vector> // Include <vector> here
#include <algorithm> // Include <algorithm> here

// Test fixture for IPv4
class IPv4Test : public ::testing::Test {};

// Test for the IPv4 constructor
TEST_F(IPv4Test, Constructor) {
    IPv4 ip("192.168.1.1");
    ASSERT_EQ(ip.n1, 192);
    ASSERT_EQ(ip.n2, 168);
    ASSERT_EQ(ip.n3, 1);
    ASSERT_EQ(ip.n4, 1);
}

// Test for the IPv4 comparison operator (operator<)
TEST_F(IPv4Test, Comparison) {
    IPv4 ip1("192.168.1.1");
    IPv4 ip2("192.168.1.2");
    ASSERT_TRUE(ip1 < ip2);
    ASSERT_FALSE(ip2 < ip1);
}

// Test for sorting IPv4 addresses
TEST_F(IPv4Test, Sorting) {
    std::vector<IPv4> ip_addresses = {
        IPv4("192.168.1.1"),
        IPv4("192.168.1.3"),
        IPv4("192.168.1.2")
    };
    
    std::sort(ip_addresses.begin(), ip_addresses.end(), [](const IPv4& lhs, const IPv4& rhs) {
        return rhs < lhs; // Reverse lexicographical order
    });
    ASSERT_EQ(ip_addresses[0].n4, 3);
    ASSERT_EQ(ip_addresses[1].n4, 2);
    ASSERT_EQ(ip_addresses[2].n4, 1);
}