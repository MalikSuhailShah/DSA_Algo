#include<iostream>
#include<string>
using namespace std;

//Substring is created which increases the space complexity
void skipChar(string ans,string original){

    if(original.length()==0) {
        cout<<ans<<endl;
        return;

    }

    char ch=original[0];
    if(ch=='a') skipChar(ans,original.substr(1));
    else skipChar(ans+ch,original.substr(1));
}

//modification on same string

void skipChar2(string ans,string original , int idx){
    if(idx==original.length()){
        cout<<ans<<endl;
        return;
    }

    char ch=original[idx];
    if(ch=='a') skipChar2(ans,original,idx+1);
    else skipChar2(ans+ch,original,idx+1);
 }
int main ()
{
    string s;
    cout<<"enter the string:"<<endl;
    getline(cin,s);

    string str="";

    skipChar2(str,s,0);



}