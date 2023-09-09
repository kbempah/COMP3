#include <iostream>
#include <cstdint>
#include <cmath>
#include <climits>

using namespace std;

void getUserInput(int& _startPoint, int& _endPoint);
void clearKeyboardBuffer();
uint64_t calculateSumPrimes(int _startPoint, int _endPoint);
bool isPrime(int _value);

int main(void) {
    int start, end;
    uint64_t sum;

    getUserInput(start,end);
    sum = calculateSumPrimes(start,end);
    cout << "The sum of all the numbers is " << sum << "\n";

    return 0;
}

void getUserInput(int& _s, int& _e) {
    cout << "Enter starting value > ";
    cin >> _s;
    while (cin.fail()) {
        clearKeyboardBuffer();
        cout << "Bad input value: must be a counting number\n";
        cout << "Enter starting value > ";
        cin >> _s;
    }
    clearKeyboardBuffer();

    cout << "Enter ending value > ";
    cin >> _e;
    while (cin.fail()) {
        clearKeyboardBuffer();
        cout << "Bad input value: must be a counting number\n";
        cout << "Enter starting value > ";
        cin >> _e;
    }
    clearKeyboardBuffer();
}

void clearKeyboardBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

uint64_t calculateSumPrimes(int _startPoint, int _endPoint) {
    uint64_t sum = 0;

    for (int i = _startPoint; i <= _endPoint; ++i) {
        if (isPrime(i)) {
            cout << i << "\n";
            sum += i;
        }
    }

    return sum;
}

bool isPrime(int _value) {
    int factorCount = 0;

    if (_value <= 1)
        return false;

    for (int factor = 1; factor <= sqrt(_value); ++factor) {
        if ((_value % factor) == 0) {
            ++factorCount;
            
            if (factorCount > 1) return false;
        }
    }

    return true;
}