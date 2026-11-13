//leetcode 1197 

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<pair<int,int>> d = {{2,1},{2,-1},{-2,1},{-2,-1}, {1,2},{1,-2},{-1,2},{-1,-2}};
    int minKnightMoves(int x, int y) {
        //Your Code Goes Here

        int steps = 0;
        queue<pair<int,int>> qu;

        qu.push({0,0});
        qu.push({-1000,-1000});

        set<pair<int,int>> visited;
        visited.insert({0,0});

        while( qu.size() ){
            auto curr = qu.front();
            qu.pop();

            int r = curr.first;
            int c = curr.second;

            if(r==-1000 && c==-1000){
                steps++;
                if(qu.size()){
                    qu.push({-1000,-1000});
                }
                continue;
            }

            if(x==r && y==c) return steps;
            
            for(int i=0;i<d.size();i++){
                int nr = r +d[i].first;
                int nc = c + d[i].second;

                if(visited.count({nr,nc})) continue;

                qu.push({nr,nc});
                visited.insert({nr,nc});
               
            }
        }

        return steps;
    }
};

int main (){

}