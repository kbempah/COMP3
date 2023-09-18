#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>

using namespace std;

void get_user_input(string& op, double& var1, double& var2);
double add(double, double);
double sub(double, double);
double mul(double, double);
double div(double, double);
bool is_valid_operation(string op);
void clear_keyboard_buffer(void);

int main(void)
{
    string operation;
    double left = 0.0, right = 0.0;
    bool good = false;

    get_user_input(operation, left, right);

    while (operation != "quit") {
        if (operation == "+") {
            cout << add(left, right) << endl;
        }
        else if (operation == "-") {
            cout << sub(left, right) << endl;
        }
        else if (operation == "*") {
            cout << mul(left, right) << endl;
        }
        else if (operation == "/") {
            cout << div(left, right) << endl;
        }

        get_user_input(operation, left, right);
    }

    return 0;
}

void get_user_input(string& op, double& var1, double& var2)
{
    cout << "Enter expression in the form: operation operand1 operand2 or \"quit\" to quit > \n";
    cin >> op;
    if (cin.fail()) {
        clear_keyboard_buffer();
        cout << "Could not determing input.\n";
        return;
    }
    if (!is_valid_operation(op) && op != "quit") {
        clear_keyboard_buffer();
        cout << "Could not determine operation.\n";
        return;
    }
    if (op == "quit") {
        clear_keyboard_buffer();
        return;
    }
    cin >> var1; cin.ignore();
    cin >> var2; cin.ignore();

    return;
}

bool is_valid_operation(string op)
{
    if (op == "+" || op == "-" || op == "*" || op == "/")
        return true;

    return false;
}

void clear_keyboard_buffer(void)
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double add(double arg1, double arg2)
{
    return arg1 + arg2;
}

double sub(double arg1, double arg2)
{
    return arg1 - arg2;
}

double mul(double arg1, double arg2)
{
    return arg1 * arg2;
}

double div(double arg1, double arg2)
{
    if (!arg2) {
        return 0xFFFF;
    }
    else {
        return arg1 / arg2;
    }
}