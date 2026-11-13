//leetcode 286 : https://takeuforward.org/practice/dsa/walls-and-gates

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:

    vector<pair<int,int>> d = {{1,0},{-1,0},{0,1},{0,-1}};

    void wallsAndGates(vector<vector<int>>& rooms) {
        // Your code goes here

        int rows = rooms.size();
        int cols = rooms[0].size();

        queue<pair<int,int>> qu;
         set<pair<int,int>> visited;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(rooms[i][j]==0){
                     qu.push({i,j});
                     visited.insert({i,j});
                     }
            }
        }

        qu.push({-2,-2});

       
        int dis = 1;
        while(qu.size()){
            auto curr = qu.front();
            qu.pop();

            int r = curr.first, c = curr.second;

            if(r==-2 && c==-2){
                dis++;
                if(qu.size()) qu.push({-2,-2});
                continue;
            }

            for(int i=0;i<d.size();i++){
                int nr = r + d[i].first;
                int nc = c + d[i].second;

                if(nr<0 || nc<0 || nr>=rows || nc>=cols) continue;
                if(rooms[nr][nc]!=2147483647 || visited.count({nr,nc})) continue;

                if(rooms[nr][nc]==2147483647 ) {
                   visited.insert({nr,nc});
                        rooms[nr][nc]=dis;
                         qu.push({nr,nc});
                }
               

            }
        }
    }
};
int main (){

}