#include <iostream>
#include <string>
using namespace std;

void BinaryString(string s, int n)
{

    if (s.length() == n)
    {
        cout << s << endl;
        return;
    }

    
   
    if (s==""){
        BinaryString(s + "0", n);
        BinaryString(s+"1",n);
    }

    else if(s[s.length()-1]=='0'){
        BinaryString(s+'1',n);
    }
}
int main()
{
    int n;
    cout << "Enter the length of the string:";
    cin >> n;

    BinaryString(" ", n);
}