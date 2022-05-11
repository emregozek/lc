#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
namespace {
class Solution {
public:
    static std::string reverseWords(std::string s) {
        if (s.empty()) {
            return s;
        }
        if (s.size() == 1) {
            return s;
        }
        
        //"Let's take LeetCode contest"
        auto iter {s.begin()};
        std::vector<std::string> svec;
        while (iter != s.end()) {
            svec.push_back(std::string{});
            while (iter != s.end() && *iter == ' ') {
                svec.back().append(1, ' ');
                ++iter;
            }
            if (iter == s.end()) break;
            svec.push_back(std::string{});
            while (iter != s.end() && *iter != ' ') {
                svec.back().append(1, *iter);
                ++iter;
            }
        }
        std::string result;
        result.resize(s.size());
        int i {};
        for (const std::string& str: svec) {
            if (str[0] == ' ') {
                std::copy(str.begin(), str.end(), result.begin() + i);
            } else {
                std::reverse_copy(str.begin(), str.end(), result.begin() + i);
            }
            i += str.size();
        }
        return result;
    }
    static std::string reverseWordsFaster(std::string s) {
                if (s.empty()) {
            return s;
        }
        if (s.size() == 1) {
            return s;
        }
        
        //"Let's take LeetCode contest"
        auto iter {s.begin()};
        while (iter != s.end()) {
            while (iter != s.end() && *iter == ' ') {
                ++iter;
            }
            if (iter == s.end()) {
                break;
            }
            std::size_t wstart = static_cast<std::size_t>(iter - s.begin());
            while (iter != s.end() && *iter != ' ') {
                ++iter;
            }
            std::size_t wend = static_cast<std::size_t>(iter - s.begin());
            for (std::size_t i {}; i < (wend - wstart) / 2; ++i) {
                std::swap(s[wstart + i], s[wend - i - 1]);
            }
            if (iter == s.end()) {
                break;
            }
            ++iter;
        }
        return s;
    }
    static std::string reverseWordsFasterWithStdReverse(std::string s) {
        if (s.empty()) {
            return s;
        }
        if (s.size() == 1) {
            return s;
        }
        
        //"Let's take LeetCode contest"
        auto iter {s.begin()};
        while (iter != s.end()) {
            while (iter != s.end() && *iter == ' ') {
                ++iter;
            }
            if (iter == s.end()) {
                break;
            }
            auto wstart = iter;
            while (iter != s.end() && *iter != ' ') {
                ++iter;
            }
            auto wend = iter;
            std::reverse(wstart, wend);
            if (iter == s.end()) {
                break;
            }
            ++iter;
        }
        return s;
    }

};
}
int main() {
    std::cout << Solution::reverseWords("Let's take LeetCode contest") << "\n";
    std::cout << Solution::reverseWordsFaster("Let's take LeetCode contest") << "\n";
    std::cout << Solution::reverseWordsFasterWithStdReverse("Let's take LeetCode contest") << "\n";
}