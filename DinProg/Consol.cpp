#include <iostream>
#include <vector>
#include <list>

std::vector<int> Rykzak(int n, std::vector<int> weight, std::vector<int> value, std::vector<int> head, int qu) {
	int a = 0;
	std::list<int> h;
	for (int i = 0; i < qu; ++i) {
		if (n - weight[i]>= 0) {
			a = head[n - weight[i]] + value[i];
		}
		else a = 0;
		h.push_back(a);
	}
	a = h.front();
	for (auto it = h.begin(); it != h.end(); ++it) if (a < *it) a = *it;
	head[n] = a;
	return head;
}

int main() {
	std::vector<int> head;
	std::vector<int> value, weight;
	int n, z;
	std::cout << "Введите кол-во предметов: ";
	std::cin >> n;
	std::cout << "Введите вес элементов по индексам: ";
	std::cout << std::endl;
	for (int i = 0; i < n; ++i) {
		std::cout << i+1 << ": ";
		std::cin >> z;
		weight.push_back(z);
	}
	std::cout << std::endl;
	std::cout << "Введите вес элементов по индексам: ";
	std::cout << std::endl;
	for (int i = 0; i < n; ++i) {
		std::cout << i+1 << ": ";
		std::cin >> z;
		value.push_back(z);
	}
	std::cout << std::endl;
	std::cout << "Введите размер рюкзака: ";
	std::cin >> z;
	++z;
	std::cout << std::endl;
	for (int i = 0; i < z; ++i) {
		head.push_back(0);
	}
	for (int i = 1; i < z; ++i) {
		head = Rykzak(i, weight, value, head, n);
	}
	for (int i = 1; i < z; ++i) {
		std::cout << i << " у.в. - " << head[i] << '\n';
	}
}
