/* Author: Elad Shoham, 205439649 */
#pragma once

#include <string>
#include <numeric>
#include <iostream>
#include <cmath>

using namespace std;

class Fraction {
private:

    int numerator;
    int denominator;

    // Find the greatest common divisor of the numerator and denominator and reduce the fraction
    int gcd(int, int) const;
    void reduceByGcd();
public:

    // Constructors
    Fraction() : numerator(0), denominator(1) {}
    Fraction(double);
    Fraction(int x, int y);
    Fraction(const Fraction& other) : numerator(other.numerator) , denominator(other.denominator) {
        cout << "copy constr" << endl;
        reduceByGcd();
    }

    // destructor
    ~Fraction() {}
    
    //toString() overload
    std::string toString() const {return std::to_string(numerator) + "/" + std::to_string(denominator); }

    // Get
    int getNumerator() const {return numerator;}
    int getDenominator() const {return denominator;}

    //----------------------------------------
    // binary operators
    //----------------------------------------
    Fraction& operator= (const Fraction&);
    void operator= (double);

    Fraction operator+ (const Fraction& other) const {return Fraction((numerator * other.denominator) + (other.numerator * denominator), denominator * other.denominator);}
    Fraction operator+ (double) const;
    friend Fraction operator+ (double, const Fraction&);

    
    Fraction operator- (const Fraction& other) const {return Fraction((numerator * other.denominator) - (other.numerator * denominator), denominator * other.denominator);};
    Fraction operator- (double) const;
    friend Fraction operator- (double, const Fraction&);

    Fraction operator* (const Fraction& other) const {return Fraction(numerator * other.numerator, denominator * other.denominator);}
    Fraction operator* (double) const;
    friend Fraction operator* (double, const Fraction&);

    Fraction operator/ (const Fraction& other) const {return Fraction(numerator * other.denominator, denominator * other.numerator);}
    Fraction operator/ (double) const;
    friend Fraction operator/ (double, const Fraction&);

    bool operator== (const Fraction& other) const {return (numerator == other.numerator) && (denominator == other.denominator);}
    bool operator== (double) const;
    friend bool operator== (double, const Fraction&);
    
    Fraction& operator++() {
        numerator = numerator + denominator;
        return *this;
    }

    Fraction operator++(int dummy_flag_for_postfix_increment) {
        Fraction f(*this);
        numerator = numerator + denominator;
        return f;
    }

    
    Fraction& operator--() {
        numerator = numerator - denominator;
        return *this;
    }
    Fraction operator--(int) {
        Fraction f(*this);
        numerator = numerator - denominator;
        return f;
    }

    
    bool operator> (const Fraction& other) const {
        return (numerator * other.denominator) > (other.numerator * denominator);
    }

    bool operator> (double) const;
    friend bool operator> (double, const Fraction&);

    bool operator>= (const Fraction& other) const { return *this > other || *this == other;}
    bool operator>= (double) const;
    friend bool operator>= (double, const Fraction&);
    
    bool operator< (const Fraction& other) const {return (numerator * other.denominator) < (denominator * other.numerator);}
    bool operator< (double) const;
    friend bool operator< (double, const Fraction&);

    bool operator<= (const Fraction& other) const {return *this < other || *this == other;}
    bool operator<= (double) const;
    friend bool operator<= (double, const Fraction&);

    //----------------------------------
    // friend global IO operators
    //----------------------------------
    friend ostream& operator<< (ostream&, const Fraction&);
    friend istream& operator>> (istream& , Fraction&);
};
