// Leet code -253 for subcribed user

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int NoOfRooms(vector<vector<int>> & v){
  vector<int> start, ending;

  for(int i=0;i<v.size();i++){
    start.push_back(v[i][0]);
    ending.push_back(v[i][1]);
  }

  sort(start.begin(), start.end());
  sort(ending.begin(),ending.end());

  int ans=0;
  int room=0;
  int i=0,j=0;

  while(i<start.size() && j<ending.size()){
    if(start[i]<ending[j]){
        //new meeting starting 
        room++;
        ans=max(ans,room);
        i++;
    }
    else if(start[i]>ending[j]){
        // a meeting is ending room will get freed
        room--;
        j++;
    }
    else{
        //at same time one meeting end and anathor starts in such case room gets filled as soon it became vacant
        i++;
        j++;
    }
  }

  return ans;
}

int main (){

}