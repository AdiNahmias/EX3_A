#include "doctest.h"
#include <iostream>
#include "Fraction.hpp"
using namespace ariel;



TEST_CASE("Fractional initialization check"){
    Fraction x(1,2);
    CHECK(x.getNumerator() == 1);
    CHECK(x.getDenominator() == 2);
    Fraction a(1,3);
    Fraction b(2,6);
    Fraction c(3,9);
    CHECK(a.getNumerator() == 1);
    CHECK(a.getDenominator() == 3);
    CHECK(b.getNumerator() == 1);
    CHECK(b.getDenominator() == 3);
    CHECK(c.getNumerator() == 1);
    CHECK(c.getDenominator() == 3);

}


TEST_CASE("Checking for a valid denominator"){
    Fraction a(1,3);
    CHECK_THROWS(a.setDenominator(0));
    CHECK_THROWS(Fraction(1,0));
   
}

TEST_CASE("Chking reduction of fractions"){
    Fraction a(1,3);
    Fraction b(2,6);
    Fraction c(3,9);
    CHECK(a == b);
    CHECK(b == c);
    CHECK(c == a);
}


TEST_CASE("Checking the + operator"){
    Fraction x(1,2);
    double y = 0.5;
    double z = 1.0;
    CHECK((x+y) == z);
    Fraction a(1,3);
    Fraction b(2,6);
    Fraction c(3,9);
    CHECK((a + b) + c == 1.0);
    

}

TEST_CASE("Checking the - operator"){
    Fraction a(3,6);
    double b = 0.5;
    double c = 0.0;
    CHECK((a - b) == c);
    Fraction x(3,2);
    Fraction y(1,2);
    CHECK(x - y == 1.0);

}

TEST_CASE("Checking the * operator"){
    Fraction a(1,3);
    double b = 0.0;
    CHECK( a * b  == b);
    CHECK( a * b == 2 * b);
    Fraction x(3,6);
    Fraction y(1,2);
    Fraction z(5,10);
    CHECK((x * y) * z == Fraction(1,8));

}

TEST_CASE("Checking the / operator"){
    Fraction a(1,3);
    Fraction b(2,6);
    CHECK( a / b == 1);
    CHECK( b / a == 1);
    Fraction x(3,2);
    Fraction y(1,2);
    Fraction z(5,10);
    CHECK(((x / y) / z) == 6);

}

TEST_CASE("Checking all comparison operations (>,<,>=,<=)"){
    Fraction a(1,3);
    Fraction b(2,6);
    CHECK(a >= b);
    Fraction x(3,2);
    Fraction y(1,2);
    CHECK(x > y);
    CHECK( x >= y);

}

TEST_CASE("Checking the ++ and -- operator"){
    Fraction a(1,3);
    Fraction b(1,2);
    a--;
    CHECK(a == Fraction(-2,3));
    b++;
    CHECK(b == Fraction(3,2));
    Fraction x(3,2);
    Fraction y(1,2);

    for(int i=0; i<5; i++){
        x++;
        y--;
    }

    CHECK(x == Fraction(13,2));
    CHECK(y == Fraction(-9,2));

    Fraction c(1,3);
    Fraction d(1,2);
    
    Fraction result_1 = c++ * d;
    CHECK(result_1 == Fraction(1,6));

    Fraction result_2 = ++c * d;
    CHECK(result_2 == Fraction(2,3));

}





