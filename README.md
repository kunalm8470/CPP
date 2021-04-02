# CPP
Learning C++ from scratch
___

## Introduction and baby steps
1. Hello World Program
2. Variables (Assignment and Initialization)
3. Data types
4. Enumerated types and Enum classes
5. Structs

## Operators
1. Literals, Operators, Constants
2. Precedence and associativity

## Internals
1. Loaders and Linkers 
2. Preprocessor
2. Macros
3. Header files and guards

## Bitwise arithmetic
1. Bitwise operators
2. Bit flags and bit manipulation via `std::bitset`
3. Bit manipulation with bitwise operators and bit masks

## Variables and their scopes
1. Compound statements (blocks)
2. User-defined namespaces, Handling namespace collisions
3. Local variables
4. Global variables
5. Variable shadowing (name hiding)
6. Internal linkage
7. External linkage
8. Global constants and inline variables
9. Static local variables
10. Scope, duration, and linkage summary
11. Using statements
12. Typedefs and type aliases
13. `auto` keyword
14. Implicit type conversion (coercion)
15. Explicit type conversion (casting) and `static_cast`
16. Unnamed and inline namespaces

## Control and Iteration statements
1. If statement
2. Switch statement
3. Goto statement
4. While statement
5. Do while statement
6. For statement
7. Break and continue statements
8. Random number generation

## Arrays and Pointer arithmetic
1. Arrays
2. Multidimensional Arrays
3. C-style strings
4. `std::string_view`
5. Pointers
6. Null pointers
7. Pointers and arrays
8. Pointer arithmetic and array indexing
9. C-style string symbolic constants
10. Dynamic memory allocation with new and delete
11. Dynamically allocating arrays
12. Pointers and const
13. Reference variables
14. References and const
15. Member selection with pointers and references
16. For-each loops
17. Void pointers
18. Pointers to pointers and dynamic multidimensional arrays
19. `std::array`
20. `std::vector`
21. Iterators

## Functions
1. Functions
2. Forward declaration of function
3. Passing arguments by value
4. Passing arguments by reference
5. Passing arguments by address
6. Returning values by value, reference, and address
7. Inline functions
8. Function overloading
9. Default arguments
10. Function Pointers
11. The stack and the heap
12. std::vector capacity and stack behavior
13. Recursion
14. Handling errors, `cerr` and `exit`
15. Assert and `static_assert`
16. Command line arguments
17. Ellipsis (and why to avoid them)
18. Lambdas (anonymous functions)
19. Lambda captures

## Object Oriented Programming
1. Classes and class members
2. Public vs private access specifiers
3. Access functions and encapsulation
4. Constructors
5. Constructor member initializer lists
6. Non-static member initialization
7. Overlapping and delegating constructors
8. Destructors
9. **"this"** pointer
10. Class code and header files
11. Const class objects and member functions
12. Static member variables
13. Static member functions
14. Friend functions and classes
15. Anonymous objects
16. Nested types in classes
17. Timing code

## Inheritance
1. Basic inheritance in C++
2. Order of construction of derived classes
3. Constructors and initialization of derived classes
4. Inheritance and access specifiers
5. Adding new functionality to a derived class
6. Calling inherited functions and overriding behavior
7. Hiding inherited functionality
8. Multiple inheritance

## Polymorphism
1. Pointers and references to the base class of derived objects
2. Virtual functions and polymorphism
3. The override and final specifiers, and covariant return types
4. Virtual destructors, virtual assignment, and overriding virtualization
5. Early binding and late binding
6. The virtual table
7. Pure virtual functions, abstract base classes, and interface classes
8. Virtual base classes
9. Object slicing
10. Dynamic casting
11. Printing inherited classes using operator `<<`

## Operator overloading
1. Overloading the arithmetic operators using friend functions
2. Overloading operators using normal functions
3. Overloading the I/O operators
4. Overloading operators using member functions
5. Overloading unary operators `+`, `-`, and `!`
6. Overloading the comparison operators
7. Overloading the increment and decrement operators
8. Overloading the subscript operator
9. Overloading the parenthesis operator
10. Overloading typecasts
11. Copy constructor
12. Copy initialization
13. Converting constructors, explicit, and delete
14. Overloading the assignment operator
15. Shallow vs. Deep copying

## Object Relationships
1. Composition
2. Aggregation
3. Association
4. Dependencies
5. Container classes
6. `std::initializer_list`

## Templates
1. Function templates
2. Function template instances
3. Template classes
4. Template non-type parameters
5. Function template specialization
6. Class template specialization
7. Partial template specialization
8. Partial template specialization for pointers

## Exceptions and Exception Handling
1. Basic exception handling
2. Exceptions, functions, and stack unwinding
3. Uncaught exceptions, catch-all handlers, and exception specifiers
4. Exceptions, classes, and inheritance
5. Rethrowing exceptions
6. Function try blocks

## Move semantics and Smart Pointers
1. Smart pointers and move semantics
2. R-value and L-value references
3. Move constructors and move assignment
4. `std::move`
5. `std::unique_ptr`
6. `std::shared_ptr`
7. Circular dependency issues with `std::shared_ptr`, and `std::weak_ptr`

## Strings
1. `std::string` and `std::wstring`
2. `std::string` construction and destruction
3. `std::string` length and capacity
4. `std::string` character access and conversion to C-style arrays
5. `std::string` assignment and swapping
6. `std::string` appending
7. `std::string` inserting

## I/O
1. Input and output (I/O) streams
2. Input with istream
3. Output with ostream and ios
4. Stream classes for strings
5. Stream states and input validation
6. Basic file I/O
7. Random file I/O

## STL
1. STL containers overview
2. STL iterators overview
3. STL algorithms overview

## Idioms and Patterns
1. RAII
2. PIMPL
