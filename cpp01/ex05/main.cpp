#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl Harl;

    if (argc == 2)
        Harl.complain(argv[1]);
    else
        std::cout << "please introduce argument" << std::endl;
    return (0);
}