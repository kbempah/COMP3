#include <iostream>
#include <iomanip>
#include <climits>
#include <cmath>
#include <cstdint>

using namespace std;

const double FEET_TO_METERS_FACTOR = 0.3048;
const int FEET_TO_INCHES_FACTOR = 12;
const int METERS_TO_CENTIMETERS_FACTOR = 100;

void getLength(int32_t& _feet, double& _inches);
void getMetricUnits(int32_t _feet, double _inches, int32_t& _meters, double& _centimeters);
void displayConversions(int32_t _feet, double _inches, int32_t _meters, double _centimeters);
void converUnits(int32_t& _feet, double& _inches);

void clearKeyBoardBuffer();

template<typename DataType>
void validateLengthInput(DataType& _length);

int main(void) 
{
    int32_t feet, meters;
    double inches, centimeters;

    getLength(feet, inches);
    getMetricUnits(feet, inches, meters, centimeters);
    converUnits(feet, inches);
    displayConversions(feet, inches, meters, centimeters);

    return 0;
}

void getLength(int32_t& _feet, double& _inches)
{
    cout << "Please enter the number of feet > ";
    cin >> _feet;
    validateLengthInput(_feet);

    cout << "Please enter the number of inches > ";
    cin >> _inches;
    validateLengthInput(_inches);

    return;
}

void clearKeyBoardBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void getMetricUnits(int32_t _feet, double _inches, int32_t& _meters, double& _centimeters)
{
    double tempFeet = 0.0;
    double tempMeters = 0.0;

    tempFeet = _feet + (_inches/FEET_TO_INCHES_FACTOR);
    tempMeters = tempFeet * FEET_TO_METERS_FACTOR;

    _meters = floor(tempMeters);
    _centimeters = fmod((tempMeters * METERS_TO_CENTIMETERS_FACTOR),METERS_TO_CENTIMETERS_FACTOR);
}

void displayConversions(int32_t _feet, double _inches, int32_t _meters, double _centimeters)
{
    cout << fixed << showpoint << setprecision(8);

    cout << _feet << " feet and " << _inches << " inches converts to \n";
    cout << _meters << " meters and " << _centimeters << " centimeters.\n";
}

void converUnits(int32_t& _feet, double& _inches)
{
    _feet += floor(_inches/FEET_TO_INCHES_FACTOR);
    _inches = fmod(_inches, FEET_TO_INCHES_FACTOR);
}

template<typename DataType>
void validateLengthInput(DataType& _length)
{
    while (cin.fail() || _length < 0) {
        clearKeyBoardBuffer();
        if (_length < 0) {
            cout << "Invalid Input: Value must be non-negative.\n";
            cout << "Please enter number greater than or equal to 0 > ";
        }
        else {
            cout << "Error: unrecognized input. Value must be integer.\n";
            cout << "Please enter an integer value > ";
        }
        cin >> _length;
    }
    clearKeyBoardBuffer();
}
