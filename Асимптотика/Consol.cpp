#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <list>



int main() {
	std::list<short int> head;
	std::vector<short int> head1;
	std::ofstream out;
	out.open("D:\\h.txt");
	if (out.is_open()) out << "edasd" << std::endl;
	for (int i = 1; i < 1000000000; i++)
	{
		out << i << std::endl;
	}
}