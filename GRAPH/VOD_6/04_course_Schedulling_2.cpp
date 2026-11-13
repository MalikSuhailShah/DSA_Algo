//leetcode 210 : https://leetcode.com/problems/course-schedule-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> graph;

    void add_Edge(int src, int des){
        graph[src].push_back(des);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

         vector<int> indeg(numCourses, 0);
        int sz = prerequisites.size();

        graph.resize(numCourses, vector<int> ());

        for (int i = 0; i < sz; i++) {
            int c1 = prerequisites[i][0]; // 
            int c2 = prerequisites[i][1]; // [c1,c2] b should be completed first
            add_Edge(c2,c1);       // => c1 depends upon c2
            indeg[c1]++;
        }

        queue<int> qu;

        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                qu.push(i);
            }
        }

        unordered_set<int> visited;
        

        vector<int> ans;
        int count=0;
        
        while(qu.size()){
            int node = qu.front();
            qu.pop();

            ans.push_back(node);
           count++;

            if(not visited.count(node)) visited.insert(node);
            for(int ele : graph[node]){
                indeg[ele]--;

                if(not visited.count(ele) && indeg[ele]==0){
                    qu.push(ele);
                    visited.insert(ele);
                }
            }
        }

        return (count==numCourses)?ans:vector<int> ();
        
    }
};

int main (){

}