#include <vector>
#include <iostream>

std::vector<int> GetPrefixSums(const std::vector<int>& input_array) {
    std::vector<int> prefix_sums(input_array.size() + 1, 0);
    for (size_t i = 0; i < input_array.size(); ++i) {
        prefix_sums[i + 1] = prefix_sums[i] + input_array[i];
    }
    return prefix_sums;
}

std::vector<int> SlowGetPrefixSums(const std::vector<int>& input_array) {
    std::vector<int> prefix_sums(input_array.size() + 1, 0);
    for (size_t size_of_prefix = 0; size_of_prefix <= input_array.size(); ++size_of_prefix) {
        for (size_t i = 0; i < size_of_prefix; ++i) {
            prefix_sums[size_of_prefix] += input_array[i];
        }
    }
    return prefix_sums;
}

class IntervalSumsComputer {
public:
    IntervalSumsComputer(const std::vector<int>& input_array) : prefix_sums(GetPrefixSums(input_array)) {}


    // sum from half-interval [begin_index, end_index).
    int GetIntervalSum(size_t begin_index, size_t end_index) {
        return prefix_sums[end_index] - prefix_sums[begin_index];
    }
private:
    std::vector<int> prefix_sums;
};

class SubmatrixSumComputer {
public:
    SubmatrixSumComputer(const std::vector<std::vector<int>>& matrix)
        : prefix_sums(matrix.size() + 1, std::vector<int>(matrix[0].size() + 1, 0))
    {
        for (size_t row = 0; row < matrix.size(); ++row) {
            for (size_t col = 0; col < matrix[row].size(); ++col) {
                prefix_sums[row + 1][col + 1] = prefix_sums[row][col + 1] + prefix_sums[row + 1][col] - prefix_sums[row][col] + matrix[row][col];
            }
        }
    }

    int GetSubmatrixSum(size_t row_begin, size_t row_end, size_t col_begin, size_t col_end) {
        return prefix_sums[row_end][col_end] - prefix_sums[row_begin][col_end] - prefix_sums[row_end][col_begin] + prefix_sums[row_begin][col_begin];
    }
private:
    std::vector<std::vector<int>> prefix_sums;
};

int main() {
    std::vector<int> input_array{1, 3, 5, 10, 12};
    std::vector<int> prefix_sums = GetPrefixSums(input_array);
    for (int number : prefix_sums) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
    IntervalSumsComputer interval_sums_computer(input_array);
    std::cout << interval_sums_computer.GetIntervalSum(2, 4) << std::endl;
    std::vector<std::vector<int>> matrix{
        std::vector<int>{1, 2,  3,  4},
        std::vector<int>{5, 6,  7,  8},
        std::vector<int>{9, 10, 11, 12},
    };
    SubmatrixSumComputer submatrix_sum_computer(matrix);
    std::cout << submatrix_sum_computer.GetSubmatrixSum(1, 3, 1, 3) << std::endl;
    return 0;
}
