#include <iostream>
#include <unordered_set>
#include <cmath>
class Solution {
private:
    static int getNext(int n) {
        int num {};
        while (n >= 1) {
            num += static_cast<int>(std::pow((n % 10), 2));
            n /= 10;
        }
        return num;
    }
public:
    bool isHappySlow(int n) {
        if (n == 1) {
            return true;
        }
        int num {};
        std::unordered_set<int> visited;
        while (num != 1) {
            num = 0;
            while (n >= 1) {
                auto modulus = (n % 10);
                auto square = modulus * modulus;
                num += square;
                n /= 10;
            }
            if (visited.end() == visited.find(num)) {
                visited.insert(num);
            } else {
                break;
            }
            n = num;
        }
        return (num == 1);
    }
    static bool isHappy(int n) {
        if (n == 1) {
            return true;
        }
        int fast_num {getNext(n)};
        int slow_num {n};
        while (fast_num != slow_num) {
            slow_num = getNext(slow_num);
            if (auto next {getNext(fast_num)}; next != 1) {
                fast_num = getNext(next);
            } else {
                fast_num = 1;
                break;
            }
            if (fast_num == 1) {
                break;
            }
        }
        return (fast_num == 1);
    }
};

int main() {

    std::cout << "Hello world!\n";

    {
        int n {19};
        operator<<(std::cout << n << " is ", (Solution::isHappy(n) == true) ? "a happy number\n" : "not a happy number\n");
    }
}