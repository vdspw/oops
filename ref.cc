#include <iostream>
using namespace std; // Add this to use cout without std::

int main() {
    int x = 3;
    int& x_ref = x; // Reference to x
    cout << "Before modification: x = " << x << ", x_ref = " << x_ref << endl;

    // Modifying through reference to show how it affects x
    x_ref = 7;
    cout << "After modification: x = " << x << ", x_ref = " << x_ref << endl;
    
    int y = 5;
    int &y_ref =y;
    cout << "New value : "<< y_ref << endl;
    return 0;
}
