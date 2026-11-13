#include <iostream>
#include <string>
#include <stack>
using namespace std;

int prio(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    else
        return 1;
}

int solve(int val1,int val2,char opr){
    if(opr=='+') return val1+val2;
    else if(opr=='-') return  val1-val2;
    else if(opr=='*') return val1*val2;
    else return val1/val2;
}

int main()
{

    string str = "2+4*6/8-3";

    stack<int> val;
    stack<char> op;

    for (int i = 0; i < str.length() ; i++)
    {

        if (str[i] >= 48 && str[i] <= 57)
        { // str[i] is 0-9
            val.push(str[i] - 48);
        }
        else
        {
            if (op.size() == 0 || prio(op.top()) < prio(str[i]))
                op.push(str[i]);
            else
            {//prio(op.top()) >= prio(str[i])
                while(op.size() && prio(op.top())>=prio(str[i])){
                    char opr=op.top();
                op.pop();
                int val2=val.top();
                val.pop();
                int val1=val.top();
                val.pop();

                int ans = solve(val1,val2,opr);
                val.push(ans);
                }

                op.push(str[i]);
            }
               
        }
    }

    //ifor operator stack still not empty
    while(op.size()>0){
         char opr=op.top();
                op.pop();
                int val2=val.top();
                val.pop();
                int val1=val.top();
                val.pop();

                int ans = solve(val1,val2,opr);
                val.push(ans);
        }

        cout<<"the final answer is :"<<val.top();
}