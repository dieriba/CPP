# include <iostream>
# include <cctype>

int main(int argc, char **argv)
{
    size_t      i = 0, j;
    std::string phone = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

    if (argc > 1)
        while (argv[++i])
        {
            j = -1;
            while (argv[i][++j])
                argv[i][j] = islower(argv[i][j]) ? toupper(argv[i][j]) : argv[i][j];
            phone = argv[i];
            std::cout << phone << std::endl;
        }
    else
        std::cout << phone << std::endl;
}