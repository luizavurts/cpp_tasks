#include <vector>
#include <iostream>
#include <algorithm>

int GetLongestSubsequenceLength(const std::vector<int>& numbers) {
    std::vector<int> d(numbers.size(), 1);
    for (size_t i = 0; i < numbers.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (numbers[j] < numbers[i]) {
                d[i] = std::max(d[i], 1 + d[j]);
            }
        }
    }
    int ans = 0;
    for (size_t i = 0; i < numbers.size(); ++i) {
        ans = std::max(ans, d[i]);
    }
    return ans;
}

int main() {
    int good_tripples = 0;
    for (int x = 1; x <= 15; ++x) {
        for (int y = 1; y <= 15; ++y) {
            for (int z = 1; z <= 15; ++z) {
                if (GetLongestSubsequenceLength({1, 5, 10, 3, 15, x, y, z}) == 4) {
                    ++good_tripples;
                }
            }
        }
    }
    std::cout << good_tripples << std::endl;
    return 0;
}
