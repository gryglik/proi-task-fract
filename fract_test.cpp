#include "fract.h"
#include <iostream>


int main()
{
    {
        fract f;
        if(f.num() != 0 || f.denom() != 1)
            std::cerr << "Error in values after default ctor\n";
    }

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
        fract f(-3, 9);
        if (f.num() != -1 || f.denom() != 3)
            std::cerr << "Error in values after fract(-3, 9) ctor\n";
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

    {
        fract f1(1, 2);
        fract f2(4, 8);
        if (!f1.equal(f2))
            std::cerr << "Error in equality after fract(1, 2) and fract(4,8)\n";
        f1.print(std::cout);
        std::cout << std::endl;
    }

    {
        fract f(4, 8);
        fract f_neg = f.neg();
        if(f_neg.num() != -1 || f_neg.denom() != 2)
            std::cerr << "Error in negation after fract(4, 8) \n";
        f_neg.print(std::cout);
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return 0;
}