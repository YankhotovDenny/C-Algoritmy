#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <list>
#include <cstdlib>

//RAND_MAX = 100;

std::vector<int> Rykzak(int n, std::vector<int> value, std::vector<int> head) {
	int a = 0;
	std::list<int> h;
	for (int i = 1; i < 4; i++)
	{
		if (n - i >= 0)
		{
			a = head[n - i] + value[i];
		}
		else a = 0;
		h.push_back(a);
	}
	a = h.front();
	for (auto it = h.begin(); it != h.end(); ++it)
		if (a < *it) a = *it;
	head[n] = a;
	return head;

}

int main() {
	std::vector<int> head;
	std::vector<int> value;
	for (int i = 0; i < 4; i++)
	{
		value.push_back(i * i);
	}
	for (int i = 0; i < 31; i++)
	{
		head.push_back(0);
	}
	for (int i = 1; i < 31; i++)
	{
		head = Rykzak(i, value, head);
	}
	for (int i = 0; i < 31; i++)
	{
		std::cout << head[i] << '\n';
	}
}