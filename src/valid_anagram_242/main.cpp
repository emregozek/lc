#include<iostream>
#include<unordered_map>
#include<string>

namespace {

class Solution {
    public:
//     static bool isAnagramBruteForce(string s, string t) {
//         if (s.length() != t.length()) {
//             return false;
//         }
//         std::sort(s.begin(), s.end());
//         std::sort(t.begin(), t.end());
        
//         if (s == t) {
//             return true;
//         } else {
//             return false;
//         }
//     }

    static bool isAnagram(const std::string& s, const std::string& t) {
        if (s.length() != t.length()) {
            return false;
        }
        std::unordered_map<char, int> histogram;
        for (const auto& cs : s) {
            ++histogram[cs];
        }
        for (const auto& ct : t) {
            if (histogram[ct] == 0) {
                return false;
            }
            --histogram[ct];
        }
        return true;
    }
};

}

int main() {
    Solution s;
    std::cout << std::boolalpha<< s.isAnagram("emre", "emme") << "\n";
}