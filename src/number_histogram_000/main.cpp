#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>

namespace {
    constexpr int decimal = 10;
class Solution {
    public:
    static std::unordered_map<int, int> histogram_numbers_for_range(int beg, int end) {
        std::unordered_map<int, int> histogram;
        if (beg >= end) {
            return histogram;
        }
        // 0 1 2 3 4 5 6 7 8 9
        // [0 - 10) => 1 (10x + 10/10)
        // [0 - 100) ==> 20 (10x + 100/10)
        // [0 - 1000) ==> 300 (10x + 1000/10)
        // [0 - 10000) ==> 4000
        std::vector<int> digit_count_vec;
        int digit_count_iter = 0;
        int find_max = 1;
        digit_count_vec.push_back(1);
        while (find_max <= end) {
            digit_count_vec.push_back((digit_count_vec.back() * 10) + (find_max / 10));
            find_max *= 10;
        }

        auto diff {end - beg};// 3526 7
        auto diff_iter {diff};
        int n_digits = 1;
        while (diff_iter >= 10) {
            ++n_digits;
            diff_iter /= 10;
        }

        if (diff < decimal) {
            std::stack<int> digits;
            auto iter_beg {beg};
            while (iter_beg >= 1) {
                digits.push(iter_beg % decimal);
                iter_beg /= decimal;
            }
            while (digits.size() > 1) {
                histogram[digits.top()] += diff;
                digits.pop();
            }
            for (int i = digits.top(); i < diff; ++i) {
                histogram[i] += 1;
            }
        }
        return histogram;
    }
};
}
// 12 18
// 12 13 14 15 16 17
// 1 ==> 
// 312 318
// 

int main() {
    Solution s;
    int beg {112};
    int end {1288};
    auto result_map {s.histogram_numbers_for_range(beg, end)};
    for (const auto& val : result_map) {
        std::cout << "[" << val.first << "]" << " = " << val.second << "\n";
    }
}