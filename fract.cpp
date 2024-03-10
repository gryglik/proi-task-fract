#include "fract.h"
#include <cmath>

void fract::set_fract(int new_num, unsigned int new_denom)
{
    unsigned int divisor = gcd(abs(new_num), new_denom);
    numerator = new_num / int(divisor);
    denominator = new_denom / divisor;
}

fract::fract(int num, unsigned int denom)
    : numerator(num), denominator(denom)
{
    set_fract(num, denom);
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
    return fract(-num(), denom());
}

void fract::add(const fract& right)
{
    unsigned int new_denominator = lcm(denom(), right.denom());
    int new_numerator = (num()*int(new_denominator))/int(denom())
        + (right.num()*new_denominator)/right.denom();
    set_fract(new_numerator, new_denominator);
}

fract fract::sum(const fract& right) const
{
    fract f(num(), denom());
    f.add(right);
    return f;
}

void fract::mul(const fract& right)
{
    set_fract(num() * right.num(), denom() * right.denom());
}

fract fract::prod(const fract& right) const
{
    fract f(num(), denom());
    f.mul(right);
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