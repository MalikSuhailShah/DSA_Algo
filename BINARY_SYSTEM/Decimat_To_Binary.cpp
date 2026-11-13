#include <iostream>
#include <string>
using namespace std;

string Decimal_To_Binary(int num)
{
    string result = "";

    while (num > 0)
    {
        if (num % 2 == 0)
            result += '0';
        else
            result += '1';

        num = num >> 1; // this calculation is preformed internally in cpu
    }

    return result;
}

int main()
{

    cout << Decimal_To_Binary(8) << endl;
}