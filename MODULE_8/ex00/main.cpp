#include "./includes/easyfind.h"
#include <vector>
#include <list>

#define MAX_VAL 750
int main(int, char**)
{
	std::vector<int>	l;

	l.push_back(42);
	l.push_back(21);
	l.push_back(1337);
	l.push_back(84);
	std::vector<int>::iterator it = easyfind(l, 21);
	if (it == l.end())
		std::cout << "Can't find this element..." << std::endl;
	else
		std::cout << "Element " << *it << " found !" << std::endl;

	return 0;
}
