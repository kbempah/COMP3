#include <iostream>
using namespace std;

class SuperInt
{
    public:
    explicit SuperInt(int val);
    
    private:
    int storedVal;
};

SuperInt::SuperInt(int val)
{
    storedVal = val;
}

int main(void)
{
    SuperInt x {5};
    int y = 5;

    return 0;
}