#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double number = 123.456789;
    
    // Set precision to 5 digits in total
    cout << setprecision(5) << number << endl; 
    return 0;
}

// Using Fixed with setprecision

// Combining setprecision with fixed changes the behavior, so the precision strictly refers to the number of digits after the decimal point, and numbers are displayed in fixed-point notation.

#include <iostream>
#include <iomanip>

int main() {
    double number = 123.456789;
    
    // Set precision to 2 digits after the decimal point, with fixed-point notation
    cout << fixed << setprecision(4) << number << endl;  // Output: 123.4568

    return 0;
}

