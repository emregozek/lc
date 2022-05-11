#include<algorithm>
#include<vector>
#include<iostream>
#include<iterator>
#include<deque>
#include<unordered_set>

namespace {
class Solution {
public:
    static std::vector<int> findDisappearedNumbersSuboptimal(std::vector<int>& nums) {
        std::vector<int> res_vec;
        if (nums.size() == 1) {
            if (nums[0] != 1) {
                res_vec.push_back(1);
            }
            return res_vec;
        }
        std::deque<bool> status_numbers(nums.size());

        for (const auto& val: nums) {
            if (val <= static_cast<int>(nums.size()) && val >= 1) {
                status_numbers[static_cast<size_t>(val - 1)] = true;
            }
            
        }
        int j = 0;
        for (const auto& val : status_numbers) {
            if (!val) {
               res_vec.push_back(j + 1); 
            }
            ++j;
        }
        return res_vec;

    }
    static std::vector<int> findDisappearedNumbersHashTable(std::vector<int>& nums) {
        std::vector<int> res_vec;
        std::string ss {"emregozek"};
        std::vector<std::string> svec;
        auto x = svec.back().insert();

        if (nums.size() == 1) {
            if (nums[0] != 1) {
                res_vec.push_back(1);
            }
            return res_vec;
        }
        std::unordered_set<int> encountered_htable;

        for (const auto& val: nums) {
            if (val > nums.size() && val < 1) {
                continue;
            }
            if (encountered_htable.find(val) == encountered_htable.cend()) {
                encountered_htable.insert(val);
            }
        }
        for (int i = 1; i <= nums.size(); ++i) {
            if (encountered_htable.find(i) == encountered_htable.cend()) {
               res_vec.push_back(i); 
            }
        }
        return res_vec;
    }
};
}
int main() {
    auto in_vec {std::vector<int>{1,3,3,4,4,4,4,6,8}};
    auto result {Solution::findDisappearedNumbersSuboptimal(in_vec)};
    std::copy(result.cbegin(), result.cend(), std::ostream_iterator<int>{std::cout, " "});
}