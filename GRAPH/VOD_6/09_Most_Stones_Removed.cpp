// leetcode 947 : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/


#include<iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    void BFS(int start, vector<bool>& visited, vector<vector<int>>& stones) {
        queue<int> qu;
        qu.push(start);
        visited[start] = true;

        while (!qu.empty()) {
            int curr = qu.front();
            qu.pop();

            for (int i = 0; i < stones.size(); i++) {
                if (visited[i])
                    continue;

                // Same row or same column
                int r1 = stones[curr][0];
                int c1 = stones[curr][1];
                int r2 = stones[i][0];
                int c2 = stones[i][1];

                if (r1 == r2 || c1 == c2) {
                    visited[i] = true;
                    qu.push(i);
                }
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                BFS(i, visited, stones);
            }
        }

        return n - components;
    }
};
int main (){
    
}