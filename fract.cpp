#include "fract.h"
#include <cmath>

fract::fract(int num, unsigned int denom)
    : numerator(num), denominator(denom)
{
    unsigned int divisor = gcd(abs(numerator), denominator);
    if (divisor > 1)
    {
        numerator /= int(divisor);
        denominator /= divisor;
    }
}

int fract::num() const
{
    return numerator;
}

unsigned int fract::denom() const
{
    return denominator;
}

bool fract::equal(const fract& right) const
{
    if ((right.num() == numerator) && (right.denom() == denominator))
        return true;
    return false;
}

fract fract::neg() const
{
    if(numerator == 0)
        return fract();
    return fract(-numerator, denominator);
}

void fract::print(std::ostream& os) const
{
    os << num();
    if (denom() != 1)
        os << '/' << denom();
}

unsigned int gcd(unsigned int a, unsigned int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return std::max(a, b);
}
