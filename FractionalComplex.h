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

#pragma once
#include <iostream>

class FractionalComplex
{
public:
	FractionalComplex(); //Default constructor, sets the fractions to 0/1 and 0/1
	FractionalComplex(int x, int y); //Constructor with only 2 numbers, sets the fractions to x/1 and y/1
	FractionalComplex(int a, int b, int c, int d); //"Full" constructor, sets fractions to a/b and c/d

	//All of the binary operators need friend acccess because they are modifiying the private variables
	//*function prototypes w/comments are outside the class*
	friend FractionalComplex operator+(const FractionalComplex& lhs, const FractionalComplex& rhs);
	friend FractionalComplex operator-(const FractionalComplex& lhs, const FractionalComplex& rhs);
	friend FractionalComplex operator*(const FractionalComplex& lhs, const FractionalComplex& rhs);
	friend FractionalComplex operator*(const FractionalComplex& lhs, int x);
	friend FractionalComplex operator*(int x, const FractionalComplex& rhs);
	friend bool operator==(const FractionalComplex& lhs, const FractionalComplex& rhs);
	friend bool operator<(const FractionalComplex& lhs, const FractionalComplex& rhs);	
	friend bool operator>(const FractionalComplex& lhs, const FractionalComplex& rhs);	
	friend std::ostream& operator<<(std::ostream& o, const FractionalComplex& rhs);
	
	FractionalComplex operator++(); //Post-fix increment, ++a
	FractionalComplex operator++(int); //Pre-fix increment, a++

	void printme() const; //Obsolete printme function, prints off the object

private:
	//Declaring the 4 variables for the fractions
	int a;
	int b;
	int c;
	int d;

	void reduce(); //Function to reduce the fractions when necessary
	double length() const; //Function to find the length of the complex number
};

//Binary operators
FractionalComplex operator+(const FractionalComplex& lhs, const FractionalComplex& rhs); //Addition operator, adds two complex numbers together
FractionalComplex operator-(const FractionalComplex& lhs, const FractionalComplex& rhs); //Subtraction operator, finds the difference between two complex numbers
FractionalComplex operator*(const FractionalComplex& lhs, const FractionalComplex& rhs); //Multiplication operator, multiplies two complex numbers
FractionalComplex operator*(const FractionalComplex& lhs, int x); //Multiplication operator, multiplies a complex number by an integer
FractionalComplex operator*(int x, const FractionalComplex& rhs); //Same as above, allows the variables to be on either side of the asterisk
bool operator==(const FractionalComplex& lhs, const FractionalComplex& rhs); //Checks if two complex numbers are the same
bool operator<(const FractionalComplex& lhs, const FractionalComplex& rhs);	 //Checks if one complex number is bigger than another
bool operator>(const FractionalComplex& lhs, const FractionalComplex& rhs);  //Checks if one complex number is smaller than another
std::ostream& operator<<(std::ostream& o, const FractionalComplex& rhs);     //Pipe operator, allows us to cout the object without using a printme function