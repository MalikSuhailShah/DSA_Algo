// can a person attend all the meetings

//LeetCode-252

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool CanAttendAll(vector<vector<int>> & v){
    //if only one room is required then person will be able to attend all the meetings

    if(v.size()==0) return true;
    
    vector<int> start, ending;

    for(auto ele : v){
        start.push_back(ele[0]);
        ending.push_back(ele[1]);
    }

    sort(start.begin(),start.end());
    sort(ending.begin(),ending.end());

    int i=0,j=0;
    int room=0, ans=0;

    while(i<start.size() && j<ending.size()){
        if(start[i]<ending[j]){
            room++;
            ans=max(ans,room);
            i++;
        }
        else if(start[i]>ending[j]){
            j++;
            room--;
        }
        else{
            i++;
            j++;
        }
    }

    return ans==1;


}

int main (){

}