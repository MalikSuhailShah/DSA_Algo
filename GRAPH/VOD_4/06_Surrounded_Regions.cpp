// leetcode 130 : https://leetcode.com/problems/surrounded-regions/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<pair<int, int>> d = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void solve(vector<vector<char>>& board) {

        int rows = board.size();
        int cols = board[0].size();

        queue<pair<int,int>> qu;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
               if(i==0 || j==0 || i==rows-1 || j==cols-1){
                if(board[i][j]=='O') qu.push({i,j});
               }
            }
        }

        set<pair<int,int>> visited;

        while(qu.size()){
            auto curr = qu.front();
            qu.pop();

            int r = curr.first, c = curr.second;
            if(not visited.count({r,c})) visited.insert({r,c});

            board[r][c]='Y';
            for(int i=0;i<d.size();i++){
                int nr = r + d[i].first;
                int nc = c + d[i].second;

                if(nr<0 || nc<0 || nr>=rows || nc>=cols) continue;

                if(board[nr][nc]=='O' && not visited.count({nr,nc})){
                    qu.push({nr,nc});
                    visited.insert({nr,nc});
                }
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='Y') board[i][j]='O';
            }
        }
    }
};

int main (){

}