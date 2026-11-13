#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

void permutations(string input, string output){
    if(input.length()==0){
        cout<<output<<"\n";
        return;
    }

    for(int i=0;i<input.length();i++)
    {
        char ch = input[i];
        
        string left = input.substr(0,i);
        string right = input.substr(i+1);

        string rem = left + right;

        permutations(rem, output + ch);
    }
}


void BacktrackSoln(string &input, int i){ 
    if(i + 1 == input.length()){
        cout<<input<<"\n";
        return;
    }
    unordered_set<char> s;// used to handle repeated recurive calls
    for(int idx =i; idx < input.length();idx++){
        if(s.count(input[idx])) continue;

        s.insert(input[idx]);
        swap(input[i], input[idx]);
        BacktrackSoln(input,i+1);
        swap(input[i],input[idx]);
    }

}
int main (){
    string str = "aba";

    BacktrackSoln(str,0);
}