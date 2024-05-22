/**********************
Name: Odin Lindal
Date: 5/1/24
CS132

Programming Assignment - Fractions

The behavior of this program is to create complex fractions
in the style of [(a/b) + (c/d)]i.
Functions are implemented to reduce, add, multiply, subtract,
increment, print and check equality of the fractions.

***********************/
#include <iostream>
#include "FractionalComplex.h"

/********** Constructors **************/
FractionalComplex::FractionalComplex()	//Default consctructor with no parameters
{
	a = c = 0; //Set the numerators to 0
	b = d = 1; //Set the denominators to 1
}

FractionalComplex::FractionalComplex(int x, int y) //Constructor with the numerators passed
{
	a = x;	//Set the first numerator to x
	c = y;	//Set the second numerator to y
	b = d = 1;	//Set both denominators to 1
}

FractionalComplex::FractionalComplex(int a, int b, int c, int d) //"Full" constructors, with both numerators and denominators passed
{
	if (b == 0) //If the first denominator is 0, default to 0/1
	{
		this->a = 0;	//Numerator is 0
		this->b = 1;	//Denominator is 1
	}
	else	//If the first denominator is not 0, set the first fraction to a/b
	{
		this->a = (b < 0) ? -a : a; //Checks if the denominator is smaller than 0, if so, we reverse the numerator because we want the negative sign on the top
		this->b = abs(b); //Absolute value for the denominator, if it is less than 0, we want the negative sign in the numerator
	}
	if (d == 0) //If the second denominator is 0, default to 0/1
	{
		this->c = 0;	//Numerator is 0
		this->d = 1;	//Denominator is 1
	}
	else	//If the second denominator is not 0, set the second fraction to c/d
	{
		this->c = (d < 0) ? -c : c; //Checks if the denominator is smaller than 0, if so, we reverse the numerator because we want the negative sign on the top
		this->d = abs(d);	//Absolute value for the denominator, if it is less than 0, we want the negative sign in the numerator
	}

	reduce(); //Call the reduce function to reduce the fractions
}

/********* Private Methods ************/
void FractionalComplex::reduce() //Function to reduce the fractions
{
	for (int i = abs(a); i > 1; i--) //Loops through all numbers i that start with the absolute value of the numerator, and ends at 2, decrements 1 for each iteration
	{
		if (a % i == 0 && b % i == 0) //If both the numerator and the denominator are divisible by i, divide them both by i
		{
			a = a / i; //Divide numerator by i
			b = b / i; //Divide denominator by i
		}
	}
	for (int i = abs(c); i > 1; i--) //Loops through all numbers i that start with the absolute value of the numerator, and ends at 2, decrements 1 for each iteration
	{
		if (c % i == 0 && d % i == 0) //If both the numerator and the denominator are divisible by i, divide them both by i
		{
			c = c / i; //Divide numerator by i
			d = d / i; //Divide denominator by i
		}
	}
}

double FractionalComplex::length() const //Function to determine the length of a fractional complex number
{
	//returns the sqaure root of the fractions squared and added together
	return sqrt(((double(a) / double(b)) * ((double(a) / double(b))) + (double(c) / double(d)) * (double(c) / double(d))));
}

/********* Public Methods *************/
void FractionalComplex::printme() const //Function to print the complex number, in the format [(a/b)+(c/d)]
{
	std::cout << "[(" << a << "/" << b << ") + (" << c << "/" << d << ")i]" << std::endl;
}

FractionalComplex FractionalComplex::operator++() //Post-fix increment function, ++a, increments the complex number by 1
{
	a += b; //Adds one whole to the first fraction
	c += d;	//Adds one whole to the second fraction
	reduce(); //Reduce if possible
	return *this; //Return the object
}

FractionalComplex FractionalComplex::operator++(int) //Pre-fix increment function, a++, increments the complex number by 1 after it has been used
{
	FractionalComplex origVersion = *this; //Create a copy of the original object
	a += b;	//Add one whole to the first fraction
	c += d; //Add one whole to the second fraction
	reduce(); //Reduce if possible
	return origVersion; //Return the original object, that has not incremented
}

