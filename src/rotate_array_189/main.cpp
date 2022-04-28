
#include <vector>
#include <iostream>
#include <algorithm>
class Solution {
public:
    static void rotate(std::vector<int>& nums, int k) {
        k %= nums.size();
        std::vector<int> tmp {nums.end() - k, nums.end()};
        std::copy(nums.begin(), (nums.begin() + static_cast<int>(nums.size()) - k), nums.begin() + k);
        std::copy(tmp.begin(), tmp.end(), nums.begin());
    }
    static void rotateByReversing(std::vector<int>& nums, int k) {
        k %= nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
    static void print(const std::vector<int>& nums) {
        std::cout << "test vector:\n";
        for (const auto& val : nums) {
            std::cout << val << " ";
        }
        std::cout << "\n\n";
    }
};

int main() {
    std::cout << " Hello world!\n";
    std::vector<int> test {1,3,5,7,9, 11, 13,15, 17, 19};
    Solution::print(test);

    // Solution::rotate(test, 4);
    Solution::rotateByReversing(test, 4);

    Solution::print(test);

    return 0;
}