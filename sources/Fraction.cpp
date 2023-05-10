/* Author: Elad Shoham, 205439649*/
# include "Fraction.hpp"

using namespace std;

int Fraction::gcd(int x, int y) const {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

void Fraction::reduceByGcd() {
    // Find the gcd (if there is no, will be 1)
    int x = gcd(numerator, denominator);

    numerator = numerator / x;
    denominator = denominator / x;
}


Fraction::Fraction(int x, int y) : numerator(x), denominator(y) {
    if (y == 0) {
        throw std::string("Denominator cannot be zero (division by zero)");
    }

    if (x == 0) {
        denominator = 1;
    }
    else {
        reduceByGcd();
        if (denominator < 0) {
            numerator = numerator * (-1);
            denominator = denominator * (-1);
        }
    }
}

Fraction::Fraction(double other) {
    double left = other - (int)other;
    // shift 3 left
    numerator = (int) (other * 1000);
    denominator = 1000;
    
    reduceByGcd();
    if (denominator < 0) {
        numerator = numerator * (-1);
        denominator = denominator * (-1);
    }
}

Fraction& Fraction::operator= (const Fraction& other) {
    numerator = other.numerator;
    denominator = other.denominator;

    return *this;
}

void Fraction::operator= (double d) {
    Fraction f(d);
    *this = f;
}

Fraction Fraction::operator+ (double other) const {
    Fraction f(other);
    return operator+(f);
}

Fraction operator+ (double d, const Fraction& f) {
    return f + d;
}

Fraction Fraction::operator- (double d) const {
    Fraction f(d);
    return *this - f;
}

Fraction operator- (double d, const Fraction& f) {
    Fraction fd(d);
    return fd - f;
}


Fraction Fraction::operator*(double d) const {
    Fraction f(d);
    return *this * f;
}

Fraction operator* (double d, const Fraction& f) {
    Fraction fd(d);
    return f * fd;
}

Fraction Fraction::operator/(double d) const {
    Fraction f(d);
    return *this / f;
}

Fraction operator/(double d, const Fraction& f) {
    Fraction fd(d);
    return fd / f;
}

bool Fraction::operator== (double d) const {
    Fraction f(d);
    return *this == f;
}

bool operator==(double d, const Fraction& f) {
    Fraction fd(d);
    return fd == f;
}

bool Fraction::operator> (double d) const {
    Fraction f(d);
    return *this > f;
}

bool operator> (double d, const Fraction& f) {
    Fraction fd(d);
    return fd > f;
}

bool Fraction::operator>= (double d) const {
    Fraction f(d);
    return *this >= f;
}

bool operator>= (double d, const Fraction& f) {
    Fraction fd(d);
    return fd >= f;
}

bool Fraction::operator< (double d) const {
    Fraction f(d);
    return *this < f;
}

bool operator< (double d, const Fraction& f) {
    Fraction fd(d);
    return fd < f;
}

bool Fraction::operator<= (double d) const {
    Fraction f(d);
    return *this <= f;
}

bool operator<= (double d, const Fraction& f) {
    Fraction fd(d);
    return fd <= f;
}

std::ostream& operator<< (std::ostream& os, const Fraction& f){
    return (os << f.numerator << '/' << f.denominator);
}

static istream& getAndCheckNextCharIs(istream& input, char expectedChar) {
    char actualChar;
    input >> actualChar;
    if (!input) {return input;}

    if (actualChar!=expectedChar) {
        // failbit is for format error
        input.setstate(ios::failbit);
    }
    return input;
}

std::istream& operator>> (std::istream& input, Fraction& f) {
     char slash;
    input >> f.numerator >> slash >> f.denominator;
    if (slash != '/') {
         f.numerator = 0;
         f.denominator = 1;
         cout << "Error: format" << endl;
    }
    f.reduceByGcd();
    return input;
}
