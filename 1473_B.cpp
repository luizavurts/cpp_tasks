#include <iostream>
#include <string>
#include <numeric>

std::string LCM(std::string s, std::string t) {
    int size_1 = s.size();
    int size_2 = t.size();
    std::string new_string_1;
    std::string new_string_2;
    int nok = std::lcm(size_1, size_2);
    for (int i = 0; i < nok / size_1; ++i) {
        new_string_1 += s;
    }
    for (int i = 0; i < nok / size_2; ++i) {
        new_string_2 += t;
    }
    if (new_string_1 == new_string_2) {
        return new_string_1;
    }    
}

int main() {
	int q;
	std::cin >> q;
	for (int i = 0; i < q; ++i) {
		std::string s, t;
		std::cin >> s >> t;
        std::cout << LCM(s, t);
    } 
    return 0;
}
