//NAME       : TATENDA MACHIRORI
//COURSE     : CS3339.004
//INSTRUCTOR :PROFESSOR ANDRES GONZALES
//ASSIGNMENT : HOMEWORK 2

# Floating-Point Overflow Detector

## Team Members (worked individually)
- Tatenda Machirori

## How to Compile
```bash
g++ -o fp_overflow_checker fp_overflow_checker.cpp

## How to Run
''''bash
./fp_overflow_checker <loop_bound> <loop_counter>

Examples on how to run  :
./fp_overflow_checker 1e+08 1.0     (overflow case )

./fp_overflow_checker 1e+05 2.0     (no overfloe case)

./fp_overflow_checker 1.4567 3.14   (no overflow case)

./fp_overflow_checker 100000.0 2.0  (no overflow case)

./fp_overflow_checker 17.0          (invalid input)

Explanation :

When the following program is executed it will output some potentially useful information for the user regarding the possible errors that occur in floating point arithmetic.
Executing the command line ./fp_overflow_checker 1e+08 1.0 would return "Warning: Possible overflow!" because the number being added to each loop counter (1.0) is too small to be exactly represented at that bound (1e+08), with a 23-bit mantissa (IEEE 754 single precision) and approximately 1.67772e+07 as an overflow threshold where that precision loss begins.
./fp_overflow_checker 1e+05 2.0 would return "There is no overflow!" because the value 2.0 is larger than the ULP for this bound. ./fp_overflow_checker 17.0 would return "Usage: ./fp_overflow_checker float_bound adder" and exit, as that program call doesn't have two positive floating-point numbers on the command line. Suggestions to improve the README.md file would be to also include something about prerequisites to use (for example, g++ should be installed on the machine to run the code), mention something about the IEEE 754 floating point representation for the output of bits, and also remind to test various edge cases (very large bounds like 1e+38 or very small values like 1e-10 for the adder) to confirm behavior.