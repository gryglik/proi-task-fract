#include "fract.h"
#include <iostream>


int main()
{
    {
        fract f(1, 3);
        if (f.num() != 1 || f.denom() != 3)
            std::cerr << "Error in values after fract(1, 3) ctor\n";
        f.print(std::cout);
        std::cout << std::endl;
    }

    {
        fract f(2, 4);
        if (f.num() != 1 || f.denom() != 2)
            std::cerr << "Error in values after fract(2, 4) ctor\n";
        f.print(std::cout);
        std::cout << std::endl;
    }

    {
        fract f(0, 500);
        if (f.num() != 0 || f.denom() != 1)
            std::cerr << "Error in values after fract(0, 1) ctor\n";
        f.print(std::cout);
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return 0;
}