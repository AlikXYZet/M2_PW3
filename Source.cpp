#include <iostream>
#include <vector>

int main()
{
	// Инициализация вектора с последующей записью и воводом
	std::vector<int> V1;

	std::cout << "{ ";
	for (int i = 0; i < 10; i++)
	{
		V1.push_back(i);
		std::cout << V1[i];
		if (i != 9)
			std::cout << ", ";
	}
	std::cout << " }" << std::endl;



	return 0;
}