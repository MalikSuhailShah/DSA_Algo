// leetcode 200

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int cc = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (grid[r][c] == '0') {
                    continue; // water body or already explored cell
                }
                 cc += 1;
                queue<pair<int,int>> qu;
                qu.push({ r,c});
                grid[r][c] = '0';

                while (!qu.empty()) {
                    auto curr = qu.front();
                    qu.pop();

                    int currRow = curr.first;
                    int currCol = curr.second;

                    // checking for up

                    if (currRow - 1 >= 0 && grid[currRow - 1][currCol]=='1') {
                        qu.push({currRow - 1, currCol});
                        grid[currRow - 1][currCol] = '0';
                    }

                    // checking for down

                    if (currRow + 1 < rows && grid[currRow + 1][currCol]=='1') {
                        qu.push({currRow + 1, currCol});
                        grid[currRow + 1][currCol] = '0';
                    }

                    // checking for right

                    if (currCol + 1 < cols && grid[currRow][currCol + 1]=='1') {
                        qu.push({currRow, currCol + 1});
                        grid[currRow][currCol + 1] = '0';
                    }

                    // checking for up

                    if (currCol - 1 >= 0 && grid[currRow][currCol - 1]=='1') {
                        qu.push({currRow, currCol - 1});
                        grid[currRow][currCol - 1] = '0';
                    }
                }
            }
        }

        return cc;
    }
};

int main (){
    
}