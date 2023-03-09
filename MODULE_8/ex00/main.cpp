#include "./includes/easyfind.h"
#include <vector>
#include <list>

#define MAX_VAL 750
int main(int, char**)
{
	std::vector<int> vec;
	std::vector<int>::iterator iterator;
	int to_find = 10;

	vec.push_back(10);
	vec.push_back(12);

	iterator = easyfind(vec, to_find);
	if (iterator != vec.end())
		std::cout << "Number: " << (*iterator) << " Found !" << std::endl;
	else
		std::cout << "The number " << to_find << " was not found !" << std::endl; 
	return 0;
}
