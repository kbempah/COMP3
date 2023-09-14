#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>

using namespace std;

void get_user_input(string& op, double& var1, double& var2);
bool is_valid_operation(string op);
void clear_keyboard_buffer();

int main(void)
{
    string operation;
    double left, right;

    get_user_input(operation, left, right);

    cout << operation << 
    left << right << endl;
    return 0;
}

void get_user_input(string& op, double& var1, double& var2)
{
    cout << "enter expression in the form: operation operand1 operand2 > ";
    cin >> op; cin.ignore();

    if (op == "quit")
    {
        exit(EXIT_SUCCESS);
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

void clear_keyboard_buffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}