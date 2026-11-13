#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string str;
    cout << "Enter the string:" << endl;
    cin >> str;
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {

        if (str.length() % 2 != 0)
            break;

        if (str[i] == '(')
            st.push(str[i]);
        else
        {
            if (st.size() == 0)
                break;
            else
                st.pop();
        }
    }

    if (st.size() != 0)
        cout << "Unbalanced string" << endl;
    else
        cout << "Balanced string" << endl;
}