#include <iostream>

class Matrix22 {
public:
	Matrix22(): a(1), b(0), c(0), d(1) {}

	Matrix22(int x, int y, int z, int u): a(x), b(y), c(z), d(u) {}

	Matrix22 operator*(const Matrix22& x) {
		Matrix22 y;
		y.a = a * x.a + b * x.c;
		y.b = a * x.b + b * x.d;
		y.c = c * x.a + d * x.c;
		y.d = c * x.b + d * x.d;
		return y;
	}

	int Get12() {
		return b;
	}
private:
	int a;
	int b;
	int c;
	int d;
};

Matrix22 FastPower(Matrix22 a, int n) {
	Matrix22 x;
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

int GetFibonacci(int index) {
	Matrix22 f(1, 1, 1, 0);
	Matrix22 t = FastPower(f, index);
    return t.Get12();
}


int main() {
	int a;
	std::cin >> a;
	std::cout << GetFibonacci(a);
	return 0;
}