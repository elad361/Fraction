/* Author: Elad Shoham, 205439649 */
#pragma once

#include <string>
#include <numeric>
#include <iostream>

using namespace std;

class Fraction {
private:

    int numerator;
    int denominator;

    // Finds the greatest common divisor of the numerator and denominator and reduce the fraction
    void reduceByGcd();
public:

    // Constructors
    Fraction() : numerator(0), denominator(1) {}
    Fraction(double);
    Fraction(int x, int y);
    Fraction(const Fraction& other) : numerator(other.numerator) , denominator(other.denominator) {}
    
    //toString() overload
    string toString() const {return to_string(numerator) + "/" + to_string(denominator); }

    // Get
    int getNumerator() const {return numerator;}
    int getDenominator() const {return denominator;}

    //----------------------------------------
    // binary operators
    //----------------------------------------
    Fraction operator+ (const Fraction&) const;
    Fraction operator+ (double) const;

    Fraction operator- (const Fraction&) const;
    Fraction operator- (double) const;

    Fraction operator* (const Fraction&) const;
    Fraction operator* (double) const;

    Fraction operator/ (const Fraction&) const;
    Fraction operator/ (double);

    bool operator== (const Fraction&) const;
    bool operator== (double) const;

    bool operator> (const Fraction&) const;
    bool operator> (double) const;

    bool operator>= (const Fraction&) const;
    bool operator>= (double) const;

    bool operator< (const Fraction&) const;
    bool operator< (double) const;

    bool operator<= (const Fraction&) const;
    bool operator<= (double) const;


    Fraction& operator++();
    Fraction operator++(int);

    Fraction& operator--();
    Fraction operator--(int);

    //-------------------------------------
    // friend global binary operators
    //-------------------------------------
    friend Fraction operator+ (double, const Fraction&);
    friend Fraction operator- (double, const Fraction&);
    friend Fraction operator* (double, const Fraction);
    friend Fraction operator/ (double, const Fraction&);
    friend bool operator== (double, const Fraction&);
    friend bool operator> (double, const Fraction&);
    friend bool operator>= (double, const Fraction&);
    friend bool operator< (double, const Fraction&);
    friend bool operator<= (double, const Fraction);

    //----------------------------------
    // friend global IO operators
    //----------------------------------
    friend ostream& operator<< (ostream&, const Fraction&);
    friend istream& operator>> (istream& , Fraction&);
};
