#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

std::vector<int> sort_list(std::vector<int> unsorted_list) {
    
    auto outer_iter {unsorted_list.begin()};
    while (outer_iter != unsorted_list.end()) {
        auto inner_iter = outer_iter;
        auto local_min = outer_iter;
        while (inner_iter != unsorted_list.end()) {
            local_min = *local_min < *inner_iter ? local_min : inner_iter;
            std::advance(inner_iter, 1);
        }
        if (*outer_iter != *local_min) {
            auto tmp = *local_min;
            *local_min = *outer_iter;
            *outer_iter = tmp;
        }
        std::advance(outer_iter, 1);
    }
    
    return unsorted_list;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> unsorted_list = get_words<int>();
    std::vector<int> res = sort_list(unsorted_list);
    put_words(res);
}
