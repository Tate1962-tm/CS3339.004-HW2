//NAME       : TATENDA MACHIRORI
//COURSE     : CS3339.004
//INSTRUCTOR :PROFESSOR ANDRES GONZALES
//ASSIGNMENT : HOMEWORK 2

#include <iostream>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

// Function to print IEEE 754 representation of a float with proper spacing
void printIEEE(float value) {
    union {
        float f;
        uint32_t i;
    } u;
    u.f = value;

    bitset<32> bits(u.i);

    cout << bits[31] << " "; // Sign bit + space
    for (int i = 30; i >= 23; i--)
        cout << bits[i];
    cout << " ";
    for (int i = 22; i >= 0; i--)
        cout << bits[i];
    cout << endl;
}

float calculateULP(float value) {
    union {
        float f;
        uint32_t i;
    } u;
    u.f = fabs(value);

    uint32_t exponent = (u.i >> 23) & 0xFF;
    if (exponent == 0) return 0.0f;

    int adjusted_exponent = exponent - 127 - 23;
    return ldexp(1.0f, adjusted_exponent);
}


float calculateOverflowThreshold(float increment) {
    return ldexp(fabs(increment), 23);
}

int main(int argc, char* argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        cerr << "usage:" << endl;
        cerr << "    ./fp_overflow_checker loop_bound loop_counter" << endl;
        cerr << endl;
        cerr << "    loop_bound is a positive floating-point value" << endl;
        cerr << "    loop_counter is a positive floating-point value" << endl;
        cerr << endl;
        return 1;
    }

    float bound, increment;
    try {
        bound = stof(argv[1]);
        increment = stof(argv[2]);
    }
    catch (...) {
        cerr << "usage:" << endl;
        cerr << "    ./fp_overflow_checker loop_bound loop_counter" << endl;
        cerr << endl;
        cerr << "    loop_bound is a positive floating-point value" << endl;
        cerr << "    loop_counter is a positive floating-point value" << endl;
        cerr << endl;
        return 1;
    }

    if (bound <= 0 || increment <= 0) {
        cerr << "usage:" << endl;
        cerr << "    ./fp_overflow_checker loop_bound loop_counter" << endl;
        cerr << endl;
        cerr << "    loop_bound is a positive floating-point value" << endl;
        cerr << "    loop_counter is a positive floating-point value" << endl;
        return 1;
    }

    cerr << endl;

    cout << "Loop bound:   ";
    printIEEE(bound);
    cout << "Loop counter: ";
    printIEEE(increment);
    cout << endl;

    float ulp = calculateULP(bound);

    if (ulp >= increment) {
        cout << "Warning: Possible overflow!" << endl;
        cout << "Overflow threshold:" << endl;

        float threshold = calculateOverflowThreshold(increment);

        // Convert number to string (scientific format)
        stringstream ss;
        ss << scientific << setprecision(6) << threshold;
        string numStr = ss.str();

        // Set the padding to position the '8' just 7to 8 spaces is enough
        const int padding = 7;
        cout << string(padding, ' ') << numStr << endl;

        // Align IEEE output so '0' is directly under '8'
        cout << string(padding, ' ');
        printIEEE(threshold);
    }
    else {
        cout << "There is no overflow!" << endl;
    }

    return 0;
}