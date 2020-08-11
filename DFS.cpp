#include <iostream>
#include <vector>
#include <queue>

void DFSPrint(int node, const std::vector<std::vector<int>>& graph, std::vector<bool>& is_visited) {
	if (is_visited[node]) {
		return;
	}
	is_visited[node] = true;
	std::cout << node << std::endl;
	for (int i : graph[node]) {
		DFSPrint(i, graph, is_visited);
	}
}

void BFSPrint(int node, const std::vector<std::vector<int>>& graph) {
	std::vector<bool> is_visited(graph.size(), false);
	std::queue<int> to_visit;
	to_visit.push(node);
	is_visited[node] = true;
	while (to_visit.size() > 0) {
		int first_node = to_visit.front();
		std::cout << first_node << std::endl;
		is_visited[first_node] = true;
		to_visit.pop();
		for (int i : graph[first_node]) {
			if (!is_visited[i]) {
				to_visit.push(i);
			}
		}
	}
}

void BFSPrintDistances(int node, const std::vector<std::vector<int>>& graph) {
	std::vector<bool> is_visited(graph.size(), false);
	std::queue<std::tuple<int, int>> to_visit;
	to_visit.push(std::make_tuple(node, 0));
	is_visited[node] = true;
	while (to_visit.size() > 0) {
		std::tuple<int, int> first_node_and_distance = to_visit.front();
		int first_node = std::get<0>(first_node_and_distance);
		int distance = std::get<1>(first_node_and_distance);
		std::cout << first_node << " : " << distance << std::endl;
		is_visited[first_node] = true;
		to_visit.pop();
		for (int i : graph[first_node]) {
			if (!is_visited[i]) {
				to_visit.push(std::make_tuple(i, distance + 1));
			}
		}
	}
}

int main() {
	int n = 5;
	std::vector<std::vector<int>> graph(n);
	// 0 -> 1
	// 1 -> 2
	// 2 -> 0
	// 2 -> 1
	// 3 -> 4
	// [[1], [2], [0, 1], [4], []] 
	graph[0].push_back(1);
	graph[1].push_back(2);
	graph[2].push_back(0);
	graph[2].push_back(1);
	graph[3].push_back(4);
	//std::vector<bool> is_visited(n, false);
	//DFSPrint(3, graph, is_visited);
	BFSPrintDistances(3, graph);
	return 0;
}