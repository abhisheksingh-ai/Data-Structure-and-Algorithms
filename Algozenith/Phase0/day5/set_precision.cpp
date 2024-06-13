#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double number = 123.456789;
    
    // Set precision to 5 digits in total
    cout << setprecision(5) << number << endl;  // Output might be in scientific notation for large numbers
    //123.46
    return 0;
}
