#include <iostream>

using namespace std;

class Date 
{
    public:
        Date();
        Date(int month, int day, int year)
        {
            Date::month = month;
            Date::day = day;
            Date::year = year;
        }

    private:
        int day;
        int month;
        int year;
};

int main()
{
    Date today{9,11,2023};
    return 0;
}