#include <iostream>
#include <string>

int NOD(int n1, int n2)
{
    int div;
    if (n1 == n2)  return n1;
    int d = n1 - n2;
    if (d < 0) {
        d = -d;  div = NOD(n1, d);
    }
    else
        div = NOD(n2, d);
    return div;
}

int NOK(int n1, int n2)
{
    return n1 * n2 / NOD(n1, n2);
}

bool LCM(std::string s, std::string t) {
    int size_1 = s.size();
    int size_2 = t.size();
    std::string new_string_1;
    std::string new_string_2;
    int nok = NOK(size_1, size_2);
    for (int i = 0; i < nok / size_1; ++i) {
        new_string_1 += s;
    }
    for (int i = 0; i < nok / size_2; ++i) {
        new_string_2 += t;
    }
    int k = 0;
    for (int i = 0; i < new_string_1.size(); ++i) {
        if (new_string_1[i] == new_string_2[i]) {
            k += 1;
        }
    }
    if (k == nok) {
        return true;
    }
}

std::string string(std::string s, std::string t) {
        int size_1 = s.size();
        int size_2 = t.size();
        std::string new_string;
        for (int i = 0; i < (NOK(size_1, size_2) / size_2); ++i) {
            new_string += t;
        }
        return new_string;
}

int main() {
	int q;
	std::cin >> q;
	for (int i = 0; i < q; ++i) {
		std::string s, t;
		std::cin >> s >> t;
        if (LCM(s, t) == true) {
            std::cout << string(s, t) << std::endl;
        }
        else {
            std::cout << -1 << std::endl;
        }
    } 
    return 0;
}