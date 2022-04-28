#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    static int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> count_map;
        for (const auto &val : nums) {
            ++count_map[val];
        }
        int max_count {};
        int max_value {};
        for (const auto &el : count_map) {
            if (el.second > max_count) {
                max_value = el.first;
                max_count = el.second;
            }
        }
        return max_value;
    }
    static int majorityElementOptimal(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        bool even_size {(nums.size() % 2) == 0 ? true : false};
        return nums[even_size ? (nums.size() / 2) : (nums.size() - 1) / 2];
    }
};

int main() {
    std::cout << "Hello world!\n";
    std::vector<int> nums {1,2,3,4,5,5,5,5,5,5,5,5,5};

    std::cout << "majorityElement = " << Solution::majorityElement(nums) << "\n";
    std::cout << "majorityElementOptimal = " << Solution::majorityElementOptimal(nums) << "\n";

    return 0;
}