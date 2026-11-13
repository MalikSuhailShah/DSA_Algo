// Leet Code - 781 Rabbits in Forest => https://leetcode.com/problems/rabbits-in-forest/description/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;

        int ans=0;
        for(int i=0;i<answers.size();i++){
            if(!mp[answers[i]+1]){
                ans+=answers[i]+1;// we started with a new colour group
                if(answers[i]==0) continue;
                mp[answers[i]+1]=1;
            }
            else{
                    mp[answers[i]+1]++;
                    int key=answers[i]+1;
                    if(mp[key]==key){ 
                        //we have found all the rabbits of the same group
                        // elliminate the group
                        mp.erase(key);}
            }
        }

        return ans;
    }
};

int main (){

}