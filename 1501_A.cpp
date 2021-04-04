#include <iostream> 
#include <vector>
int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		std::cin >> n;
		std::vector<int> a_vector;
		std::vector<int> b_vector;
		std::vector<int> m_vector;
		std::vector<int> new_time_of_arrival(n, 0);
		std::vector<int> new_time_of_departure(n, 0);
		for (int j = 0; j < n; ++j) {
			int a, b;
			std::cin >> a >> b;
			a_vector.push_back(a);
			b_vector.push_back(b);
		}
		for (int j = 0; j < n; ++j) {
			int m;
			std::cin >> m;
			m_vector.push_back(m);
		}

		new_time_of_arrival[0] = a_vector[0] + m_vector[0];
		new_time_of_departure[0] = new_time_of_arrival[0] + (b_vector[0] - a_vector[0]) / 2 + 1;
		for (int j = 1; j < a_vector.size(); ++j) {
			new_time_of_arrival[j] = new_time_of_departure[j - 1] + m_vector[j] + a_vector[j] - b_vector[j - 1];
			new_time_of_departure[j] = new_time_of_arrival[j] + (b_vector[j] - a_vector[j]) / 2 + 1;
		}
		std::cout << new_time_of_arrival[n - 1] << std::endl;
	}
	return 0;
}
