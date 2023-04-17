# include "./includes/PmergeMe.hpp"

int main (int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << "Missing Argument" << std::endl;
        return 1;
    }
    
    if (argc == 2)
    {
        int val;
        std::string s(argv[1]);
        std::stringstream ss(argv[1]);

        ss >> val;
        if (s.find_first_not_of(BASE) != std::string::npos || ss.fail())
        {
            std::cerr << "Error\n";
            return 1;
        }
        std::cout << "Argument is already sorted\n";
    }
    else
    {
        try
        {
            PmergeMe merger;

            for (int i = 1; i < argc; i++)
                merger.addToContainers(argv[i]);

            merger.BeforeMerge();
            merger.PmergeContainers();
            std::cout << "After: " << merger.getVector();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}