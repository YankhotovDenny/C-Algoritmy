#include <iostream>
#include <vector>
#include <array>
#include <chrono>
#include <fstream>



int main() {
	std::vector<long int> a;
	std::ofstream out;
	out.open("D:\\vector2.txt");
	if (out.is_open()) out << "edasd" << std::endl;
	for (int i = 1; i < 1001; i++)
	{
		if (true)
		{
			auto start = std::chrono::system_clock::now();
			a.push_back(i);
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end - start;
			std::cout << "elapsed time: " << elapsed_seconds.count() * pow(10, 6) << std::endl;
			if (out.is_open()) out << i << "-" << elapsed_seconds.count() * pow(10, 6) << std::endl;

		}
		else a.push_back(i);
	}
}
