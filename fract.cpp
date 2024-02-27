#include "fract.h"


fract::fract(int num, unsigned int denom)
    : numerator(num), denominator(denom)
{
    unsigned int divisor = gcd(numerator, denominator);
    if (divisor > 1)
    {
        numerator /= divisor;
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
