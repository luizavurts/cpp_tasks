#include <iostream>
#include <tuple>
#include <vector>

void EuclidAlgoritm(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return;
	}
	int n = a / b;
	int r = a % b;
	int x1, y1;
	EuclidAlgoritm(b, r, y1, x1);
	x = x1;
	y = y1 - n * x1;
}

std::tuple<int, int> EuclidAlgoritm(int a, int b) {
	if (b == 0) {
		return std::make_tuple(1, 0);
	}
	int n = a / b;
	int r = a % b;
	std::tuple<int, int> c = EuclidAlgoritm(b, r);
	return std::make_tuple(std::get<1>(c), std::get<0>(c) - n * std::get<1>(c));
}

std::tuple<int, int> EuclidAlgoritm2(int a, int b) {
	std::vector<int> ns;
	while (b > 0) {
		int n = a / b;
		int r = a % b;
		ns.push_back(n);
		a = b;
		b = r;
	}
	int x = 1;
	int y = 0;
	std::reverse(ns.begin(), ns.end());
	for (int n : ns) {
		int x1 = y;
		int y1 = x;
		x = x1;
		y = y1 - n * x1;
	}
	return std::make_tuple(x, y);
}

int maindjfdkjsfkd() {
	int a;
	int b;
	std::cin >> a;
	std::cin >> b;
	std::tuple<int, int> result = EuclidAlgoritm(a, b);
	std::cout << std::get<0>(result) << " " << std::get<1>(result) << std::endl;
	//int x, y;
	//EuclidAlgoritm(a, b, x, y);
	//std::cout << x << " " << y << std::endl;
	return 0;
}