#include <iostream>
#include <vector>
#include <array>

class Solution {
public:
    static constexpr int m = 5;
    // static constexpr int m = 0;
    static constexpr int n = 5;
    // static constexpr int n = 0;
    inline static std::array<int, m> num1_arr = {1,3,4,10,20};
    // inline static std::array<int, m> num1_arr = {};
    inline static std::array<int, n> num2_arr = {2,5,6,15,28};
    // inline static std::array<int, n> num2_arr = {};

    static void merge(std::vector<int>& nums1, std::size_t mx, std::vector<int>& nums2, std::size_t nx) {
        if (nx == 0) {
            return;
        } else if (mx == 0) {
            nums1.assign(nums2.begin(), nums2.end());
            return;
        }

        for (std::size_t i = 0, j = 0, k = 0; i < nums1.size(); ++i) {
            if (j < mx && k < nx) {
                if (nums1[i] <= nums2[k]) {
                    ++j;
                } else {
                    nums1.insert(nums1.begin() + static_cast<long>(i), nums2[k++]);
                    nums1.pop_back();
                }
            } else if (j == mx && k < nx) {
                nums1.insert(nums1.begin() + static_cast<long>(i), nums2[k++]);
                nums1.pop_back();
            } else if (j < mx && k == nx) {
                ++j;
            }
        }
    }
    static void reverse_merge(std::vector<int>& nums1, std::size_t my, std::vector<int>& nums2, std::size_t ny) {
        if (ny == 0) {
            return;
        } else if (my == 0) {
            nums1.assign(nums2.begin(), nums2.end());
            return;
        }

        for (std::size_t i = nums1.size() - 1, j = my - 1, k = ny - 1; i >= 0; --i) {
            if ((j >= 0 && nums1[j] > nums2[k])) {
                nums1[i] = nums1[j--];
            } else {
                nums1[i] = nums2[k--];
            }
        }
    }
};

int main() {

    std::vector<int> nums1 {std::begin(Solution::num1_arr), std::end(Solution::num1_arr)};
    std::vector<int> nums2 {std::begin(Solution::num2_arr), std::end(Solution::num2_arr)};
    nums1.insert(nums1.end(), nums2.size(), 0);
    
    std::cout << "BEFORE merge\n";
    std::cout << "nums1\n";
    for (const auto& val : nums1) {
        operator<<(operator<<(std::cout, "val: ").operator<<(val), " ");
    }
    std::cout << "\n\n";

    std::cout << "nums2\n";
    for (const auto& val : nums2) {
        operator<<(operator<<(std::cout, "val: ").operator<<(val), " ");
    }
    std::cout << "\n\n";

    Solution::reverse_merge(nums1, Solution::m, nums2, Solution::n);

    std::cout << "AFTER merge\n";

    std::cout << "nums1\n";
    for (const auto& val : nums1) {
        operator<<(operator<<(std::cout, "val: ").operator<<(val), " ");
    }
    std::cout << "\n\n";
    std::cout << "nums2\n";
    for (const auto& val : nums2) {
        operator<<(operator<<(std::cout, "val: ").operator<<(val), " ");
    }

    
    return 0;
}