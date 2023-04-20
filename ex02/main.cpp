# include "./includes/PmergeMe.hpp"

int main (int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << "Missing Argument" << std::endl;
        return 1;
    }
    
    try
    {
        PmergeMe merger;
        merger.setBeginVecTime();
        for (int i = 1; i < argc; i++)
            merger.addToVector(argv[i]);
        merger.PmergeContainers();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}