#include <iostream>

int FastPower(int a, int n) {
	int x = 1;
	while (n > 0) {
		if (n % 2 == 0) {
			n = n / 2;
			a = a * a;
		}
		else {
			n = n - 1;
			x = x * a;
		}
	}
	return x;
}

int main465fvbghgdfsd() {
	int x;
	int y;
	std::cin >> x;
	std::cin >> y;
	std::cout << FastPower(x, y) << std::endl;
	return 0;
}