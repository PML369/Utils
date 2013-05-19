#include <Utils\utils\utils.h>
#include <iostream>
#include <vector>
#include <fstream>

int main()
{
	if (utils::FileExists("D:\\cfg.txt"))
	{
		std::cout << "Exists" << std::endl;
	}
	std::cout << utils::int_to_hex<int>(utils::GetIntVal("254000")) << std::endl;
	std::vector<int> x;
	x.push_back(5);
	x.push_back(3);
	utils::PrintVector<int>(std::cout,x,"\n");
	system("pause");
	return 0;
}