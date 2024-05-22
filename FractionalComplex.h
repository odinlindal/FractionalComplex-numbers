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

class FractionalComplex
{
	private:
		int a;
		int b;
		int c;
		int d;

		void reduce();
	public:
		FractionalComplex();
		FractionalComplex(int, int);
		FractionalComplex(int, int, int, int);

		void printme() const;
};