#include <vector>
#include <iostream>

int64_t GetCombinationsNumber(int64_t n, int64_t k) {
    int64_t answer = 1;
    for (int64_t i = 1; i <= k; ++i) {
        answer *= n - i + 1;
        answer /= i;
    }
    return answer;
}

int main() {
    std::vector<int64_t> answers(11, 1);
    answers[0] = 1;
    answers[1] = 1;
    answers[2] = 2;
    for (int n = 3; n <= 10; ++n) {
        int x = (n - 1) / 2;
        int y = n / 2;
        answers[n] = 2 * answers[n - 1] + answers[x] * answers[y] * GetCombinationsNumber(x + y, x);
    }
    std::cout << answers[4] << " " << answers[5] << " " << answers[9] << " " << answers[10] << std::endl;
    return 0;
}
