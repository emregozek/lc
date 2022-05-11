#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<algorithm>
#include<cmath>
#include<iterator>
#include<chrono>

namespace {

class Profiling {
    private:
        std::chrono::system_clock::time_point m_start;
    public:
        Profiling() : m_start{std::chrono::high_resolution_clock::now()} {}
        ~Profiling() {
            std::cout << "Took " << std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - m_start).count() << " ms\n";
        }
};
class Solution {
    constexpr static inline int dec_max = 10;
    public:
    static std::vector<int> digit_hist_in_range(int beg, int end) {
        Profiling p{};
        std::vector<int> histogram(dec_max);
        if (beg >= end) {
            return histogram;
        }
        if (beg < 0) {
            std::cout << "negative numbers not supported\n";
            return histogram;
        }

        std::vector<int> digit_count_vec;
        long int find_max = 1;
        digit_count_vec.push_back(1);
        auto diff_it {end - beg};
        int n_digits_diff = 1;
        while (diff_it >= dec_max) {
            ++n_digits_diff;
            diff_it /= dec_max;
            find_max *= dec_max;
            digit_count_vec.push_back((digit_count_vec.back() * dec_max) + static_cast<int>(find_max));
        }

        auto remaining_diff {end - beg};
        auto cur_end {end};
        for (int i = n_digits_diff; i > 0; --i) {
            auto diff_step = static_cast<int>(std::pow(dec_max, i - 1));
            int diff_step_cnt = remaining_diff / diff_step;
            if (!diff_step_cnt) {
                continue;
            }
            int cur_end_mod = cur_end % diff_step;
            int cur_process = diff_step * diff_step_cnt;

            auto higher_digits_min = (cur_end - cur_end_mod - cur_process) / diff_step;

            if (i > 1) {
                auto to_be_added = diff_step_cnt * digit_count_vec[static_cast<std::size_t>(i - 2)];
                std::for_each(histogram.begin(), histogram.end(), [to_be_added](auto &el) { el += to_be_added;});
            }

            int processing_phase{};
            while (diff_step_cnt >= 0) {
                auto higher_digits_iter {higher_digits_min + diff_step_cnt};
                auto incr_val = processing_phase == 0 ? cur_end_mod : processing_phase == 1 ? diff_step : (diff_step - cur_end_mod);
                while (higher_digits_iter >= 1) {
                    auto idx = static_cast<std::size_t>(higher_digits_iter % 10);
                    histogram[idx] += incr_val;
                    higher_digits_iter /= 10;     
                }
                --diff_step_cnt;
                if (processing_phase == 0) {
                    ++processing_phase;
                } else if (processing_phase == 1 && diff_step_cnt == 0) {
                    ++processing_phase;
                }
            }
            remaining_diff -= cur_process;
            cur_end -= cur_process;
        }
        return histogram;
    }

    static std::vector<int> digit_hist_in_range_brute_force(int beg, int end) {
        Profiling p{};
        std::vector<int> histogram(10);
        if (beg >= end) {
            return histogram;
        }
        if (beg < 0) {
            std::cout << "negative numbers not supported\n";
            return histogram;
        }
        for (auto i = beg; i < end; ++i) {
            auto iter {i};
            while (iter >= dec_max) {
                histogram[static_cast<std::size_t>(iter % dec_max)] += 1;
                iter /= dec_max;
            }
            histogram[static_cast<std::size_t>(iter % dec_max)] += 1;
        }
        return histogram;
    }
};
}


int main() {

    int beg {120};
    int end {96665633};

    auto result {Solution::digit_hist_in_range(beg, end)};
    std::copy(result.cbegin(), result.cend(), std::ostream_iterator<int>{std::cout, "\n"});

    auto result_brute_force {Solution::digit_hist_in_range_brute_force(beg, end)};
    std::copy(result_brute_force.cbegin(), result_brute_force.cend(), std::ostream_iterator<int>{std::cout, "\n"});
}