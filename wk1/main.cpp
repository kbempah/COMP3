#include <iostream>
#include <climits>

using namespace std;

void clear_keyboard_buffer();

int main(void) {
    int x;
    double PI = 3.14159;

    // used for formatting output 
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(8);
    
    cout << "Enter a value for x that is non-negative > ";
    cin >> x;

    while (cin.fail() || x < 0) {
        clear_keyboard_buffer();
        cout << "Please enter a value that is non-negative > ";
        cin >> x;
    }
    clear_keyboard_buffer();
    
    cout << "The final value is " << x << "\n";
    return 0;
}

void clear_keyboard_buffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}