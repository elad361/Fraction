/* Author: Elad Shoham, 205439649*/
# include "Fraction.hpp"

using namespace std;

void Fraction::reduceByGcd() {
    // Find the gcd (if there is no, will be 1)
    int gcd = std::gcd(numerator, denominator);

    numerator = numerator / gcd;
    denominator = denominator / gcd;
}

Fraction::Fraction(int x, int y) : numerator(x), denominator(y) {
    if (y == 0) {
        throw std::string("Denominator cannot be zero (division by zero)");
    }

    if (x == 0) {
        denominator = 1;
    }
    else reduceByGcd();
}

bool Fraction::operator== (const Fraction& other) const {
    return (numerator == other.numerator) && (denominator == other.denominator);
}

bool Fraction::operator== (double other) const {
    Fraction f(other);
    return operator== (f);
}

std::ostream& operator << (std::ostream& os, const Fraction& f){
    return (os << f.numerator << '/' << f.denominator);
}
