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
    }

    {
        fract f(2, 4);
        if (f.num() != 1 || f.denom() != 2)
            std::cerr << "Error in values after fract(2, 4) ctor\n";
    }

    {
        fract f(-3, 9);
        if (f.num() != -1 || f.denom() != 3)
            std::cerr << "Error in values after fract(-3, 9) ctor\n";
    }

    {
        fract f(0, 500);
        if (f.num() != 0 || f.denom() != 1)
            std::cerr << "Error in values after fract(0, 1) ctor\n";
    }

    {
        fract f1(1, 2);
        fract f2(4, 8);
        if (not f1.equal(f2))
            std::cerr << "Error 1 in equality after fract(1, 2) and fract(4,8)\n";
        if (f1.equal(fract(1, 3)))
            std::cerr << "Error 2 in equality after fract(1, 2) and fract(1, 3)\n";
        if (f1.equal(fract(-1, 2)))
            std::cerr << "Error 3 in equality after fract(1, 2) and fract(-1, 2)\n";
    }

    {
        fract f(4, 8);
        fract f_neg = f.neg();
        if (f_neg.num() != -1 || f_neg.denom() != 2)
            std::cerr << "Error in negation after fract(4, 8)\n";
    }

    {
        fract f(-3, 9);
        fract f_neg = f.neg();
        if (f_neg.num() != 1 || f_neg.denom() != 3)
            std::cerr << "Error in negation after fract(-3, 9)\n";
    }

    {
        fract f(0, 10);
        fract f_neg = f.neg();
        if (f_neg.num() != 0 || f_neg.denom() != 1)
            std::cerr << "Error in negation after fract(0, 10)\n";
    }

    {
        fract f(1, 6);
        f.add(fract(1, 2));
        if (f.num() != 2 || f.denom() != 3)
            std::cerr << "Error while adding fract(1, 6) to fract(1, 2)\n";
    }

    {
        fract f(-2, 10);
        f.add(fract(1, 15));
        if (f.num() != -2 || f.denom() != 15)
            std::cerr << "Error while adding fract(1, 15) to fract(-2, 10)\n";
    }


    {
        fract f(-2, 10);
        f.add(fract(5, 15));
        if (f.num() != 2 || f.denom() != 15)
            std::cerr << "Error while adding fract(5, 15) to fract(-2, 10)\n";
    }

    {
        fract f(-1, 12);
        f.add(fract(2, 24));
        if (f.num() != 0 || f.denom() != 1)
            std::cerr << "Error while adding fract(1, 12) to fract(-1, 12)\n";
    }

    {
        fract f(-1, 12);
        f.add(fract(0, 909));
        if (f.num() != -1 || f.denom() != 12)
            std::cerr << "Error while adding fract(-1, 12) to fract(0, 909)\n";
    }

    {
        fract f(-3, 30);
        fract f_sum = f.sum(fract(4, 15));
        if (f_sum.num() != 1 || f_sum.denom() != 6)
            std::cerr << "Error while summing fract(-3, 30) and dract(4, 15)\n";
    }

    {
        fract f(1, 30);
        f.mul(fract(2, 60));
        if (f.num() != 1 || f.denom() != 900)
            std::cerr << "Error in multiplying fract(1, 30) by fract(2, 60)\n";
    }

    {
        fract f(-3, 14);
        f.mul(fract(2, 5));
        if (f.num() != -3 || f.denom() != 35)
            std::cerr << "Error in multiplying fract(-3, 14) by fract(2, 5)\n";
    }

    {
        fract f(-3, 14);
        f.mul(fract(-3, 3));
        if (f.num() != 3 || f.denom() != 14)
            std::cerr << "Error in multiplying fract(-3, 14) by fract(-3, 3)\n";
    }

    {
        fract f(-4, 10);
        f.mul(fract(0, 10));
        if (f.num() != 0 || f.denom() != 1)
            std::cerr << "Error in multiplying fract(-4, 10) by fract(0, 10)\n";
    }

    {
        fract f(-3, 12);
        fract f_prod = f.prod(fract(2, 3));
        if (f_prod.num() != -1 || f_prod.denom() != 6)
            std::cerr << "Error in product of fract(-3, 12) and fract(2, 3)\n";
    }
    return 0;
}