/********* Exterior Functions ***********/
FractionalComplex operator+(const FractionalComplex& lhs, const FractionalComplex& rhs) //Addition operator, to add two complex numbers together
{
	FractionalComplex temp((lhs.a * rhs.b) + (rhs.a * lhs.b), lhs.b * rhs.b, (lhs.c * rhs.d) + (rhs.c * lhs.d), lhs.d * rhs.d); //Create a temporary object with parameters
	//following the same logic as when adding fractions, multiply the first fraction by the second denominator, and the second fraction by the first denominator, then add the numerators
	temp.reduce(); //Reduce if possible
	return temp; //Return the newly created object
}

FractionalComplex operator-(const FractionalComplex& lhs, const FractionalComplex& rhs) //Subtraction operator
{
	//Following the same logic as the addition operator, but subracting the numerators instead of adding them
	FractionalComplex temp((lhs.a * rhs.b) - (rhs.a * lhs.b), lhs.b * rhs.b, (lhs.c * rhs.d) - (rhs.c * lhs.d), lhs.d * rhs.d);
	temp.reduce(); //Reduce if possible
	return temp; //Return the newly created object
}

//This operator follows the formula for multiplying fractional complex numbers, as in the instructions
FractionalComplex operator*(const FractionalComplex& lhs, const FractionalComplex& rhs)
{
	//Two different temp objects are constructed, then added together
	//The w, x, y, z in the formula are represented by lhs.a, b, c, d respectively
	FractionalComplex temp1((lhs.a * rhs.a), (lhs.b * rhs.b), (lhs.a * rhs.c), (lhs.b * rhs.d)); //The first complex number is created in the format aw/bx+ay/bz i
	FractionalComplex temp2((-1 * lhs.c * rhs.c), (lhs.d * rhs.d), (lhs.c * rhs.a), (lhs.d * rhs.b)); //The second complex number is created in the format -1cy/dz+cw/dx i
	FractionalComplex temp = temp1 + temp2; //Adding the two together using the + operator
	temp.reduce(); //Reduce if necessary
	return temp; //Return the newly created object
}

FractionalComplex operator*(const FractionalComplex& lhs, int x) //Operator for multiplying a complex number by an integer
{
	FractionalComplex temp((lhs.a * x), lhs.b, (lhs.c * x), lhs.d); //Create a new object with the parameters: both numerators multiplied by the int, and denominators stay the same
	temp.reduce(); //Reduce if necessary
	return temp; //Return the newly created object
}

FractionalComplex operator*(int x, const FractionalComplex& rhs) //Operator for multiplying a complex number by an integer
{
	FractionalComplex temp((rhs.a * x), rhs.b, (rhs.c * x), rhs.d); //Create a new object with the parameters: both numerators multiplied by the int, and denominators stay the same
	temp.reduce(); //Reduce if necessary
	return temp; //Return the newly created object
}

bool operator==(const FractionalComplex& lhs, const FractionalComplex& rhs) //Equality operator, checks if two objects are the same
{
	if (lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c && lhs.d == rhs.d) //Check if a, b, c and d on both sides are the same, if so, return true
		return true;
	else	//If they are not all equal, return false
		return false;
}

bool operator<(const FractionalComplex& lhs, const FractionalComplex& rhs) //Smaller than operator
{
	//return (lhs.a * lhs.d + lhs.c * lhs.b) / (lhs.b * lhs.d) < (rhs.a * rhs.d + rhs.b * rhs.c) / (rhs.b * rhs.d); //ALTERNATIVE WAY
	return lhs.length() < rhs.length(); //Find the length of both sides, then check if the left side is smaller than the right side
}

bool operator>(const FractionalComplex& lhs, const FractionalComplex& rhs) //Greater than operator
{
	return rhs < lhs; //Returns the opposite of the <operator
}

std::ostream& operator<<(std::ostream& o, const FractionalComplex& rhs) //Pipe operator, returns a stream formatted to [(a/b)+(c/d)i]
{
	o << "[(" << rhs.a << "/" << rhs.b << ") + (" << rhs.c << "/" << rhs.d << ")i]"; //Pipes the formatted stream into the ostream object o
	return o; //Returns the output stream object
}