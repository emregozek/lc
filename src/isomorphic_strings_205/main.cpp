#include<algorithm>
#include<unordered_map>
#include<string>
#include<iostream>
namespace {
class Solution {
public:
    static bool isIsomorphic(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }
        std::unordered_map<char, char> iso_map;
        
        for (size_t i{}; i < s.length(); ++i) {
            if (iso_map.find(s[i]) != iso_map.end()) {
                if (iso_map[s[i]] != t[i]) {
                    return false;
                }
            } else {
                auto iter = std::find_if(iso_map.begin(), iso_map.end(), [&t, &i] (const auto& c) {
                    return c.second == t[i];
                });
                if (iter != iso_map.end()) {
                    return false;
                }
                iso_map[s[i]] = t[i];
            }
        }
        
        return true;
    }
};

int main() {
    Solution s;
    std::cout << std::boolalpha << s.isIsomorphic("add", "egg") << "\n";
}
}