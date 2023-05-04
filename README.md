# Fraction
 Represents a fraction of two integers.
 
Constracturs:
Fraction();
Fraction(double);
Fraction(int x, int y);
Fraction(const Fraction& other);

Overloaded operators:
The + operator to add two fractions and return their sum as another fraction in reduced form.
The - operator to subtract two fractions and return their difference as another fraction in reduced form.
The * operator to multiply two fractions and return their product as another fraction in reduced form.
The / operator to divide two fractions and return their quotient as another fraction in reduced form.
The == operator to compare two fractions for equality and return true or false.
All comparison operations (>,<,>=,<=)
The ++ and -- operator that adds (or substracts) 1 to the fraction. implement both pre and post fix.
The << operator to print a fraction to an output stream in the format “numerator/denominator”.
The >> operator to read a fraction from an input stream by taking two integers as input.
