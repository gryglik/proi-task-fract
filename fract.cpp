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
    return right.num() == num()
        && right.denom() == denom();
}

fract fract::neg() const
{
    if(numerator == 0)
        return fract();
    return fract(-num(), denom());
}

void fract::add(const fract& right)
{
    unsigned int new_denominator = lcm(denom(), right.denom());
    int new_numerator = (num()*int(new_denominator))/int(denom())
        + (right.num()*new_denominator)/right.denom();
    unsigned int divisor = gcd(new_denominator, new_numerator);
    numerator = new_numerator / int(divisor);
    denominator = new_denominator / divisor;
}

fract fract::sum(const fract& right) const
{
    fract f(num(), denom());
    f.add(right);
    return f;
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

unsigned int lcm(unsigned int a, unsigned int b)
{
    return a*b/gcd(a,b);
}