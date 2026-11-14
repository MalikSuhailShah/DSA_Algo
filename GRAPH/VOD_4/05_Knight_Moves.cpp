//leetcode 1197 
/*Problem Statement
In an infinite chessboard with coordinates ranging from negative infinity to positive infinity, you have a knight at square (0, 0).

A knight has 8 possible moves. Each move consists of moving two squares in one direction and one square perpendicular to that direction

Return the minimum number of steps needed to move the knight to the square (x, y).

It is guaranteed that there is a unique answer.
*/

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