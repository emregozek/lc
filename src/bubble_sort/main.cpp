#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

std::vector<int> sort_list(std::vector<int> unsorted_list) {
    bool swapped{true};
    std::size_t i {};
    while (swapped && i < (unsorted_list.size() - 1)) {
        swapped = false;
        for (std::size_t j {}; j < unsorted_list.size() - i - 1; ++j) {
            if (unsorted_list[j] > unsorted_list[j + 1]) {
                auto tmp = unsorted_list[j];
                unsorted_list[j] = unsorted_list[j + 1];
                unsorted_list[j + 1] = tmp;
                swapped = true;
            }
        }
        ++i;
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
