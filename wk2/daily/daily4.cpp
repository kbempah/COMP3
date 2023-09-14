#include <_ctype.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <limits>
#include <cctype>

using namespace std;

const double CEL_TO_KEL = 273.15;

class Temperature
{
    public:
    Temperature();
    void set_temp_kelvin(double);
    void set_temp_fahrenheit(double);
    void set_temp_celsius(double);
    double get_temp_kelvin() const;
    double get_temp_fahrenheit() const;
    double get_temp_celsius() const;

    private:
    double degrees_kelvin;
};

Temperature::Temperature()
{
    degrees_kelvin = 0.0;
}

void Temperature::set_temp_kelvin(double kel_t_point)
{
    degrees_kelvin = kel_t_point;
}

double Temperature::get_temp_kelvin() const
{
    return degrees_kelvin;
}

void Temperature::set_temp_fahrenheit(double fahr_t_point)
{
    degrees_kelvin = 5.0/9 * (fahr_t_point - 32) + CEL_TO_KEL;
}

double Temperature::get_temp_fahrenheit() const
{
    return 9.0/5 * (degrees_kelvin - CEL_TO_KEL) + 32;
}

void Temperature::set_temp_celsius(double cel_t_point)
{
    degrees_kelvin = cel_t_point + CEL_TO_KEL;
}

double Temperature::get_temp_celsius() const
{
    return degrees_kelvin - CEL_TO_KEL;
}

void clear_keyboard_buffer();
void validate_input(double&);
void get_user_input(double&);
void output(const Temperature&);

int main(void)
{
    Temperature today;
    double t_point = 0.0;
    char option;

    cout << "Enter a temperature scale (A) Kelvin, (B) Celsius, or  (C) Fahrenheit.\n"
            << "Your options are A, B, or C > ";
    cin.get(option);

    while (tolower(option) != 'a' && tolower(option) != 'b' && tolower(option) != 'c') {
        clear_keyboard_buffer();
        cout << "Invalid option. Try again (A) (B) or (C) > ";
        cin.get(option);
    }
    clear_keyboard_buffer();

    switch (option)
    {
        case 'a': 
        case 'A':
            cout << "Enter temperature point in the Kelvin scale > ";
            get_user_input(t_point);
            today.set_temp_kelvin(t_point);
            break;
        case 'b':
        case 'B':
            cout << "Enter temperature point in the Celsius scale > ";
            get_user_input(t_point);
            today.set_temp_celsius(t_point);
            break;
        case 'c':
        case 'C':
            cout << "Enter temperature point in the Fahrenheit scale > ";
            get_user_input(t_point);
            today.set_temp_fahrenheit(t_point);
            break;
        default:
            cout << "Could not set temp attribute.\n";
    }

    cout << fixed << showpoint << setprecision(2);

    if (option == 'A') {
        output(today);
    }
    else if (option == 'B') {
        output(today);
    }
    else {
        output(today);
    }

    return 0;
}

void clear_keyboard_buffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void validate_input(double& val)
{
    while (cin.fail()) {
        clear_keyboard_buffer();
        cout << "Unrecognized input. Try again\n";
        cout << "Enter a temperature point in degrees Kelvin, Celsius, or Fahrenheit > ";
        cin >> val;
    }
    clear_keyboard_buffer();
}

void get_user_input(double& t_point)
{
    cin >> t_point;
    validate_input(t_point);
}

void output(const Temperature& obj)
{
    cout << obj.get_temp_kelvin() << " degrees Kelvin is "
        << obj.get_temp_celsius() << " degrees Celsius and "
        << obj.get_temp_fahrenheit() << " degrees Fahrenheit.\n";
}