#include <vector>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        auto beg {s.begin()};
        auto end {s.end()};
        std::vector<char> left_vec;
        
        while (beg != end) {
            if (*beg == ')' || *beg == '}' || *beg == ']') {
                if (left_vec.empty()) {
                    return false;
                }
                char left_el = left_vec.back();
                left_vec.pop_back();
                if ((*beg == ')' && left_el != '(') || (*beg == '}' && left_el != '{') || (*beg == ']' && left_el != '[')) {
                    return false;
                }
            } else if (*beg == '(' || *beg == '{' || *beg == '[') {
                left_vec.push_back(*beg);
            }
            ++beg;
        }
        return left_vec.empty() ? true : false;
    }    
};