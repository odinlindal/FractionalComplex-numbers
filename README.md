# FractionalComplex Library

## Overview

This project implements a `FractionalComplex` class in C++ that supports operations on complex fractions in the form `[(a/b) + (c/d)]i`. The library includes functionalities for creating, reducing, adding, multiplying, subtracting, incrementing, printing, and checking equality of the fractions.

[Programming Assignment - CS132 - Fractions.pdf](https://github.com/odinlindal/FractionalComplex-numbers/blob/d8914e886d178d05bfe606dc17b4b4ebd5e5037e/Programming%20Assignment%20-%20CS132%20-%20Fractions.pdf)

### Features

- Default and parameterized constructors
- Overloaded operators for arithmetic operations and comparisons
- Methods to reduce fractions and calculate their length

## File Structure

- `FractionalComplex.h`: Header file with class definition and method declarations.
- `FractionalComplex.cpp`: Source file with method implementations.

## Installation

To use this library, simply include the `FractionalComplex.h` and `FractionalComplex.cpp` files in your project.

## Usage

### Example

```cpp
#include <iostream>
#include "FractionalComplex.h"

int main() {
    FractionalComplex fc1(1, 2, 3, 4);
    FractionalComplex fc2(2, 3, 4, 5);

    std::cout << "fc1: " << fc1 << std::endl;
    std::cout << "fc2: " << fc2 << std::endl;

    FractionalComplex fc3 = fc1 + fc2;
    std::cout << "fc1 + fc2: " << fc3 << std::endl;

    return 0;
}
