#include <iostream>
#include <string>
#include <vector>
#include<cmath>

namespace {
    
class Solution {
public:
    static int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        std::size_t size {static_cast<std::size_t>(n)};
        std::vector<int> prime_table(size);

        auto outer_bound {std::ceil(std::sqrt(size))};
        for (std::size_t i = 2; i < outer_bound; ++i) {
            if (prime_table[i] != 0) {
                continue;
            }
            for (std::size_t k = i * i; k < size; k += i) {
                prime_table[k] = 1;
            }
        }
        return static_cast<int>(std::count(prime_table.cbegin() + 2, prime_table.cend(), 0));
    }
    // static int countPrimesInefficient(int n) {
    //     if (n <= 2) {
    //         return 0;
    //     }
    //     int result {1};
    //     for (int i = 3; i < n; i += 2) {
    //         bool not_prime{};
    //         for (int j = 2; j <= (i / 2) + 1; ++j) {
    //             if ((i % j) == 0) {
    //                 not_prime = true;
    //                 break;
    //             }
    //         }
    //         if (!not_prime) {
    //             ++result;
    //         }
    //     }
    //     return result;
    // }
};

}

int main() {
    Solution s;
    std::cout << s.countPrimes(8) << "\n";
    return 0;
}