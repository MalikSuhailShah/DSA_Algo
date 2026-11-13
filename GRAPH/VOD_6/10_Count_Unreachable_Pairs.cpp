// leetcode 2316 : https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/


#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> graph;

    void add_Edge(int src, int des, bool bi_dir = true) {
        graph[src].push_back(des);
        if (bi_dir)
            graph[des].push_back(src);
    }

    int BFS(int src, vector<bool>& visited) {
        queue<int> qu;
        qu.push(src);

        visited[src] = true;
        int count = 1;
        while (qu.size()) {
            int node = qu.front();
            qu.pop();

            for (int neighbour : graph[node]) {
                if (visited[neighbour] == false) {
                    qu.push(neighbour);
                    visited[neighbour] = true;
                    count++;
                }
            }
        }

        return count;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        graph.resize(n, vector<int>());

        for (auto ele : edges) {
            int src = ele[0];
            int des = ele[1];

            add_Edge(src, des, true);
        }

        vector<int> c;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                int count = BFS(i, visited);
                c.push_back(count);
            }
        }

        long long ans = 0;
        long long rem = (long long)n;
        for (int i = 0; i < c.size(); i++) {
            rem = rem - (long long)c[i];

            ans += rem *(long long) c[i];
        }

        return ans;
    }
};

int main (){
    
}