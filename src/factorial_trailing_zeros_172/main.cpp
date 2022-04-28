#include <iostream>
#include <string>
#include <cmath>

class Solution {
private:
    static constexpr long double factorial(int x) {
        long double ret_val {1};
        while (x > 0) {
            ret_val *= x--;
        }
        return ret_val;
    }
public:
    static int trailingZeroes(int n) {
        auto factorial_double {factorial(n)};
        int result {};
        while (0 == (std::fmodl(factorial_double, 10.0L))) {
            factorial_double /= 10.0L;
            ++result;
        }
        return result;
    }
    static int trailingZeroesFaster(int n) {
        int result {};
        n = n - n % 5;
        while (n >= 5) {
            auto inner {n};
            while (inner >= 5 && inner % 5 == 0) {
                inner /= 5;
                ++result;
            }
            n -= 5;
        }
        return result;
    }
    static int trailingZeroesFastest(int n) {
        int result{};
        while (n >= 5) {
            n /= 5;
            result += n;
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!\n";
    for (int i = 0; i < 500; ++i) {
        // std::cout << "Factorial of " << i << " has " << Solution::trailingZeroes(i) << " trailing zeros\n";
        // std::cout << "Factorial of " << i << " has " << Solution::trailingZeroesFaster(i) << " trailing zeros\n";
        std::cout << "Factorial of " << i << " has " << Solution::trailingZeroesFastest(i) << " trailing zeros\n";
    }
    return 0;
}
