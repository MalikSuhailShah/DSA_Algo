#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void duplicateSubset(string ans, string original, int idx, vector<string> &v, bool flag)
{
    if(idx==original.length()){
        v.push_back(ans);
        return;
    }

   
    char ch=original[idx];
    if(original.length()==1){
       if(flag==true) duplicateSubset(ans+ch,original,idx+1,v,true);
       duplicateSubset(ans,original,idx+1,v,true);
       return;
    }
    
    char dh='0';
    if(idx+1<original.length()){
        dh=original[idx+1];
    }
   
    if(ch==dh){
        if(flag==true) duplicateSubset(ans+ch,original,idx+1,v,true);

        duplicateSubset(ans,original,idx+1,v,false);
    }
    else{
        if(flag==true) duplicateSubset(ans+ch,original,idx+1,v,true);

        duplicateSubset(ans,original,idx+1,v,true);
    }

}

int main()
{
    string str="aab";
    vector<string> v;
     sort(str.begin(),str.end());//in order to make all duplicates together


    duplicateSubset("",str,0,v,true);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}