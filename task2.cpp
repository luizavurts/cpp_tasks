#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

int main() {
    std::string number;
    std::cin >> number;
    std::vector<int> digits(number.size());
    for (size_t i = 0; i < number.size(); ++i) {
        digits[i] = number[i] - '0';
    }
    std::vector<int> prefix_minimums(digits.size() + 1, std::numeric_limits<int>::max());
    prefix_minimums[0] = 0;
    prefix_minimums[1] = digits[0];
    for (size_t prefix_end = 2; prefix_end < digits.size() + 1; ++prefix_end) {
        for (size_t previous_prefix_end = 0; previous_prefix_end < prefix_end; ++previous_prefix_end) {
            int new_summand = 1;
            for (size_t i = previous_prefix_end; i < prefix_end; ++i) {
                new_summand *= digits[i];
                if (new_summand > 100000) {
                    break;
                }
            }
            if (new_summand > 100000) {
                continue;
            }
            prefix_minimums[prefix_end] = std::min(prefix_minimums[prefix_end], prefix_minimums[previous_prefix_end] + new_summand);
        }
    }
    std::cout << prefix_minimums[digits.size()] << std::endl;
	return 0;
}
