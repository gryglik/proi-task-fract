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
        std::cout << std::endl;
    }

    {
        fract f(2, 4);
        if (f.num() != 1 || f.denom() != 2)
            std::cerr << "Error in values after fract(2, 4) ctor\n";
        std::cout << std::endl;
    }

    {
        fract f(-3, 9);
        if (f.num() != -1 || f.denom() != 3)
            std::cerr << "Error in values after fract(-3, 9) ctor\n";
        std::cout << std::endl;
    }

    {
        fract f(0, 500);
        if (f.num() != 0 || f.denom() != 1)
            std::cerr << "Error in values after fract(0, 1) ctor\n";
        std::cout << std::endl;
    }

    {
        fract f1(1, 2);
        fract f2(4, 8);
        if (not f1.equal(f2))
            std::cerr << "Error 1 in equality after fract(1, 2) and fract(4,8)\n";
        if (f1.equal(fract(1, 3)))
            std::cerr << "Error 2 in equality after fract(1, 2) and fract(1, 3)";
        std::cout << std::endl;
    }

    {
        fract f(4, 8);
        fract f_neg = f.neg();
        if (f_neg.num() != -1 || f_neg.denom() != 2)
            std::cerr << "Error in negation after fract(4, 8) \n";
        std::cout << std::endl;
    }

    {
        fract f(1, 6);
        f.add(fract(1, 2));
        if (f.num() != 2 || f.denom() != 3)
            std::cerr << "Error while adding fract(1, 6) to fract(1, 2)";
    }

    {
        fract f(-2, 10);
        f.add(fract(1, 15));
        if (f.num() != -2 || f.denom() != 15)
            std::cerr << "Error while adding fract(1, 15) to fract(-2, 10)";
    }


    {
        fract f(-2, 10);
        f.add(fract(5, 15));
        if (f.num() != 2 || f.denom() != 15)
            std::cerr << "Error while adding fract(5, 15) to fract(-2, 10)";
    }

    {
        fract f(-1, 12);
        f.add(fract(1, 12));
        if (f.num() != 0 || f.denom() != 1)
            std::cerr << "Error while adding fract(1, 12) to fract(-1, 12)";
    }

    std::cout << std::endl;
    return 0;
}