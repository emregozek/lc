#include <vector>
#include <iostream>

class Solution {
    // std::vector<int> nodes;
    // int robFrom(std::vector<int>& nums, int i) {
    //     if (i >= nums.size()) {
    //         return 0;
    //     }
    //     if (nodes[i] != -1) {
    //         return nodes[i];
    //     }
    //     nodes[i] = std::max(nums[i] + robFrom(nums, i + 2), robFrom(nums, i + 1));
    //     return nodes[i];
    // }
public:
    // int rob(std::vector<int>& nums) {
    //     nodes.resize(nums.size(), 0);
    //     return robFrom(nums, -1);
    // }
    // int robNonRecursive(std::vector<int>& nums) {
    //     if (nums.size() == 0) {
    //         return 0;
    //     }

    //     nodes.resize(nums.size() + 1);
    //     nodes[nums.size()] = 0;
    //     nodes[nums.size() - 1] = nums[nums.size() - 1];

    //     for (int i = nums.size() - 2; i >= 0 ; --i) {
    //         nodes[i] = std::max(nums[i] + nodes[i + 2], nodes[i + 1]);
    //     }
    //     return nodes[0];
    // }
    int robNonRecursiveLowMemory(std::vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int robNext = 0;
        int robCurrent = nums[nums.size() - 1];
        for (std::size_t i = nums.size() - 2; i >= 0 ; --i) {
            auto current = std::max(nums[i] + robNext, robCurrent);
            robNext = robCurrent;
            robCurrent = current;
        }
        return robCurrent;
    }
};

int main() {
    Solution solution;
    std::cout << "Hello\n";
    std::vector<int> test {114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188,67,205,94,205,169,241,202,144,240};
    // std::vector<int> test {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // std::vector<int> test {1,2,2,2,1};
    // std::cout << "result = " << solution.rob(test) << "\n";
    // std::cout << "result = " << solution.robNonRecursive(test) << "\n";
    std::cout << "result = " << solution.robNonRecursiveLowMemory(test) << "\n";
    return 0;
}