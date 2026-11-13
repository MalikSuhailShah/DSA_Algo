#include <iostream>

using namespace std;

int Set_Bits(int n){
    int count=0;
    while(n>0){
        count++;

        n=(n&(n-1));
    }

    return count;
}

int main()
{
    cout<<Set_Bits(13);
}