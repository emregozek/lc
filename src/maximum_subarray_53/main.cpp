#include <iostream>
#include <vector>

class Solution {
public:
    static int maxSubArray(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int max_sum {nums[0]};
        int cur_sum {nums[0]};
        for (std::size_t i = 1; i < nums.size(); ++i) {
            auto tmp_sum {cur_sum + nums[i]};
            cur_sum = tmp_sum > nums[i] ? tmp_sum : nums[i];
            max_sum = cur_sum > max_sum ? cur_sum : max_sum;
        }
        return max_sum;
    }
};

int main() {
    operator<<(operator<<(std::cout, "Hello"), " world!\n");

    std::vector<int> ivec = {5,4,-1,7,8};

    for (const auto& val : ivec) {
        std::cout << "val:" << val << "\n";
    }

    std::cout << "Answer: "<< Solution::maxSubArray(ivec) << "\n";

    return 0;
}