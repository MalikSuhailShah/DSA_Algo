#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

int main (){
    string str;
    cout<<"Enter the string:"<<endl;
    cin>>str;

    stack<char> st;
    st.push(str[0]);

    for(int i=1;i<str.length();i++){
        if(st.top()!=str[i])  st.push(str[i]);
        
    }

    string s="";

    while(st.size()){
        s+=st.top();
        st.pop();
    }

    reverse(s.begin(),s.end());

    cout<<s;

}
